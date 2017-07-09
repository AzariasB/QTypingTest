/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */

/*
 * File:   vector2f.h
 * Author: boutina
 *
 * Created on 15 mars 2017, 19:00
 */

#include "bouncegame.h"
#include <QList>

const QString BounceGame::alphabet = "abcdefghijklmnopqrstuvwxyz,./?;";
const int BounceGame::startingLives = 5;

BounceGame::BounceGame(BounceData *dataHolder, QWidget *parent):
	QGraphicsView(parent),
	bullet_(new Bullet()),
	dataHolder_(dataHolder),
	countdown_(new Countdown)
{
	loadResources();
	initWalls();
	timer_.setInterval(15);
	timer_.setSingleShot(false);

	connect(countdown_, &Countdown::timeout, this, &BounceGame::play);
	connect(dataHolder_, &BounceData::playPause, this, &BounceGame::togglePause);
	connect(dataHolder, &BounceData::exit, this, &BounceGame::gameEnded);
	connect(&timer_, &QTimer::timeout, [=](){
		this->tick(15);
	});

	dataHolder_->reset(startingLives);

	setScene(&scene_);
	init();
	qDebug() << "Test";
}

void BounceGame::togglePause()
{
	if(state_ == GameSate::Pause){
		stateChanges(GameSate::Countdown);
	}else if(state_ == GameSate::Play){
		stateChanges(GameSate::Pause);
	}
	setFocus();
}

void BounceGame::loadResources()
{
	int pixmapNumber = 3;
	for(int i = 0; i < pixmapNumber;i++){
		rm_.loadPixmap(QString("sparkles-%1").arg(i), QString(":/game/sparkles-%1.png").arg(i));
	}
	rm_.loadPixmap("puff",":/game/puff.png");
}

void BounceGame::initWalls()
{
	walls_[LEFT] = createWall(WALL_NUMBER, QPoint(0,WALL_SIZE), QPoint(0,WALL_SIZE), LEFT );
	walls_[RIGHT] = createWall(WALL_NUMBER, QPoint((WALL_NUMBER+1)*WALL_SIZE  ,WALL_SIZE), QPoint(0,WALL_SIZE), RIGHT);
	walls_[UP] = createWall(WALL_NUMBER, QPoint(WALL_SIZE,0), QPoint(WALL_SIZE,0), UP);
	walls_[DOWN] = createWall(WALL_NUMBER, QPoint(WALL_SIZE,  (WALL_NUMBER+1)*WALL_SIZE ), QPoint(WALL_SIZE, 0), DOWN);
}

void BounceGame::looseLife()
{
	spawnPuff(bullet_->pos());
	bullet_->reset();
	if(!dataHolder_->decrementLives()){
		//Loosing
		stateChanges(GameSate::Lost);
	}else{
		timer_.stop();
		bullet_->setX(scene_.width() / 2.f);
		bullet_->setY(scene_.height()/ 2.f );
		nextTarget();
		stateChanges(GameSate::Countdown);
	}
}

void BounceGame::tick(int dt)
{
	if(state_ == GameSate::Lost || state_ == GameSate::Pause || state_ == GameSate::Countdown)
		return;

	bullet_->tick(dt);

	QList<QGraphicsItem*> colliders = scene_.collidingItems(bullet_);

	for(QGraphicsItem *itemCollider : colliders){

		LetterWall *collider;
		if(!(collider = dynamic_cast<LetterWall*>(itemCollider)))
			continue;

		if(currentTarget_->getChar() != currentPressed_){
			looseLife();
			return;
		}
		spawnSparkles( bullet_->pos() );
		dataHolder_->incrementScore();

		LetterWall *nwTarget = nullptr;
		for(int d = UP; d != NO_DIRECTION; d++){
			if(walls_[static_cast<DIRECTION>(d)].contains(collider)){
				int nextDirI = (d - 1) % NO_DIRECTION;
				if(nextDirI < 0)
					nextDirI = NO_DIRECTION - 1;

				DIRECTION opposite = static_cast<DIRECTION>((d+2) % NO_DIRECTION);

				nwTarget = randomTarget(static_cast<DIRECTION>(nextDirI));
				uncollideBullet(collider, opposite);
			}
		}

		if(nwTarget){
			if(currentTarget_)
				currentTarget_->resetState();
			bullet_->slowDown();
			nextTarget(nwTarget);
		}
	}
}

void BounceGame::spawnSparkles(const QPointF &position)
{
//	QSound::play(":/game/sfx/c.wav"); => find a good sound
	AnimatedSprite *anim = new AnimatedSprite(randomSparkle(), 7, true);
	anim->setPos(position);
	scene_.addItem(anim);
}

void BounceGame::spawnPuff(const QPointF &position)
{
	const QPixmap &puff = rm_.getPixmap("puff");
	//if !mute => play ":/"
	AnimatedSprite *anim = new AnimatedSprite(puff,5, true);
	anim->setPos(QPointF(position.x() - 32, position.y() - puff.height()/ 2));
	scene_.addItem(anim);
}

void BounceGame::uncollideBullet(LetterWall *collider, DIRECTION targetDir)
{
	// up || down => change y
	// left || right => change x
	if(targetDir == DOWN){
		qreal minY = collider->y() + collider->boundingRect().height();
		bullet_->setY(minY  + .1f);
	}else if(targetDir == UP){
		qreal maxY = collider->y();
		bullet_->setY(maxY - .1f - bullet_->boundingRect().height());
	}else if(targetDir == LEFT){
		qreal maxX = collider->x();
		bullet_->setX(maxX - .1f - bullet_->boundingRect().width());
	}else if(targetDir == RIGHT){
		qreal minX = collider->x() + collider->boundingRect().width();
		bullet_->setX(minX + .1f);
	}
}

void BounceGame::play()
{
	countdown_->setVisible(false);
	timer_.start();
	dataHolder_->play();
	scene_.addItem(bullet_);

	bullet_->setX(scene_.width() / 2.f);
	bullet_->setY(scene_.height()/ 2.f );

	nextTarget();
	setFocus();
	stateChanges(GameSate::Play);
}

void BounceGame::init()
{

	this->update();
	//Prevent scene from resizing
	scene_.addWidget(countdown_);
	scene_.setSceneRect(scene_.sceneRect());
}

void BounceGame::nextTarget(LetterWall *nwTarget)
{
	if(nwTarget == 0)
		nwTarget = randomTarget();

	if(currentTarget_ != 0)
		currentTarget_->resetState();

	if(!currentPressed_.isNull() && equivalents_.contains(currentPressed_)){
		for(LetterWall *wall : equivalents_[currentPressed_]){
			wall->resetState();
		}
	}

	currentPressed_ = '\0';
	currentTarget_ = nwTarget;
	nwTarget->setSelectedState();
	bullet_->setTarget(nwTarget);
}

void BounceGame::restart()
{
	scene_.clear();//Clears all the items
	equivalents_ = QHash<QChar, QVector<LetterWall*>>();

	initWalls();
	bullet_ = new Bullet;

	currentPressed_ = '\0';
	state_ = GameSate::Countdown;
	dataHolder_->reset(startingLives);
	currentTarget_ = 0;

	countdown_ = new Countdown;
	connect(countdown_, &Countdown::timeout, this, &BounceGame::play);
	scene_.addWidget(countdown_);
	countdown_->move(scene_.sceneRect().width() / 2.f - countdown_->width(), scene_.sceneRect().height() / 2.f - countdown_->height());
	countdown_->start();
}


void BounceGame::keyPressEvent(QKeyEvent *event)
{
	if(event->isAutoRepeat())
	        return;

	if(event->key() == Qt::Key_Escape)
	{
		if(state_ == GameSate::Pause){
			emit gameEnded(-1, QTime());
		}else if(state_ == GameSate::Lost){
			emit gameEnded(dataHolder_->getScore(), dataHolder_->time());
		}else if(state_ == GameSate::Play){
			stateChanges(GameSate::Pause);
		}
	}else if(state_ == GameSate::Pause){
		stateChanges(GameSate::Countdown);
	}

	if(state_ == GameSate::Lost){
		if(event->key() == Qt::Key_Return)
		        restart();
	}else{
		if(!currentPressed_.isNull()){
			for(LetterWall *wall : equivalents_[currentPressed_]){
				wall == currentTarget_ ? wall->setSelectedState() : wall->resetState();
			}
		}

		if(currentTarget_ != 0 && !event->text().isEmpty()){
			currentPressed_ = event->text()[0].toLower();
			if(equivalents_.contains(currentPressed_)){
				bool correct = currentPressed_ == currentTarget_->getChar();
				for(LetterWall *wall : equivalents_[currentPressed_]){
					correct ? wall->setCorrectState() : wall->setWrongState();
				}
				if(correct)
					bullet_->boost();
			}
		}
	}
}

void BounceGame::keyReleaseEvent(QKeyEvent *event)
{
	if(event->isAutoRepeat())
		return;

	if(!event->text().isEmpty()){
		if(equivalents_.contains(currentPressed_)){
			bullet_->slowDown();
		}
	}
}

QVector<LetterWall *> BounceGame::createWall(int numberOfWalls, QPoint start, QPoint increment, DIRECTION wallSide)
{
	QVector<LetterWall*> res;
	for(int i = 0; i < numberOfWalls;i++){
		int xPos = start.x() + i*increment.x();
		int yPos = start.y() + i*increment.y();
		QChar letter = randomLetter();
		LetterWall *lWall = new LetterWall(letter, WALL_SIZE, wallSide);
		equivalents_[letter].append(lWall);
		lWall->setPos(xPos, yPos);
		scene_.addItem(lWall);
		res << lWall;
	}
	return res;
}

void BounceGame::resizeEvent(QResizeEvent *event)
{
	event->setAccepted(false);
	event->ignore();
	fitInView(scene_.sceneRect(), Qt::AspectRatioMode::KeepAspectRatio);
}

LetterWall *BounceGame::randomTarget(DIRECTION nwDirection)
{
	if(nwDirection == NO_DIRECTION)
		nwDirection = static_cast<DIRECTION>(qrand() % NO_DIRECTION);

	if(walls_.contains(nwDirection)){
		QVector<LetterWall*> mWall = walls_[nwDirection];
		return mWall[qrand() % mWall.length()];
	}
	return nullptr;
}

QChar BounceGame::randomLetter()
{
	return alphabet[qrand()%alphabet.size()];
}

RectText *BounceGame::createMessageBox(QString msg)
{
	qreal topLeftX = scene()->sceneRect().width()/4.f;
	qreal topLeftY = scene()->sceneRect().height()/3.f;

	qreal bottomRightX = topLeftX * 3.f;
	qreal bottomRighttY = topLeftY * 2.f;

	QPointF topLeft(topLeftX, topLeftY);
	QPointF bottomRight(bottomRightX, bottomRighttY);

	QRectF messageBounds(topLeft, bottomRight);

        return new RectText(messageBounds, msg, 0 , QColor(135, 211, 124), QColor()/* black border */);
}

const QPixmap &BounceGame::randomSparkle()
{
	int numberOfSparkles = 3;
	return rm_.getPixmap(QString("sparkles-%1").arg(qrand()%numberOfSparkles));
}

void BounceGame::stateChanges(GameSate nwState)
{
	switch(nwState){
		case GameSate::Lost:
				dataHolder_->stop();
				scene_.addItem(createMessageBox(QString("You lost\n Score : %1\n - Enter to restart - \n - Escape : return to menu - ").arg(dataHolder_->getScore())));
	            break;
		case GameSate::Pause:
				//TODO : Add (maybe) a recttext indicating the game is paused
				scene_.addItem(createMessageBox(QString("Gamed paused\n - Espace : return to menu -\n - Any key : continue -")));
				dataHolder_->pause();
	            break;
		case GameSate::Play:
			timer_.start();
			dataHolder_->play();
			break;
		case GameSate::Countdown:
			QList<QGraphicsItem*> items = scene_.items();
			foreach(QGraphicsItem *it, items){
				if(RectText* rt = dynamic_cast<RectText*>(it) ){
					scene_.removeItem(rt);
				}
			}
			countdown_->reset();
			countdown_->setVisible(true);
			countdown_->start();
			disconnect(countdown_, &Countdown::timeout, this, &BounceGame::play);
			connect(countdown_, &Countdown::timeout, [=](){
				countdown_->setVisible(false);
				stateChanges(GameSate::Play);
			});
			break;
	}
	state_ = nwState;
}

BounceGame::~BounceGame()
{
	//Destroys all the scene's items
}

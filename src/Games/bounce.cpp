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

#include "bounce.h"

const QString Bounce::alphabet = "abcdefghijklmnopqrstuvwxyz";

Bounce::Bounce(QWidget *parent):
	QGraphicsView(parent),
	bullet_(new Bullet()),
	leftWall_(createWall(WALL_NUMBER, QPoint(0,WALL_SIZE), QPoint(0,WALL_SIZE), LEFT )),
	rightWall_(createWall(WALL_NUMBER, QPoint((WALL_NUMBER+1)*WALL_SIZE  ,WALL_SIZE), QPoint(0,WALL_SIZE), RIGHT)),
	upperWall_(createWall(WALL_NUMBER, QPoint(WALL_SIZE,0), QPoint(WALL_SIZE,0), UP)),
	lowerWall_( createWall(WALL_NUMBER, QPoint(WALL_SIZE,  (WALL_NUMBER+1)*WALL_SIZE ), QPoint(WALL_SIZE, 0), DOWN))
{
	timer_.setInterval(15);
	timer_.setSingleShot(false);
	connect(&timer_, &QTimer::timeout, [=](){
		this->tick(15);
	});
	setScene(&scene_);
	init();
}

void Bounce::looseGame()
{
	qDebug() << score_;
	lost_ = true;
	scene_.addItem(getEndMessage());
}

void Bounce::tick(int dt)
{
	if(lost_)
		return;

	bullet_->tick(dt);

	QList<QGraphicsItem*> colliders = scene_.collidingItems(bullet_);
	if(colliders.length() > 0){
		LetterWall *collider = static_cast<LetterWall*>(colliders[0]);

		if(currentTarget_->getChar() != currentPressed_){
			looseGame();
			return;
		}
		score_++;

		LetterWall *nwTarget = nullptr;
		if(leftWall_.contains(collider)){
			nwTarget = randomTarget(DOWN);
			uncollideBullet(collider, RIGHT);
		}else if(rightWall_.contains(collider)){
			nwTarget =  randomTarget(UP);
			uncollideBullet(collider, LEFT);
		}else if(upperWall_.contains(collider)){
			nwTarget = randomTarget(LEFT);
			uncollideBullet(collider, DOWN);
		}else{
			nwTarget = randomTarget(RIGHT);
			uncollideBullet(collider, UP);
		}

		if(nwTarget){
			if(currentTarget_)
				currentTarget_->resetState();
			bullet_->slowDown();
			nextTarget(nwTarget);
		}
	}

}

void Bounce::uncollideBullet(LetterWall *collider, DIRECTION targetDir)
{
	// up || down => change y
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

void Bounce::init()
{
	addWallToScene(leftWall_);
	addWallToScene(rightWall_);
	addWallToScene(upperWall_);
	addWallToScene(lowerWall_);
	scene_.addItem(bullet_);
	this->update();
	bullet_->setX(scene_.width() / 2.f);
	bullet_->setY(scene_.height()/ 2.f );
	timer_.start();
	nextTarget();
}

void Bounce::addWallToScene(QVector<LetterWall*> &toAdd)
{
	for(LetterWall *letter : toAdd){
		scene_.addItem(letter);
	}
}

void Bounce::nextTarget(LetterWall *nwTarget)
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

void Bounce::restart()
{
	scene_.clear();//Clears all the items
	equivalents_ = QHash<QChar, QVector<LetterWall*>>();

	leftWall_ = createWall(WALL_NUMBER, QPoint(0,WALL_SIZE), QPoint(0,WALL_SIZE), LEFT );
	rightWall_ = createWall(WALL_NUMBER, QPoint((WALL_NUMBER+1)*WALL_SIZE  ,WALL_SIZE), QPoint(0,WALL_SIZE), RIGHT);
	upperWall_ = createWall(WALL_NUMBER, QPoint(WALL_SIZE,0), QPoint(WALL_SIZE,0), UP);
	lowerWall_ =  createWall(WALL_NUMBER, QPoint(WALL_SIZE,  (WALL_NUMBER+1)*WALL_SIZE ), QPoint(WALL_SIZE, 0), DOWN);
	bullet_ = new Bullet();

	currentPressed_ = '\0';
	lost_ = false;
	score_ = 0;
	currentTarget_ = 0;
	init();
}

void Bounce::keyPressEvent(QKeyEvent *event)
{
	if(event->isAutoRepeat())
		return;

	if(event->key() == Qt::Key_Escape)
	{
		close();
		emit gameEnded(-1);
	}




	if(lost_){
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

void Bounce::keyReleaseEvent(QKeyEvent *event)
{
	if(event->isAutoRepeat())
		return;

	if(!event->text().isEmpty()){
		if(equivalents_.contains(currentPressed_)){
			bullet_->slowDown();
		}
	}
}

QVector<LetterWall *> Bounce::createWall(int numberOfWalls, QPoint start, QPoint increment, DIRECTION wallSide)
{
	QVector<LetterWall*> res;
	for(int i = 0; i < numberOfWalls;i++){
		int xPos = start.x() + i*increment.x();
		int yPos = start.y() + i*increment.y();
		QChar letter = randomLetter();
		LetterWall *lWall = new LetterWall(letter, WALL_SIZE, wallSide);
		equivalents_[letter].append(lWall);
		lWall->setPos(xPos, yPos);
		//scene_.addItem(lWall);
		res << lWall;
	}
	return res;
}

void Bounce::resizeEvent(QResizeEvent *)
{
	fitInView(scene_.sceneRect(), Qt::AspectRatioMode::KeepAspectRatio);
}


LetterWall *Bounce::randomTarget(DIRECTION nwDirection)
{
	if(nwDirection == NO_DIRECTION)
		nwDirection = static_cast<DIRECTION>(qrand() % NO_DIRECTION);

	if(nwDirection == UP) return upperWall_[qrand() % upperWall_.length()];
	if(nwDirection == RIGHT) return rightWall_[qrand() % rightWall_.length()];
	if(nwDirection == DOWN) return lowerWall_[qrand() % lowerWall_.length()];
	if(nwDirection == LEFT) return leftWall_[qrand() % leftWall_.size()];
	return nullptr;
}

QChar Bounce::randomLetter()
{
	return alphabet[qrand()%alphabet.size()];
}

QGraphicsItem *Bounce::getEndMessage()
{
	qreal topLeftX = scene()->sceneRect().width()/4.f;
	qreal topLeftY = scene()->sceneRect().height()/3.f;

	qreal bottomRightX = topLeftX * 3.f;
	qreal bottomRighttY = topLeftY * 2.f;

	QPointF topLeft(topLeftX, topLeftY);
	QPointF bottomRight(bottomRightX, bottomRighttY);

	QRectF messageBounds(topLeft, bottomRight);

	QString message = QString("You lost\n Score : %1\n - Enter to restart - \n - Escape to close - ").arg(score_);

	return new EndMessage(messageBounds, message);
}

Bounce::~Bounce()
{

}

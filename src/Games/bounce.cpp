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

Bounce::Bounce(QWidget *parent):
	QGraphicsView(parent),
	leftWall_(createWall(WALL_NUMBER, QPoint(0,WALL_SIDE), QPoint(0,WALL_SIDE))),
	rightWall_(createWall(WALL_NUMBER, QPoint((WALL_NUMBER+1)*WALL_SIDE  ,WALL_SIDE), QPoint(0,WALL_SIDE))),
	upperWall_(createWall(WALL_NUMBER, QPoint(WALL_SIDE,0), QPoint(WALL_SIDE,0))),
	lowerWall_( createWall(WALL_NUMBER, QPoint(WALL_SIDE,  (WALL_NUMBER+1)*WALL_SIDE ), QPoint(WALL_SIDE, 0)))
{
	setScene(&scene_);
	init();
}

void Bounce::tick(int dt)
{
	bullet_.tick(dt);
	QList<QGraphicsItem*> colliders = scene_.collidingItems(&bullet_);
	if(colliders.length() > 0){
		LetterWall *collider = static_cast<LetterWall*>(colliders[0]);
		LetterWall *nwTarget = nullptr;
		if(leftWall_.contains(collider)){
			nwTarget = randomTarget(DOWN);
		}else if(rightWall_.contains(collider)){
			nwTarget =  randomTarget(UP);
		}else if(upperWall_.contains(collider)){
			nwTarget = randomTarget(LEFT);
		}else{
			nwTarget = randomTarget(RIGHT);
		}

		if(nwTarget){
			nwTarget->setSelectedState();
			nwTarget->update();
			bullet_.setTarget(nwTarget);
		}
	}

}

void Bounce::init()
{
	addWallToScene(leftWall_);
	addWallToScene(rightWall_);
	addWallToScene(upperWall_);
	addWallToScene(lowerWall_);
	scene_.addItem(&bullet_);
	this->update();
	bullet_.setX(scene_.width() / 2.f);
	bullet_.setY(scene_.height()/ 2.f );
	nextTarget();
}

void Bounce::addWallToScene(QVector<LetterWall*> &toAdd)
{
	for(LetterWall *letter : toAdd){
		scene_.addItem(letter);
	}
}

void Bounce::nextTarget(DIRECTION nwDirection)
{
	LetterWall *target = randomTarget(nwDirection);
	target->setSelectedState();
	bullet_.setTarget(target);
	target->update();
}

QVector<LetterWall *> Bounce::createWall(int numberOfWalls, QPoint start, QPoint increment)
{
	QVector<LetterWall*> res;
	for(int i = 0; i < numberOfWalls;i++){
		int xPos = start.x() + i*increment.x();
		int yPos = start.y() + i*increment.y();
		LetterWall *lWall = new LetterWall('a', WALL_SIDE);
		lWall->setPos(xPos, yPos);
		//scene_.addItem(lWall);
		res << lWall;
	}
	return res;
}

void Bounce::resizeEvent(QResizeEvent *event)
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

Bounce::~Bounce()
{

}

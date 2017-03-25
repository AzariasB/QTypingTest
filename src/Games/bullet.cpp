/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */

/*
 * File:   bullet.cpp
 * Author: boutina
 *
 * Created on 15 mars 2017, 19:00
 */

#include "bullet.h"

Bullet::Bullet(QGraphicsItem *parent):
	QGraphicsEllipseItem(0,0, BULLET_RADIUS, BULLET_RADIUS, parent),
	direction(1.f,1.f)
{

}

void Bullet::setTarget(QGraphicsItem *target)
{
	if(target){
		float xDist = target->x() - x();
		float yDist = target->y() - y();
		direction = Vector2f(xDist, yDist);
		direction.normalize();
	}else{
		direction = Vector2f::zero;
	}
}

void Bullet::tick(int dt)
{
	this->setX(this->x() + (dt/100.f) * direction.x() * speed);
	this->setY(this->y() + (dt/100.f) * direction.y() * speed);
}

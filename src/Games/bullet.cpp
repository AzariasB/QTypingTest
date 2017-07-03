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
#include <qmath.h>

Bullet::Bullet(QGraphicsItem *parent):
	QGraphicsEllipseItem(0,0, BULLET_RADIUS, BULLET_RADIUS, parent),
	direction(1.f,1.f)
{
	setPen(QPen(Qt::black));
	setBrush(QBrush(Qt::red));

}

void Bullet::boost()
{
	boosted_ = true;
}

void Bullet::slowDown()
{
	boosted_ = false;
}

void Bullet::setTarget(LetterWall *target)
{
	if(target){
		qreal xDist,yDist;
		switch(target->getSide()){
		case UP:
			xDist = (target->x() + target->boundingRect().width()/2.f) - (x() + boundingRect().width()/2);
			yDist = (target->y() + target->boundingRect().height()) - y();
			break;
		case DOWN:
			xDist = (target->x() + target->boundingRect().width()/2.f) - (x() + boundingRect().width()/2);
			yDist = target->y() - (y() + boundingRect().height());
			break;
		case LEFT:
			xDist = (target->x() + target->boundingRect().width()) - x();
			yDist = (target->y() + target->boundingRect().height()/2.f) - (y() + boundingRect().height()/2);
			break;
		case RIGHT:
			xDist = target->x() - (x() + boundingRect().width());
			yDist = (target->y() + target->boundingRect().height()/2.f) - (y() + boundingRect().height()/2);
			break;
		default:
			xDist = yDist = 0.f;
			break;
		}
		direction = Vector2f(xDist, yDist);
		direction.normalize();
	}else{
		direction = Vector2f::zero;
	}
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	QGraphicsEllipseItem::paint(painter, option, widget);
	//painter->drawRect(boundingRect());
	//painter->drawLine(5,5, 5 + direction.x()*1000.f, 5 + direction.y() * 1000.f);
}

void Bullet::tick(int dt)
{
	totalTime_ += dt;
	speed_ = qLn(totalTime_)*(2 + (boosted_ ? speedBoost_ : 0 ));

	this->setX(this->x() + (dt/100.f) * direction.x() * speed_);
	this->setY(this->y() + (dt/100.f) * direction.y() * speed_);
}

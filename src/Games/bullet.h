/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */

/*
 * File:   bullet.h
 * Author: boutina
 *
 * Created on 15 mars 2017, 19:00
 */

#ifndef BULLET_H
#define BULLET_H

#define BULLET_RADIUS 10

#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QDebug>

#include "vector2f.h"

class Bullet : public QGraphicsEllipseItem
{
public:
	Bullet(QGraphicsItem *parent = 0);

	void setTarget(QGraphicsItem *target);

	void tick(int dt);

private:
	Vector2f direction;

	float speed = 4.f;
};

#endif // BULLET_H

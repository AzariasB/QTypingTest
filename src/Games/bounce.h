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

#ifndef BOUNCE_H
#define BOUNCE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QDebug>
#include <QResizeEvent>

#include "bullet.h"
#include "letterwall.h"

#define WALL_SIZE 40
#define WALL_NUMBER 20

class Bounce : public QGraphicsView
{
public:
	Bounce(QWidget *parent = 0);

	void init();

	virtual ~Bounce();

	void resizeEvent(QResizeEvent *event);

public slots:
	void tick(int dt);

private:

	QVector<LetterWall*> createWall(int numberOfWalls, QPoint start, QPoint increment, DIRECTION wallSide);

	void addWallToScene(QVector<LetterWall*> &toAdd);

	void nextTarget(LetterWall *nwTarget = nullptr);

	void uncollideBullet(LetterWall *collider, DIRECTION targetDir);

	LetterWall *randomTarget(DIRECTION nwDirection = NO_DIRECTION);

	LetterWall *currentTarget_ = nullptr;

	QGraphicsScene scene_;

	Bullet bullet_;

	QVector<LetterWall*> leftWall_;
	QVector<LetterWall*> rightWall_;
	QVector<LetterWall*> upperWall_;
	QVector<LetterWall*> lowerWall_;
};

#endif // BOUNCE_H

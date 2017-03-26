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
#include "endmessage.h"

#define WALL_SIZE 40
#define WALL_NUMBER 20

class Bounce : public QGraphicsView
{
	Q_OBJECT
public:
	Bounce(QWidget *parent = 0);

	void init();

	virtual ~Bounce();

	void resizeEvent(QResizeEvent *event);

public slots:
	void tick(int dt);

signals:
	void gameEnded(int score);

protected:
	void keyPressEvent(QKeyEvent *event) override;

	void keyReleaseEvent(QKeyEvent *event) override;

private:
	static const QString alphabet;

	QVector<LetterWall*> createWall(int numberOfWalls, QPoint start, QPoint increment, DIRECTION wallSide);

	void addWallToScene(QVector<LetterWall*> &toAdd);

	void nextTarget(LetterWall *nwTarget = nullptr);

	void uncollideBullet(LetterWall *collider, DIRECTION targetDir);

	void restart();

	QGraphicsItem *getEndMessage();

	void looseGame();

	QChar randomLetter();

	LetterWall *randomTarget(DIRECTION nwDirection = NO_DIRECTION);

	LetterWall *currentTarget_ = nullptr;

	QGraphicsScene scene_;

	Bullet *bullet_;

	QChar currentPressed_ = '\0';

	QHash<QChar, QVector<LetterWall*>> equivalents_;

	int score_ = 0;

	bool lost_ = false;

	QVector<LetterWall*> leftWall_;
	QVector<LetterWall*> rightWall_;
	QVector<LetterWall*> upperWall_;
	QVector<LetterWall*> lowerWall_;
};

#endif // BOUNCE_H

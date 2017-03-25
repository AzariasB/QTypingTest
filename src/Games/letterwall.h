/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */

/*
 * File:   letterwall.h
 * Author: boutina
 *
 * Created on 15 mars 2017, 19:00
 */


#ifndef LETTERWALL_H
#define LETTERWALL_H

#define WALL_SIDE 20

#include <QGraphicsRectItem>
#include <QDebug>
#include <QPainter>

class LetterWall : public QGraphicsRectItem
{
public:
	LetterWall(QGraphicsItem *parent = 0);

	LetterWall(QChar copy, int x, int y, QGraphicsItem *parent = 0);

	QChar getChar() const{
		return char_;
	}

	void setSelectedState(){state_ = STATE_SELECTED;}

	void setWrongState(){state_ = STATE_WRONG;}

	void resetState(){state_ = STATE_NULL;}

	void setCorrectState(){state_ = STATE_CORRECT;}

	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
	enum STATE{
		STATE_NULL, STATE_SELECTED, STATE_WRONG, STATE_CORRECT
	};

	QChar char_;

	STATE state_ = STATE_NULL;

	QColor stateToColor();
};

#endif // LETTERWALL_H

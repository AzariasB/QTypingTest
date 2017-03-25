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

#include <QGraphicsRectItem>
#include <QDebug>
#include <QPainter>

class LetterWall : public QGraphicsRectItem
{
public:
	LetterWall(QGraphicsItem *parent = 0);

	LetterWall(QChar copy,int side, QGraphicsItem *parent = 0);

	QChar getChar() const{
		return char_;
	}

	void setSelectedState();

	void setWrongState();

	void resetState();

	void setCorrectState();

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

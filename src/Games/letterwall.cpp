/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */

/*
 * File:   letterwall.cpp
 * Author: boutina
 *
 * Created on 15 mars 2017, 19:00
 */


#include "letterwall.h"

LetterWall::LetterWall(QGraphicsItem *parent):
	QGraphicsRectItem(parent)
{

}

LetterWall::LetterWall(QChar copy, int sideSize, DIRECTION side, QGraphicsItem *parent):
	QGraphicsRectItem(0, 0, sideSize, sideSize, parent),
	char_(copy),
	side_(side)
{
}

void LetterWall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	QGraphicsRectItem::paint(painter, option, widget);
	painter->setBrush(QBrush(stateToColor()));
	painter->drawRect(rect());
	painter->setBrush(QBrush(QColor()));
	painter->setFont(QFont("Arial", 16));
	painter->drawText(this->boundingRect(), QString(char_),  Qt::AlignCenter | Qt::AlignVCenter );
}

void LetterWall::resetState()
{
	state_ = STATE_NULL;
	update();
}

void LetterWall::setSelectedState()
{
	state_ = STATE_SELECTED;
	update();
}

void LetterWall::setWrongState()
{
        state_ = STATE_WRONG;
	update();
}

void LetterWall::setCorrectState()
{
        state_ = STATE_CORRECT;
	update();
}

DIRECTION LetterWall::getSide()
{
	return side_;
}

QColor LetterWall::stateToColor()
{
	QColor color(Qt::white);
	switch(state_){
	case STATE_NULL:
		return color;
	case STATE_SELECTED:
		return QColor(65, 131, 215);//blue
	case STATE_CORRECT:
		return QColor(135, 211, 124);//green
	case STATE_WRONG:
		return QColor(242, 38, 19);//red
	default:
		break;
	}
	return color;
}

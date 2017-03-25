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

LetterWall::LetterWall(QChar copy, int x, int y, QGraphicsItem *parent):
	QGraphicsRectItem(x,y,WALL_SIDE, WALL_SIDE, parent),
	char_(copy)
{
	//setPos(x,y);
}

void LetterWall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->setBrush(QBrush(stateToColor()));
	painter->drawRect(rect());
	QGraphicsRectItem::paint(painter, option, widget);
	painter->drawText(QPoint(x(), y() + boundingRect().height()), QString(char_));
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



#include "recttext.h"
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

RectText::RectText(QGraphicsItem *parent):
	QGraphicsRectItem(parent)
{
	setAcceptHoverEvents(true);
}

RectText::RectText(const QRectF& bounds,
				   const QString &message,
				   QGraphicsItem *parent,
				   const QColor &backgroundColor,
				   const QColor &borderColor):
	QGraphicsRectItem(bounds, parent),
        message_(message),
                borderColor_(borderColor)
{
    for(RectTextState r : {RectTextState::Default, RectTextState::Hovered, RectTextState::Selected})
            properties_[r].bgColor = backgroundColor;

	setAcceptHoverEvents(true);
}

void RectText::setMessage(const QString &message)
{
	message_ = message;
}


void RectText::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
	painter->setPen(borderColor_);
	painter->setBrush(QBrush(properties_[currentState_].bgColor));
	painter->drawRect(boundingRect());

	painter->setPen(QColor(properties_[currentState_].penColor));
	painter->setFont(properties_[currentState_].font);
	painter->drawText(boundingRect(),message_, Qt::AlignCenter | Qt::AlignVCenter);
}

void RectText::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	QGraphicsItem::mousePressEvent(event);
	if(event != 0 && event->button() == Qt::LeftButton){
		emit mousePressed();
	}
}

void RectText::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
	Q_UNUSED(event);
	setCurrentState(RectTextState::Hovered);
}

void RectText::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
	Q_UNUSED(event);
	setCurrentState(RectTextState::Default);
}


RecTextProperty& RectText::getProperty(const RectTextState& state)
{
	return properties_[state];//Default constructor if does not exists
}

void RectText::mapProperties(void (*mapper)(RecTextProperty &))
{
	RectTextState allStates[] = {RectTextState::Default, RectTextState::Hovered, RectTextState::Selected};
	for(RectTextState r : allStates){
		(*mapper)(properties_[r]);
	}
}

void RectText::setCurrentState(RectTextState nwState)
{
	currentState_ = nwState;
	update();
}

uint qHash(const RectTextState& state){
	return static_cast<int>(state);
}

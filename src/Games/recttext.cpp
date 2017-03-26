#include "recttext.h"

RectText::RectText(QGraphicsItem *parent):
	QGraphicsRectItem(parent)
{

}

RectText::RectText(const QRectF& bounds,
				   const QString &message,
				   const QColor &backgroundColor,
				   const QColor &borderColor,
				   QGraphicsItem *parent):
	QGraphicsRectItem(bounds, parent),
        message_(message),
		bgColor_(backgroundColor),
		borderColor_(borderColor)
{

}

void RectText::setMessage(const QString &message)
{
	message_ = message;
}


void RectText::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->setPen(borderColor_);
	painter->setBrush(QBrush(bgColor_));
	painter->drawRect(boundingRect());

	painter->setPen(QColor());
	painter->setFont(QFont("Arial", 24));
	painter->drawText(boundingRect(),message_, Qt::AlignCenter | Qt::AlignVCenter);
}

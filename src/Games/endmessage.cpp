#include "endmessage.h"

EndMessage::EndMessage(QGraphicsItem *parent):
	QGraphicsRectItem(parent)
{

}

EndMessage::EndMessage(const QRectF& bounds, const QString &message, QGraphicsItem *parent):
	QGraphicsRectItem(bounds, parent),
	message_(message)
{

}


void EndMessage::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	QGraphicsRectItem::paint(painter, option, widget);
	painter->setBrush(QBrush(QColor(135, 211, 124)));
	painter->drawRect(boundingRect());

	painter->setFont(QFont("Arial", 24));
	painter->drawText(boundingRect(),message_, Qt::AlignCenter | Qt::AlignVCenter);
}

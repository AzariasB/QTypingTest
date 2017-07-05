

#include "recttext.h"
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

RectText::RectText(QGraphicsItem *parent):
	QGraphicsRectItem(parent)
{
}

RectText::RectText(const QRectF& bounds,
				   const QString &message,
				   QGraphicsItem *parent,
				   const QColor &backgroundColor,
				   const QColor &borderColor):
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


void RectText::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
	painter->setPen(borderColor_);
	painter->setBrush(QBrush(bgColor_));
	painter->drawRect(boundingRect());

	painter->setPen(QColor());
	painter->setFont(font_);
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
    QColor tmpColor = bgColor_;
    bgColor_ = hoverColor_;
    hoverColor_ = tmpColor;
    update();
}

void RectText::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QColor tmpColor = bgColor_;
    bgColor_ = hoverColor_;
    hoverColor_ = tmpColor;
    update();
}

void RectText::setFontFamily(QString fontFamily)
{
	font_.setFamily(fontFamily);
}

void RectText::setFontSize(int nwFontSize)
{
	font_.setPixelSize(nwFontSize);
}


void RectText::setHoverColor(QColor nwColor)
{
    hoverColor_ = nwColor;
}

void RectText::setChangeColorOnHover(bool nwChangeColorOnHover)
{
    changeColorOnHover_ = nwChangeColorOnHover;
    setAcceptHoverEvents(changeColorOnHover_);
}

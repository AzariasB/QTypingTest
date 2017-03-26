#ifndef ENDMESSAGE_H
#define ENDMESSAGE_H

#include <QGraphicsRectItem>
#include <QPainter>
#include <qglobal.h>

class EndMessage : public QGraphicsRectItem
{
public:
	EndMessage(QGraphicsItem *parent = 0);

	EndMessage(const QRectF &bounds, const QString &message, QGraphicsItem *parent = 0);

protected:
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:

	QString message_;
};

#endif // ENDMESSAGE_H

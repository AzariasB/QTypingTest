#ifndef ENDMESSAGE_H
#define ENDMESSAGE_H

#include <QGraphicsRectItem>
#include <QPainter>
#include <qglobal.h>

/**
 * @brief The EndMessage class
 * Message displayed at the end of a game
 */
class RectText : public QGraphicsRectItem
{
public:
	RectText(QGraphicsItem *parent = 0);

	RectText(const QRectF &bounds,
			 const QString &message,
			 const QColor &backgroundColor = Qt::white,
			 const QColor &borderColor = Qt::white,
			 QGraphicsItem *parent = 0);

public slots:
	void setMessage(const QString &message);

protected:
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;

private:
	//Message to display
	QString message_;

	//Background color
	QColor bgColor_;

	//Border color
	QColor borderColor_;
};

#endif // ENDMESSAGE_H

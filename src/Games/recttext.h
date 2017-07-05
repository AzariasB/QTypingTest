#ifndef ENDMESSAGE_H
#define ENDMESSAGE_H

#include <QGraphicsRectItem>
#include <QPainter>
#include <qglobal.h>


/**
 * @brief The EndMessage class
 * Message displayed at the end of a game
 */
class RectText : public QObject, public QGraphicsRectItem
{
	Q_OBJECT
public:
	RectText(QGraphicsItem *parent = 0);

        RectText(const QRectF &bounds,
                         const QString &message,
                         QGraphicsItem *parent = 0,
                         const QColor &backgroundColor = Qt::white,
                         const QColor &borderColor = Qt::white);


	void setFontSize(int nwFontSize);

	void setFontFamily(QString fontFamily);

        /**
         * @brief setChangeColorOnHover
         * Wether to change color when overring with mouse
         *
         *
         * @param nwChangeColorOnHover wether to change color when hovering
         *
         */
        void setChangeColorOnHover(bool nwChangeColorOnHover);

        /**
         * @brief setHoverColor
         * Color of mouse when hoverring the item
         *
         * @param nwColor
         * the color to set when overring
         */
        void setHoverColor(QColor nwColor);

public slots:
	void setMessage(const QString &message);

protected:
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;

	void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

        void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;

        void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;

signals:
	void mousePressed();


private:
	//Message to display
	QString message_;

	//Background color
	QColor bgColor_;

	//Border color
	QColor borderColor_;

        //Color when hover with mouse
        QColor hoverColor_;

        bool changeColorOnHover_ = false;

	QFont font_ = QFont("Arial", 24);
};

#endif // ENDMESSAGE_H

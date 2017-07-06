#ifndef ENDMESSAGE_H
#define ENDMESSAGE_H

#include <QGraphicsRectItem>
#include <QPainter>
#include <qglobal.h>


enum class RectTextState{
	Default = 0,
	Hovered = 1,
	Selected = 2
};


struct RecTextProperty{
	QFont font = QFont("Arial", 24);
	QColor penColor;
	QColor bgColor = QColor(Qt::transparent);
};

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

	RecTextProperty& getProperty(const RectTextState &state);


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
	// Methods
	void updateState(const RectTextState &nwState);

	//Message to display
	QString message_;

	//Border color
	QColor borderColor_;

	QHash<RectTextState, RecTextProperty> properties_;

	RectTextState currentState_ = RectTextState::Default;
};

#endif // ENDMESSAGE_H

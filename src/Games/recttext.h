/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */

/*
 * File:   recttext.h
 * Author: azarias
 *
 */

#ifndef ENDMESSAGE_H
#define ENDMESSAGE_H

#include <QGraphicsRectItem>
#include <QPainter>
#include <qglobal.h>


/**
 * @brief The RectTextState enum
 * Possible states for a recText object
 * Default is when nothings happens
 * Hovered is when the item is hoverred with the mouse
 * Selected is when the item is clicked/selected
 */
enum class RectTextState{
	Default = 0,
	Hovered = 1,
	Selected = 2
};


/**
 * @brief The RecTextProperty struct
 * data of a single item, each state of a
 * recText has its own property, so every thing can be changed
 * when an event happens (hoverred, selected)
 */
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

	/**
	 * @brief RectText
	 * Settups a recText
	 *
	 * @param bounds the item bounds
	 * @param message the message to display in the rectangle
	 * @param parent the parent object (if any)
	 * @param backgroundColor the background color for the item, will be set for all states
	 * @param borderColor the border color, does not change between the different states
	 */
	RectText(const QRectF &bounds,
					 const QString &message,
					 QGraphicsItem *parent = 0,
					 const QColor &backgroundColor = Qt::white,
					 const QColor &borderColor = Qt::white);


	/**
	 * @brief getProperty
	 * Returns the property for the given state, if the property does not exist, construct (default construct) a new one
	 *
	 * @param state the state containg the property
	 * @return the property related to the given state
	 */
	RecTextProperty& getProperty(const RectTextState &state);

	/**
	 * @brief mapProperties calls the given function for all the existing properties
	 * The given function cannot capture anything for now :/
	 */
	void mapProperties(void (*mapper)(RecTextProperty&));

	/**
	 * @brief setCurrentState
	 * Changes the current state of the recText and redraw it
	 *
	 * @param nwState the nwState to set
	 */
	void setCurrentState(RectTextState nwState);


public slots:
	/**
	 * @brief setMessage
	 * Changes the message of the object and repaint it
	 *
	 * @param message the new message to set
	 */
	void setMessage(const QString &message);

protected:
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;

	void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

	void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;

	void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;

signals:
	/**
	 * @brief mousePressed
	 * Trigerred when the mousePressEvent is received and is "valid" (left button)
	 */
	void mousePressed();


private:
	//Message to display
	QString message_;

	//Border color
	QColor borderColor_;

	//Property for each possible state of the recText
	QHash<RectTextState, RecTextProperty> properties_;

	// Current state of the object
	RectTextState currentState_ = RectTextState::Default;
};

#endif // ENDMESSAGE_H

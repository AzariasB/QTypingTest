/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */

/*
 * File:   letterwall.h
 * Author: boutina
 *
 * Created on 15 mars 2017, 19:00
 */


#ifndef LETTERWALL_H
#define LETTERWALL_H

#include <QGraphicsRectItem>
#include "src/Games/vector2f.h" // For "direction" enum

/**
 * @brief The LetterWall class
 * A simple entity that the bullet can collide with.
 * Contains a character that the player has to type
 * when targeted.
 */
class LetterWall : public QGraphicsRectItem
{
public:
	LetterWall(QGraphicsItem *parent = 0);

	LetterWall(QChar copy,int sideSize, DIRECTION side, QGraphicsItem *parent = 0);

	/**
	 * @brief getChar
	 * @return the wall's character
	 */
	QChar getChar() const{
		return char_;
	}

	/**
	 * @brief setSelectedState
	 * Sets the state to 'selected'
	 */
	void setSelectedState();

	/**
	 * @brief setWrongState
	 * Sets the state to 'wrong'
	 */
	void setWrongState();

	/**
	 * @brief resetState
	 * Removes the state (sets to 'STATE_NULL')
	 */
	void resetState();

	/**
	 * @brief setCorrectState
	 * Sets the state to 'correct'
	 */
	void setCorrectState();

	/**
	 * @brief getSide
	 * On which side of the main scene is positioned this wall
	 * @return the wall's side
	 */
	DIRECTION getSide();

	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
	//State of the wall (null = normal, selected = blue, wrong = red, correct = green)
	enum STATE{
		STATE_NULL, STATE_SELECTED, STATE_WRONG, STATE_CORRECT
	};

	// Char to copy when targetd
	QChar char_;

	// Current state of the wall
	STATE state_ = STATE_NULL;

	// Side on the main scene
	DIRECTION side_ = NO_DIRECTION;

	/**
	 * @brief stateToColor
	 * Returns the color based on the current state of the wall
	 * @return color based on the state
	 */
	QColor stateToColor();
};

#endif // LETTERWALL_H

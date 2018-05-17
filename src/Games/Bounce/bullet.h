/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */

/*
 * File:   bullet.h
 * Author: boutina
 *
 * Created on 15 mars 2017, 19:00
 */

#ifndef BULLET_H
#define BULLET_H

#define BULLET_RADIUS 10

#include <QGraphicsEllipseItem>
#include "src/Games/vector2f.h"
class LetterWall;

/**
 * @brief The Bullet class
 * Used in the bounce game, a bullet is a simple ellipse (circle)
 * with a direction and a speed, every game tick, it will advance
 * to its direction
 */
class Bullet : public QGraphicsEllipseItem
{
public:
	Bullet(QGraphicsItem *parent = 0);

	/**
	 * @brief setTarget
	 * Changes the bullet's target, the bullet
	 * will update its direction to perfectly touch the right side
	 * of the wall in its exact center
	 * @param target the bullet's new target
	 */
	void setTarget(LetterWall *target);

	/**
	 * @brief tick
	 * Updates the bullet position
	 * @param dt the time since last called
	 */
	void tick(int dt);

	/**
	 * @brief boost
	 * Improves the bullet speed by 'speedBoost'
	 * if the bullet is not already boosted
	 */
	void boost();

	/**
	 * @brief slowDown
	 * Retrieves the normal bullet's speed
	 * if the bullet is not already at its normal speed
	 */
	void slowDown();

	/**
	 * @brief reset
	 * Reset the data about the bullet :
	 *  - speed and boosted to false
	 *
	 */
	void reset();

protected:
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
	// A normal vector to indicate the bullet direction
	Vector2f direction;

	// Wether the bullet is boosted
	bool boosted_ = false;

	qreal totalTime_ = 0;

	// Bullet's speedBoost ( valued added to the normal speed when in boost mode)
	const qreal speedBoost_ = 2.f;
};

#endif // BULLET_H

/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */
/*
 * File:   animatedsprite.h
 * Author: azarias
 *
 */

#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include <QGraphicsRectItem>
#include <QPixmap>
#include <QTimer>

class AnimatedSprite : public QGraphicsRectItem
{
public:
	AnimatedSprite(QGraphicsItem *parent = 0);

        AnimatedSprite(const QPixmap &pixmap, int frames = 1, bool destroysWhenFinished = false, QGraphicsItem *parent = 0);

protected:
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;

private:
	void init();

	void tick(int);

	QTimer timer_;

	QPixmap pixmap_;

	int frameNumber_;

	float frameWidth_;

	int currentFrame_;

	bool destroysWhenFinished_;

};

#endif // ANIMATEDSPRITE_H

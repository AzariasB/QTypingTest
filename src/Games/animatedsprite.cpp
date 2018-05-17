/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */
/*
 * File:   animatedsprite.cpp
 * Author: azarias
 *
 */


#include "animatedsprite.h"
#include <QPainter>
#include <QGraphicsScene>

AnimatedSprite::AnimatedSprite(QGraphicsItem *parent):
        QGraphicsRectItem(parent)
{
	init();
}

AnimatedSprite::AnimatedSprite(const QPixmap &pixmap, int frames, bool destroysWhenFinished, QGraphicsItem *parent):
        QGraphicsRectItem(QRectF(0,0,pixmap.width()/frames, pixmap.height()),parent),
        pixmap_(pixmap),
	frameNumber_(frames),
	frameWidth_(pixmap.width()/(float)frames),
	currentFrame_(0),
	destroysWhenFinished_(destroysWhenFinished)
{
	init();
}

void AnimatedSprite::init()
{
    int interval = 60;
    timer_.setInterval(interval);
    timer_.setSingleShot(false);
    QObject::connect(&timer_, &QTimer::timeout, [=](){
            tick(interval);
    });
    timer_.start();
}

void AnimatedSprite::tick(int )
{
	currentFrame_++;
	if(currentFrame_ == frameNumber_){
		if(destroysWhenFinished_){
			scene()->removeItem(this);
		}else{
			currentFrame_ = 0;
		}
	}
        update();
}

void AnimatedSprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
        QRectF target(0,0, frameWidth_, pixmap_.height());
        QRectF source(currentFrame_ * frameWidth_, 0, frameWidth_, pixmap_.height() );
        painter->drawPixmap(target, pixmap_, source);
}

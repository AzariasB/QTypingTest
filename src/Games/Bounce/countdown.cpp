/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */

/*
 * File:   countdown.cpp
 * Author: azarias
 *
 */

#include "countdown.h"

Countdown::Countdown()
{
	setStyleSheet("background-color : white;");

	setFont(QFont("Coalition", 28));


	timer_.setInterval(1000);
	timer_.setSingleShot(false);
	connect(&timer_, &QTimer::timeout, this, &Countdown::tick);
	setText(QString::number(value_));
}

void Countdown::reset()
{
	timer_.stop();
	value_ = 3;
	setText(QString::number(value_));
}


void Countdown::start()
{
	timer_.start();
}

void Countdown::tick()
{
	if(value_ <= 0)return;

	value_--;
	setText(QString::number(value_));
	if(value_ == 0){
		emit timeout();
	}
}

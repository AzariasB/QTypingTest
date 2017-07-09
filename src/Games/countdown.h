/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */

/*
 * File:   countdown.h
 * Author: azarias
 *
 */

#ifndef COUNTDOWN_H
#define COUNTDOWN_H

#include <QLabel>
#include <QTimer>

/**
 * @brief The Countdown class
 * Countdown object : used to have a countdown
 * before starting the game,
 * when the count ended, the event "timeout"
 * is emitted
 *
 */
class Countdown : public QLabel
{
	Q_OBJECT
public:
	Countdown();

	/**
	 * @brief reset
	 * Resets the value and the display to 3 and
	 * stops the timer
	 */
	void reset();

signals:
	/**
	 * @brief timeout
	 * Emitted when the value reaches 0
	 */
	void timeout();

public slots:
	/**
	 * @brief start
	 * Starts the timer
	 */
	void start();


private:
	/**
	 * @brief tick
	 * Called every second to update the
	 * displayed value
	 */
	void tick();

	// Currently displayed value
	int value_ = 3;

	// Timer to update the value when timeout
	QTimer timer_;
};

#endif // COUNTDOWN_H

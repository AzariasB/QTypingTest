/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */
/*
 * File:   bouncedata.h
 * Author: azarias
 *
 */

#ifndef BOUNCEDATA_H
#define BOUNCEDATA_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QTime>
#include <QPushButton>


class BounceData : public QWidget
{
	Q_OBJECT
public:
	BounceData(int lives, QWidget *parent = 0);

	void reset(int lives);

	int getScore(){
		return score_;
	}

	QTime time(){
		return totalTime_;
	}

public slots:
	void incrementScore();

	bool decrementLives();

	void play();

	void stop();

	void pause();

	void addSecond();

signals:
	void playPause();

	void exit();

private:
	QFrame *getLine();

	QLabel *livesLabel_;

	QLabel *scoreLabel_;

	QLabel *timerLabel_;

	QTimer timer_;

	QTime totalTime_ = QTime(0,0);

	QPushButton *playPauseButton_;

	int score_ = 0;

	int lives_;
};

#endif // BOUNCEDATA_H

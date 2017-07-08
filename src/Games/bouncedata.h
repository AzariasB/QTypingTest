#ifndef BOUNCEDATA_H
#define BOUNCEDATA_H

#include <QWidget>
#include <QLabel>
#include <QLCDNumber>
#include <QTimer>
#include <QTime>

class BounceData : public QWidget
{
	Q_OBJECT
public:
	BounceData(int lives, QWidget *parent = 0);

	void reset(int lives);

	int getScore(){
		return score_;
	}

public slots:
	void incrementScore();

	bool decrementLives();

	void start();

	void stop();

	void addSecond();

signals:
	void noMoreLives();

private:
	QFrame *getLine();

	QLabel *livesLabel_;

	QLabel *scoreLabel_;

	QLabel *timerLabel_;

	QFont font_ = QFont("Arial", 24);

	QTimer timer_;

	QTime totalTime_ = QTime(0,0);

	int score_ = 0;

	int lives_;
};

#endif // BOUNCEDATA_H

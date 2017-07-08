#ifndef BOUNCEDATA_H
#define BOUNCEDATA_H

#include <QWidget>
#include <QLabel>

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

signals:
	void noMoreLives();

private:

	QLabel *livesLabel_;

	QLabel *scoreLabel_;

	int score_ = 0;

	int lives_;
};

#endif // BOUNCEDATA_H

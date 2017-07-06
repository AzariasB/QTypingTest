#ifndef BOUNCEDATA_H
#define BOUNCEDATA_H

#include <QWidget>

#include "recttext.h"

class BounceData : public QWidget
{
public:
	BounceData(int lives, QWidget *parent = 0);

	void incrementScore();

	bool decrementLives();

	void reset(int lives);

	int getScore(){
		return score_;
	}

private:

	RectText *scoreText_;

	RectText *livesText_;

	int score_ = 0;

	int lives_;
};

#endif // BOUNCEDATA_H

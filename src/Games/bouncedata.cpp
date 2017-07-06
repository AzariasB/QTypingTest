

#include "bouncedata.h"
#include <QVBoxLayout>
#include <QGraphicsLinearLayout>

BounceData::BounceData(int lives, QWidget *parent):
	QWidget(parent)
{
	lives_ = lives;
	score_ = 0;

	//Add layout and stuff
}

void BounceData::incrementScore()
{
	score_++;
	scoreText_->setMessage(QString(score_));
}

bool BounceData::decrementLives()
{
	lives_--;
	livesText_->setMessage(QString(lives_));
	return lives_ <= 0;
}

void BounceData::reset(int lives)
{
	lives_ = lives;
	score_ = 0;

	scoreText_->setMessage(QString(score_));
	livesText_->setMessage(QString(lives_));
}

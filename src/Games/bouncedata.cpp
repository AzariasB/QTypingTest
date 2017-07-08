

#include "bouncedata.h"
#include <QVBoxLayout>
#include <QGraphicsLinearLayout>

BounceData::BounceData(int lives, QWidget *parent):
	QWidget(parent),
	scoreLabel_(new QLabel("Score : 0")),
	livesLabel_(new QLabel())
{
	lives_ = lives;
	score_ = 0;

	livesLabel_->setText(QString("Lives : %1").arg(lives_));
	//Add layout and stuff
	QVBoxLayout *mainLayout = new QVBoxLayout;

	mainLayout->setAlignment(Qt::AlignTop);
	mainLayout->addWidget(scoreLabel_);
	mainLayout->addWidget(livesLabel_);

	setLayout(mainLayout);
}

void BounceData::incrementScore()
{
	score_++;
	scoreLabel_->setText(QString("Score : %1").arg(score_) );
}

bool BounceData::decrementLives()
{
	lives_--;
	livesLabel_->setText(QString("Lives : %1").arg(lives_));
	return lives_ > 0;
}

void BounceData::reset(int lives)
{
	lives_ = lives;
	score_ = 0;

	scoreLabel_->setText(QString("Score : %1").arg(score_) );
	livesLabel_->setText(QString("Lives : %1").arg(lives_));
}



#include "bouncedata.h"
#include <QVBoxLayout>
#include <QGraphicsLinearLayout>

BounceData::BounceData(int lives, QWidget *parent):
	QWidget(parent),
	scoreLabel_(new QLabel("Score : 0")),
	livesLabel_(new QLabel),
	timerLabel_(new QLabel("00:00"))
{
	scoreLabel_->setFont(font_);
	livesLabel_->setFont(font_);
	timerLabel_->setFont(font_);
	lives_ = lives;
	score_ = 0;
	timer_.setInterval(1000);
	timer_.setSingleShot(false);

	connect(&timer_, &QTimer::timeout, this, &BounceData::addSecond);


	livesLabel_->setText(QString("Lives : %1").arg(lives_));
	//Add layout and stuff
	QVBoxLayout *mainLayout = new QVBoxLayout;

	mainLayout->setAlignment(Qt::AlignTop);
	QLabel *title = new QLabel("Bounce game");
	title->setFont(font_);

	mainLayout->addWidget(title);
	mainLayout->addWidget(getLine());
	mainLayout->addWidget(scoreLabel_);
	mainLayout->addWidget(livesLabel_);
	mainLayout->addWidget(timerLabel_);

	setLayout(mainLayout);
}

void BounceData::addSecond()
{
	totalTime_ =  totalTime_.addSecs(1);
	timerLabel_->setText(totalTime_.toString("mm:ss"));
}

void BounceData::start()
{
	timer_.start();
}

void BounceData::stop()
{
	timer_.stop();
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
	totalTime_ = QTime(0,0);

	scoreLabel_->setText(QString("Score : %1").arg(score_) );
	livesLabel_->setText(QString("Lives : %1").arg(lives_));
}

QFrame *BounceData::getLine()
{
	QFrame *f = new QFrame;
	f->setFrameShape(QFrame::HLine);
	f->setFrameShadow(QFrame::Sunken);
	return f;
}

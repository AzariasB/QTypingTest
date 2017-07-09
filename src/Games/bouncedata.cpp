

#include "bouncedata.h"
#include <QVBoxLayout>
#include <QGraphicsLinearLayout>

#include <qdebug.h>

BounceData::BounceData(int lives, QWidget *parent):
	QWidget(parent),
	livesLabel_(new QLabel),
	scoreLabel_(new QLabel("Score : 0")),
	timerLabel_(new QLabel("00:00"))
{
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

	QPushButton *exitButton = new QPushButton("Exit");
	exitButton->setStyleSheet(("font-size : 20px;"));
	connect(exitButton, &QPushButton::clicked, [=](){
		emit exit(score_, totalTime_);
	});

	playPauseButton_ = new QPushButton("Pause");
	playPauseButton_->setStyleSheet("font-size : 20px;");
	connect(playPauseButton_, &QPushButton::clicked, this, &BounceData::playPause);


	mainLayout->addWidget(title);
	mainLayout->addWidget(getLine());
	mainLayout->addWidget(scoreLabel_);
	mainLayout->addWidget(livesLabel_);
	mainLayout->addWidget(timerLabel_);

	mainLayout->addStretch(1);

	mainLayout->addWidget(playPauseButton_);
	mainLayout->addWidget(exitButton);

	setLayout(mainLayout);
}

void BounceData::addSecond()
{
	totalTime_ =  totalTime_.addSecs(1);
	timerLabel_->setText(totalTime_.toString("mm:ss"));
}

void BounceData::play()
{
	playPauseButton_->setText(("Pause"));
	timer_.start();
}

void BounceData::stop()
{
	timer_.stop();
}

void BounceData::pause()
{
	playPauseButton_->setText(("Play"));
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

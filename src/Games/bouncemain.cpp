/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */

/*
 * File:   bouncemain.h
 * Author: azarias
 *
 */

#include "bouncemain.h"
#include <QDebug>
#include <QFontDatabase>

BounceMain::BounceMain(QWidget *parent) : QWidget(parent),
	mainLayout_(new QStackedLayout(this)),
	menu_(new BounceMenu()),
	help_(new BounceHelp()),
	bData_(new BounceData(5)),
	bGame_(new BounceGame(bData_)),
	bScore_(new BounceScore()),
	gameWidget_(new QWidget())
{
	if(QFontDatabase::addApplicationFont(":/font/coalition.ttf") == -1){
		qDebug() << "Failed to load font";
	}
	QFile f(":/gamestyle.qss");
	f.open(QIODevice::ReadOnly | QIODevice::Text);
	QLatin1String style = QLatin1String(f.readAll());
	f.close();
	setStyleSheet(style);
	bData_->setStyleSheet(style);

	connect(menu_, &BounceMenu::playSelected, this, &BounceMain::showGame);
	connect(menu_, &BounceMenu::helpSelected, this, &BounceMain::showHelp);
	connect(menu_, &BounceMenu::leaderBoardSelected, this, &BounceMain::showLeaderboard);
	connect(bData_, &BounceData::exit, this, &BounceMain::showMenu);
	connect(bGame_, &BounceGame::gameEnded, this, &BounceMain::saveGameScore);
	connect(help_, &BounceHelp::backToMenu,this, &BounceMain::showMenu);
	connect(bScore_, &BounceScore::showMenu, this, &BounceMain::showMenu);
	connect(bScore_, &BounceScore::play, this, &BounceMain::showGame);
	connect(menu_, &BounceMenu::quitSelected, [=](){
		close();
	});

	mainLayout_->setContentsMargins(0,0,0,0);
	mainLayout_->addWidget(menu_);
	mainLayout_->addWidget(help_);
	mainLayout_->addWidget(bScore_);

	initGameWidget();
	mainLayout_->addWidget(gameWidget_);

	mainLayout_->setCurrentWidget(menu_);
	menu_->setFocus();
}

void BounceMain::initGameWidget()
{
	QHBoxLayout *layout = new QHBoxLayout;
	layout->setContentsMargins(0,0,0,0);
	layout->addWidget(bData_);
	layout->addWidget(bGame_);
	bData_->setFocusPolicy(Qt::NoFocus);

	gameWidget_->setLayout(layout);
	gameWidget_->setStyleSheet("background-color : white;");
}

void BounceMain::saveGameScore(int score, QTime time)
{
	if(score > 0){
		showLeaderboard();
		bScore_->addPlayerScore(score, time);
	}else if(score == -1){
		showMenu();
	}
}

void BounceMain::showLeaderboard()
{
	mainLayout_->setCurrentWidget(bScore_);
	bScore_->setFocus();
}

void BounceMain::showMenu()
{
	mainLayout_->setCurrentWidget(menu_);
	menu_->setFocus();
}

void BounceMain::showGame()
{
	bGame_->restart();
	mainLayout_->setCurrentWidget(gameWidget_);
}

void BounceMain::showHelp()
{
	mainLayout_->setCurrentWidget(help_);
}

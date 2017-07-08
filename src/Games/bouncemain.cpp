
#include "bouncemain.h"
#include <QDebug>

BounceMain::BounceMain(QWidget *parent) : QWidget(parent),
	mainLayout_(new QStackedLayout(this)),
	menu_(new BounceMenu()),
	help_(new BounceHelp()),
	bData_(new BounceData(5)),
	bGame_(new BounceGame(bData_)),
	gameWidget_(new QWidget())
{
	connect(menu_, &BounceMenu::playSelected, this, &BounceMain::showGame);
	connect(menu_, &BounceMenu::helpSelected, this, &BounceMain::showHelp);
	connect(bGame_, &BounceGame::gameEnded, this, &BounceMain::showMenu);
	connect(help_, &BounceHelp::backToMenu,this, &BounceMain::showMenu);
	connect(menu_, &BounceMenu::quitSelected, [=](){
		close();
	});

	mainLayout_->setContentsMargins(0,0,0,0);
	mainLayout_->addWidget(menu_);
	mainLayout_->addWidget(help_);

	initGameWidget();
	mainLayout_->addWidget(gameWidget_);

	mainLayout_->setCurrentWidget(menu_);
}

void BounceMain::initGameWidget()
{
	QHBoxLayout *layout = new QHBoxLayout;
	layout->setContentsMargins(0,0,0,0);
	layout->addWidget(bData_);
	layout->addWidget(bGame_);

	gameWidget_->setLayout(layout);
	gameWidget_->setStyleSheet("background-color : white;");
}

void BounceMain::showMenu()
{
	mainLayout_->setCurrentWidget(menu_);
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

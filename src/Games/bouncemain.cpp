
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
	connect(menu_, &BounceMenu::quitSelected, [=](){
		close();
	});
	connect(help_, &BounceHelp::backToMenu, [=](){
		mainLayout_->setCurrentWidget(menu_);
	});

	mainLayout_->addWidget(menu_);
	mainLayout_->addWidget(help_);

	initGameWidget();
	mainLayout_->addWidget(gameWidget_);

	mainLayout_->setCurrentWidget(menu_);
}

void BounceMain::initGameWidget()
{
	QHBoxLayout *layout = new QHBoxLayout;
	layout->addWidget(bData_);
	layout->addWidget(bGame_);

	//Connect game signals to data slots
	gameWidget_->setLayout(layout);
}

void BounceMain::showGame()
{
	mainLayout_->setCurrentWidget(gameWidget_);
}

void BounceMain::showHelp()
{
	mainLayout_->setCurrentWidget(help_);
}

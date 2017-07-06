#include "bouncemain.h"

BounceMain::BounceMain(QWidget *parent) : QWidget(parent),
	mainLayout_(new QStackedLayout(this)),
	menu_(new BounceMenu()),
	help_(new BounceHelp()),
	bData_(new BounceData(5)),
	bGame_(new BounceGame())
{
	mainLayout_->addWidget(menu_);
	mainLayout_->addWidget(help_);
	mainLayout_->addWidget(bData_);
	mainLayout_->addWidget(bGame_);

	mainLayout_->setCurrentWidget(menu_);
}

/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */

/*
 * File:   bouncemenu.h
 * Author: azarias
 *
 */

#include "bouncemenu.h"
#include "recttext.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
#include <QIcon>
#include <QKeyEvent>

BounceMenu::BounceMenu(QWidget *parent):
QWidget(parent)
{
	MenuButton *playButton = new MenuButton("Play ▶");
	connect(playButton, SIGNAL(clicked(bool)), this, SIGNAL(playSelected()) );

	MenuButton *helpButton = new MenuButton("Help ?");
	connect(helpButton, SIGNAL(clicked(bool)), this, SIGNAL(helpSelected()) );

	MenuButton *quitButton = new MenuButton("Quit ✗");
	connect(quitButton, SIGNAL(clicked(bool)) , this, SIGNAL(quitSelected()));

	MenuButton *leaderBoardButton = new MenuButton("Leaderboard 🏆");
	connect(leaderBoardButton, &MenuButton::clicked, this, &BounceMenu::leaderBoardSelected);

	buttons_ << playButton << helpButton << leaderBoardButton << quitButton;

	foreach (MenuButton *mb, buttons_) {
		connect(mb, &MenuButton::hovered, [=](){
			selectionChanged(buttons_.indexOf(mb));
		});
	}
	buttons_[selectedButton_]->setIsSelected(true);

	QVBoxLayout *mainLayout = new QVBoxLayout(this);

	QLabel *title = new QLabel("Bounce game");
	title->setStyleSheet("font-size : 32px;");
	title->setAlignment(Qt::AlignCenter);

	mainLayout->setContentsMargins(300, 300, 300, 300);
	mainLayout->addWidget(title);
	mainLayout->addWidget(playButton);
	mainLayout->addWidget(helpButton);
	mainLayout->addWidget(leaderBoardButton);
	mainLayout->addWidget(quitButton);
}

void BounceMenu::keyPressEvent(QKeyEvent *event)
{
	if(event->key() == Qt::Key_Up){
		selectionChanged(selectedButton_-1);
	}else if(event->key() == Qt::Key_Down){
		selectionChanged(selectedButton_ + 1);
	}else if(event->key() == Qt::Key_Return){
		emit buttons_[selectedButton_]->click();
	}
}

void BounceMenu::selectionChanged(int nwSelection)
{
	if(nwSelection >= 0 && nwSelection < buttons_.size()){
		selectedButton_ = nwSelection;
		for(int i = 0; i < buttons_.size();i++){
			buttons_[i]->setIsSelected(i == selectedButton_);
		}
	}
}

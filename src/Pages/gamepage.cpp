/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */

/* 
 * File:   GamePage.cpp
 * Author: boutina
 * 
 * Created on 3 février 2016, 09:58
 */


#include "gamepage.h"

#include "Widgets/tpresentation.h"
#include "tapplication.h"


GamePage::~GamePage(){
}

GamePage::GamePage(QWidget* parent):
QWidget(parent),
interactiveKeyboard_(new QPushButton("Interactive keyboard")),
bounceGame_(new QPushButton("Bounce game")){
    setupWidgets();
    connectEvents();
}

void GamePage::setupWidgets() {
    QGridLayout *mainLay = new QGridLayout();
    
    mainLay->addWidget(interactiveKeyboard_);
	mainLay->addWidget(bounceGame_);
    
    setLayout(mainLay);
}

void GamePage::connectEvents() {
    connect(interactiveKeyboard_,SIGNAL(clicked()),this,SLOT(showInteractiveKeyboard()));
	connect(bounceGame_, SIGNAL(clicked()), this, SLOT(showBounceGame()));
}

void GamePage::showBounceGame()
{
	BounceMain *bMain = new BounceMain;
	bMain->show();
	//connect(b, SIGNAL(gameEnded(int)), dial, SLOT(close()));
}

void GamePage::showInteractiveKeyboard() {
    QDialog *dial = new QDialog(this);
	TPresentation *p = new TPresentation(tApp.getLayout());
    QGridLayout *dialLay = new QGridLayout();
    dialLay->addWidget(p);
    
    dial->setLayout(dialLay);
    dial->adjustSize();
    
    dial->setModal(true);
    dial->show();
    p->setFocus();//Focus on THE widget for the keyevents
}



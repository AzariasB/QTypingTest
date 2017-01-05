/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */

/* 
 * File:   GamePage.cpp
 * Author: boutina
 * 
 * Created on 3 février 2016, 09:58
 */


#include "gamepage.h"

GamePage::~GamePage(){

}

GamePage::GamePage(QWidget* parent):
QWidget(parent),
interactiveKeyboard_(new QPushButton("Interactive keyboard")){
    setupWidgets();
    connectEvents();
}

void GamePage::setupWidgets() {
    QGridLayout *mainLay = new QGridLayout();
    
    mainLay->addWidget(interactiveKeyboard_);
    
    setLayout(mainLay);
}

void GamePage::connectEvents() {
    connect(interactiveKeyboard_,SIGNAL(clicked()),this,SLOT(showInteractiveKeyboard()));
}

void GamePage::showInteractiveKeyboard() {
    QDialog *dial = new QDialog(this);
    TPresentation *p = new TPresentation(TLayouts::getInstance());
    QGridLayout *dialLay = new QGridLayout();
    dialLay->addWidget(p);
    
    dial->setLayout(dialLay);
    dial->adjustSize();
    
    dial->setModal(true);
    dial->show();
    p->setFocus();//Focus on THE widget for the keyevents
}



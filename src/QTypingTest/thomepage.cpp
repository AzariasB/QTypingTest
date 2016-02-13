/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */
/* 
 * File:   THomePage.cpp
 * Author: boutina
 * 
 * Created on 16 décembre 2015, 15:27
 */



#include <qt5/QtCore/qvector.h>

#include "thomepage.h"

/**
 * Initiate the static vars
 */

THomePage::THomePage(QWidget *parent) :
QMainWindow(parent),
pagesButtons_(QVector<button_stack>()) {

    //For the test : create a new user
    //    TUser *timmy = new TUser("timmy");
    //    TUserManager& manager = TUserManager::getInstance();
    //    manager.setCurrentUser(timmy);

    ui.setupUi(this);
    connectEvents();

}

THomePage::~THomePage() {
}

void THomePage::connectEvents() {


    button_stack sHome = {
        ui.button_home,
        ui.page_home,
        new HomePage()
    };
    button_stack sLearn = {
        ui.button_learn,
        ui.page_learn,
        new LearnPage()
    };
    button_stack sGames = {
        ui.button_games,
        ui.page_games,
        new GamePage()
    };
    button_stack sStat = {
        ui.button_stats,
        ui.page_stats,
        nullptr // \todo : create statistics page
    };
    button_stack sPractice = {
        ui.button_practice,
        ui.page_practice,
        new PracticePage()
    };

    //Adding the structures to the array
    pagesButtons_ << sHome << sLearn << sGames << sPractice << sStat;

    //Iterate over the buttons-page couple
    for (auto it = pagesButtons_.begin(); it != pagesButtons_.end(); ++it) {
        button_stack s = *it;
        //If child is not nullptr create a simple layout with parent and add the child into it
        if (s.child) {
            QHBoxLayout *l = new QHBoxLayout(s.parent);
            l->addWidget(s.child);
        }
        if (!TUserManager::getInstance().getCurrentUser()) {
            s.triggerer->setEnabled(false);
        }

        connect(s.triggerer, &QPushButton::clicked, [ = ](){
            int i = ui.stack_main->indexOf(s.parent);
            ui.stack_main->setCurrentIndex(i);
        });
    }
    connect(&TUserManager::getInstance(),SIGNAL(userChanged(TUser*)),this, SLOT(updateUI(TUser*)));

}

void THomePage::updateUI(TUser* nwUser) {
    if (nwUser) {
        for (auto it = pagesButtons_.begin(); it != pagesButtons_.end(); ++it) {
            it->triggerer->setEnabled(true);
        }
    }
}

/* 
 * File:   THomePage.cpp
 * Author: boutina
 * 
 * Created on 16 décembre 2015, 15:27
 */



#include <qt5/QtCore/qlogging.h>

#include "THomePage.h"

THomePage::THomePage(QWidget *parent) :
QMainWindow(parent) {
    ui.setupUi(this);
    connectEvents();
}

THomePage::~THomePage() {
}

/**
 *  Connect the basics event for the main window,,
 *  namely change current stack index when button click
 * and connect event about the menu options 
 */
void THomePage::connectEvents() {
    QHash<QPushButton*, QWidget*> pagesButton;

    pagesButton[ui.button_home] = ui.page_home;
    pagesButton[ui.button_learn] = ui.page_learn;
    pagesButton[ui.button_games] = ui.page_games;
    pagesButton[ui.button_stats] = ui.page_stats;
    pagesButton[ui.button_practice] = ui.page_practice;

    QHashIterator<QPushButton*, QWidget*> it(pagesButton);
    while (it.hasNext()) {
        it.next();
        connect(it.key(), &QPushButton::clicked, [ = ](){
            int i = ui.stack_main->indexOf(it.value());
            ui.stack_main->setCurrentIndex(i);
        });
    }
}

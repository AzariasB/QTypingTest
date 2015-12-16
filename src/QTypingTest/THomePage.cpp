/* 
 * File:   THomePage.cpp
 * Author: boutina
 * 
 * Created on 16 décembre 2015, 15:27
 */



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
    QVector<QPushButton*> stackOrder(0);

    stackOrder.append(ui.button_home);
    stackOrder.append(ui.button_learn);
    stackOrder.append(ui.button_practice);
    stackOrder.append(ui.button_stats);
    stackOrder.append(ui.button_games);

    for (int i = 0; i < stackOrder.size(); i++) {
        connect(stackOrder[i], &QPushButton::clicked, [ = ](){ui.stack_main->setCurrentIndex(i);});
    }
}

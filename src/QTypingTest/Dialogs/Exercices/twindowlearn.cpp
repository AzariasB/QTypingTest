/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */

/* 
 * File:   TWindowLearn.cpp
 * Author: boutina
 * 
 * Created on 10 janvier 2016, 11:40
 */

#include "twindowlearn.h"

TWindowLearn::~TWindowLearn() {
}

void TWindowLearn::createToolBar() {
    TWindowTest::createToolBar();
}

QList<tln::TPage*> TWindowTest::createPages(QStringList model) {

    QList<tln::TPage*> lines;

    for (int i = 0; i < model.size(); i++) {
        tln::TPage *sLine = new tln::TPage(model[i]);
        connect(sLine, SIGNAL(endedPage(TResult*)), this, SLOT(nextPage(TResult*)));
        stackWidget_->addWidget(sLine);
        if (i > 0) {
            sLine->setEnabled(false); //Disable all to preventLine -> user to switch of lineEdit
        } else if (i == 0) {
            connect(sLine, SIGNAL(startedPage()), this, SLOT(beginExercice()));
            sLine->updateAsFirst();
        }
        lines << sLine;
    }


    centralLayout_->addWidget(stackWidget_);
    return lines;
}

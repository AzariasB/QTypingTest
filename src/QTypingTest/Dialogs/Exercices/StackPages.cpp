/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */
/* 
 * File:   StackPages.cpp
 * Author: boutina
 * 
 * Created on 20 janvier 2016, 09:58
 */


#include "StackPages.h"

StackPages::StackPages(QWidget *parent) :
QStackedWidget(parent),
toCopy_(QStringList()) {
}

StackPages::StackPages(const StackPages& orig) :
QStackedWidget(orig.parentWidget()),
toCopy_(QStringList()),
numberOfPages_(orig.getNumberOfPages()) {
    setupPages(orig.getText());
}

StackPages::StackPages(const QString &text, int numberOfPages = 1, QWidget *parent) :
QStackedWidget(parent),
toCopy_(QStringList()),
numberOfPages_(numberOfPages) {
    setupPages(text);
}

void StackPages::setupPages(QString wholeText) {
    QStringList model = factory::splitText(wholeText, numberOfPages_);

    for (int i = 0; i < model.size(); i++) {
        tln::TPage *mPage = new tln::TPage(model[i]);
        connect(mPage, SIGNAL(endedPage(TResult*)), this, SLOT(nextPage(TResult*)));

        if (i > 0) {
            mPage->setEnabled(false); //Disable all to preventLine -> user to switch of lineEdit
        } else if (i == 0) {
            connect(mPage, SIGNAL(startedPage()), this, SLOT(beginExercice()));
            mPage->updateAsFirst();
        }
        this->addWidget(mPage);
    }
}

StackPages::~StackPages() {
}


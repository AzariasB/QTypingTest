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


#include "tstackpages.h"

TStackPages::TStackPages(QWidget *parent) :
QStackedWidget(parent),
toCopy_(QStringList()) {
}

TStackPages::TStackPages(const TStackPages& orig) :
QStackedWidget(orig.parentWidget()),
toCopy_(QStringList()),
numberOfPages_(orig.numberOfPages()) {
    setupPages(orig.getText());
}

TStackPages::TStackPages(const QString &text, int numberOfPages, QWidget *parent) :
QStackedWidget(parent),
toCopy_(QStringList()),
numberOfPages_(numberOfPages) {
    setupPages(text);
}

void TStackPages::setupPages(QString wholeText) {
    QStringList model = factory::splitText(wholeText, numberOfPages_);

    for (int i = 0; i < model.size(); i++) {
        addPage(model[i],i == 0);
    }
}

void TStackPages::nextPage(TResult* previousScore) {
    emit pageEnded(previousScore);

    this->currentWidget()->setEnabled(false);
    this->currentPage_++;
    if (this->currentPage_ < this->count()) {
        this->setCurrentIndex(currentPage_);
        TPage *nwPage = currentPage();

        nwPage->setEnabled(true);
        nwPage->setFocus();
        nwPage->updateAsFirst();
    } else {//No more pages
        emit textFinished();
    }
}

void TStackPages::beginExercice() {
    emit exerciceStarted();
}

void TStackPages::keyPressed(QKeyEvent *ev) {
    TPage *p = currentPage();
    p->update(ev);
}

void TStackPages::addPage(QString pageText, bool isFirst) {
    TPage *mPage = new TPage(pageText);
    connect(mPage, SIGNAL(endedPage(TResult*)), this, SLOT(nextPage(TResult*)));

    if (!isFirst) {
        mPage->setEnabled(false); //Disable all to preventLine -> user to switch of lineEdit
    } else {
        connect(mPage, SIGNAL(startedPage()), this, SLOT(beginExercice()));
        mPage->updateAsFirst();
    }
    this->addWidget(mPage);
}

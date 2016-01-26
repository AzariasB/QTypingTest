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


//#include <qt5/QtCore/qlogging.h>
//#include <qt5/QtCore/qstringlist.h>

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

TStackPages::TStackPages(int numberOfPages, QWidget* parent):
QStackedWidget(parent),
toCopy_(QStringList()),
numberOfPages_(numberOfPages){
}


void TStackPages::setupPages(QString wholeText) {
    QStringList model = factory::splitText(wholeText, numberOfPages_);

    for (int i = 0; i < model.size(); i++) {
        addPage(model[i], i == 0);
    }
    //Set index to first
    if (!model.isEmpty())
        setCurrentIndex(0);
}

void TStackPages::nextPage(TResult* previousScore) {
    emit pageEnded(previousScore);
    if (!setFollowingPage()) {
        emit textFinished();
    }else{
        
    }
}

bool TStackPages::setFollowingPage() {
    if (currentIndex() + 1 >= count()) {
        return false;
    } else {
        this->currentWidget()->setEnabled(false);
        setCurrentIndex(currentIndex() + 1);
        TPage *nwPage = currentPage();

        nwPage->setEnabled(true);
        nwPage->setFocus();
        nwPage->updateAsFirst();
        return true;
    }
}

void TStackPages::beginExercice() {
    emit exerciceStarted();
}

void TStackPages::keyPressed(QKeyEvent *ev) {
    currentPage()->update(ev);
}

void TStackPages::addPage(QString pageText, bool isFirst) {
    TPage *mPage = new TPage(pageText);
    connect(mPage, SIGNAL(endedPage(TResult*)), this, SLOT(nextPage(TResult*)));

    if (!isFirst) {
        mPage->setEnabled(false); //Disable all to prevent user to switch of lineEdit
    } else {
        connect(mPage, SIGNAL(startedPage()), this, SLOT(beginExercice()));
        mPage->updateAsFirst();
    }
    this->addWidget(mPage);
}

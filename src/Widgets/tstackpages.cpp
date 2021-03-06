/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */
/* 
 * File:   StackPages.cpp
 * Author: boutina
 * 
 * Created on 20 janvier 2016, 09:58
 */


#include "tstackpages.h"

#include <QStringList>
#include <QList>
#include <QKeyEvent>
#include <QDebug>

#include "Data/tresult.h"
#include "Widgets/tpage.h"
#include "Util/factory.h"

TStackPages::TStackPages(QWidget *parent) :
QStackedWidget(parent){
}

TStackPages::TStackPages(const TStackPages& orig) :
QStackedWidget(orig.parentWidget()),
numberOfPages_(orig.numberOfPages()) {
    setupPages(orig.getText());
}

TPage *TStackPages::currentPage() const {
    return static_cast<TPage*> (this->currentWidget());
}

TStackPages::TStackPages(const QString &text, int numberOfPages, QWidget *parent) :
QStackedWidget(parent),
numberOfPages_(numberOfPages),
toCopy_(QStringList()) {
    setupPages(text);
}

TStackPages::TStackPages(int numberOfPages, QWidget* parent) :
QStackedWidget(parent),
numberOfPages_(numberOfPages),
toCopy_(QStringList()) {
}

void TStackPages::setupPages(const QString &wholeText) {
    QStringList model = factory::splitText(wholeText, numberOfPages_);
    for (int i = 0; i < model.size(); i++) {
        addPage(model[i] + " ", i == 0);
    }
    //Set index to first
    if (!model.isEmpty())
        setCurrentIndex(0);
}

void TStackPages::nextPage(const TResult &previousScore)
{
    emit pageEnded(previousScore);
    if (!nextPage()) {
        emit textFinished();
    } else {

    }
}

bool TStackPages::nextPage()
{
    if (currentIndex() + 1 >= count()) {
        return false;
    } else {
        this->currentWidget()->setEnabled(false);
        setCurrentIndex(currentIndex() + 1);
        TPage *nwPage = currentPage();

        nwPage->setEnabled(true);
       // nwPage->setFocus();
        nwPage->updateAsFirst();
        return true;
    }
}

void TStackPages::beginExercise() {
    emit exerciseStarted();
}

//void TStackPages::keyPressed(QKeyEvent *ev) {
    //currentPage()->update(ev);
//}

bool TStackPages::answerTyped(const QString &answer)
{
    if(answer.size() > 0)
    {
        return currentPage()->typingAnswer(answer);
    }
    return false;
}

void TStackPages::addPage(const QString &pageText, bool isFirst) {
    TPage *mPage = new TPage(pageText);
	connect(mPage, SIGNAL(endedPage(TResult)), this, SLOT(nextPage(TResult)));

    if (!isFirst) {
        mPage->setEnabled(false); //Disable all to prevent user to switch of lineEdit
    } else {
        connect(mPage, SIGNAL(startedPage()), this, SLOT(beginExercise()));
        mPage->updateAsFirst();
    }
    this->addWidget(mPage);
}

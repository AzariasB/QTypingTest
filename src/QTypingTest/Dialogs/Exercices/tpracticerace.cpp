/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */

/* 
 * File:   TPracticerace.cpp
 * Author: boutina
 * 
 * Created on 21 janvier 2016, 15:27
 */

#include "tpracticerace.h"

TPracticeRace::TPracticeRace(int timeStart,QWidget *parent) :
TWindowTest(TExercice::generateExercice(TExercice::PRACTICING_RACE), parent) {
    setupPage(timeStart);
}

TPracticeRace::TPracticeRace(TExercice* exercice,int timeStart, QWidget* parent) :
TWindowTest(exercice, parent){
    setupPage(timeStart);
}

TPracticeRace::TPracticeRace(const TPracticeRace& orig) :
TWindowTest(orig.cExercice() , orig.parentWidget()) {
    setupPage();
}

void TPracticeRace::createPage() {
    QString ex = exercice()->buildExercice();
    pages_.addPage(ex);
}

void TPracticeRace::setupPage(int timeStart) {
    //HACK for testing => shortucut to end the exercice
    QShortcut *endShortcut = new QShortcut(this);
    endShortcut->setKey(Qt::CTRL + Qt::Key_E);

    connect(endShortcut, &QShortcut::activated, [ = ](){
        emit pages_.pageEnded(new TResult());
    });
    //end of hacks

    TWindowTest::setTimeIncrement(-1);
    TWindowTest::setTimerEnd(0.f);

    connect(this,SIGNAL(timerEnded()),this,SLOT(stopRun()));


    topToolbar_.setLCDDisplayValue(timeStart);
    connect(&pages_, SIGNAL(pageEnded(TResult*)), this, SLOT(createPage()));
    QString ex = exercice()->buildExercice();
    pages_.addPage(ex, true);
}

void TPracticeRace::stopRun()
{
    addResult(pages_.currentPage()->getResult());
    emit pages_.textFinished();
}

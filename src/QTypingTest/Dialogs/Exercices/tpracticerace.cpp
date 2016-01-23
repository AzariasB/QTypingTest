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

TPracticeRace::TPracticeRace(QWidget *parent) :
TWindowTest(parent),
generator_(TExercice(TExercice::PRACTICING, true)) {
    setupPage();
}

TPracticeRace::TPracticeRace(TExercice* exercice, QWidget* parent) :
TWindowTest(parent),
generator_(*exercice) {

    setupPage();
}

TPracticeRace::TPracticeRace(const TPracticeRace& orig) :
TWindowTest(orig.parentWidget()),
generator_(orig.exerciceGenerator()) {
    setupPage();
}

void TPracticeRace::createPage(TResult* prevPageRes) {
    QString ex = generator_.buildExercice();
    pages_.addPage(ex);
    pages_.setFollowingPage();
    updateToolbarProgression();
}

void TPracticeRace::setupPage() {

    //HACK for testing => shortucut to end the exercice
    QShortcut *endShortcut = new QShortcut(this);
    endShortcut->setKey(CTRL + Key_E);

    connect(endShortcut, &QShortcut::activated, [ = ](){
        emit pages_.pageEnded(new TResult());
    });
    //end of hacks


    //TODO : change 60 to a varialbe int
    topToolbar_.setLCDDisplayValue(60.f);
    connect(&pages_, SIGNAL(pageEnded(TResult*)), this, SLOT(createPage()));
    QString ex = generator_.buildExercice();
    pages_.addPage(ex, true);
    updateToolbarProgression();
}

void TPracticeRace::updateClock() {
    double res = topToolbar_.incrementTimer(-1);
    if(res <= 0.f){
        emit pages_.textFinished();
    }
}

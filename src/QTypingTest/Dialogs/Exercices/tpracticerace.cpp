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
generator_(TExercice(TExercice::PRACTICING,true)){
    handleEvents();
}

TPracticeRace::TPracticeRace(TExercice* exercice, QWidget* parent) :
TWindowTest(parent),
generator_(*exercice) {
    handleEvents();
}

TPracticeRace::TPracticeRace(const TPracticeRace& orig) :
TWindowTest(orig.parentWidget()),
generator_(orig.exerciceGenerator()) {
    handleEvents();
}

void TPracticeRace::updateClock() {
    topToolbar_.incrementTimer(-1);
}

void TPracticeRace::handleEvents() {
    connect(&pages_, SIGNAL(pageEnded(TResult*)), this, SLOT(createPage(TResult*)));
}

void TPracticeRace::createPage(TResult* prevPageRes) {
    results_ << prevPageRes;
    pages_.addPage(generator_.buildExercice());
    //Trigger changin page
}


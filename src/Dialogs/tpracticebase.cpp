/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */

/* 
 * File:   TPractice.cpp
 * Author: boutina
 * 
 * Created on 24 janvier 2016, 11:55
 */

#include "tpracticebase.h"

#include "Data/texercice.h"

TPracticeBase::TPracticeBase(QWidget* parent)
: TWindowTest(TExercice::generateExercice(TExercice::PRACTICING), parent){
    setupText();
}

TPracticeBase::TPracticeBase(TExercice &generator, QWidget* parent) :
TWindowTest(generator, parent){
    setupText();
}

void TPracticeBase::setupText() {
    pages_.setNumberOfPages(2);
	pages_.setupPages(exercice().buildExercice());
    updateToolbarProgression();
}

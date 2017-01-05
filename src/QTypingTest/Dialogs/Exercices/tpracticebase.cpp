/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */

/* 
 * File:   TPractice.cpp
 * Author: boutina
 * 
 * Created on 24 janvier 2016, 11:55
 */

#include "tpracticebase.h"

TPracticeBase::TPracticeBase(QWidget* parent)
: TWindowTest(parent),
generator_(TExercice::generateExercice(TExercice::PRACTICING)) {
    setupText();
}

TPracticeBase::TPracticeBase(TExercice* generator, QWidget* parent) :
TWindowTest(parent),
generator_(generator) {
    setupText();
}

TPracticeBase::TPracticeBase(const TPracticeBase& orig) :
TWindowTest(orig.parentWidget()),
generator_(orig.getGenerator()) {
    setupText();
}

void TPracticeBase::setupText() {
    pages_.setNumberOfPages(2);
    pages_.setupPages(generator_->buildExercice());
    updateToolbarProgression();
}

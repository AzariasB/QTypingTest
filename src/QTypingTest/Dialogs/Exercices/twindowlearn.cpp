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

TWindowLearn::TWindowLearn(TExercice* ex, QWidget* parent) :
TWindowTest(ex->buildExercice(),ex, parent),
instructions_(new TPresentation(TLayout::getInstance(),ex->getLearningLetters())) {
    addInstructions(ex);
}

TWindowLearn::TWindowLearn(QString content, QWidget* parent) :
TWindowTest(content, 1, TExercice::generateExercice(TExercice::LEARNING), parent),
instructions_(new TPresentation(TLayout::getInstance())) {
    addInstructions();
}

TWindowLearn::TWindowLearn(TExercice* ex, int numberOfPages, QWidget* parent) :
TWindowTest(ex->buildExercice(), numberOfPages,TExercice::generateExercice(TExercice::LEARNING),  parent) {
}

void TWindowLearn::addInstructions(TExercice *exo) {
    QStackedLayout *mainLayout = layout();
    mainLayout->insertWidget(0, instructions_);
    mainLayout->setCurrentIndex(0);
    instructions_->setFocus();
    if(exo){
        topToolbar_.setAdditionnalText("<b>Learning letters :</b>" + exo->getLearningLetters() );
    }
    connect(instructions_,SIGNAL(allCopied()),this,SLOT(endOfTraining()));
}

void TWindowLearn::endOfTraining() {
    layout()->removeWidget(instructions_);
    edit_.setFocus();
    adjustSize();
}

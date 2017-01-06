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
TWindowTest(ex->buildExercice(), parent),
instructions_(new TPresentation(TLayout::getInstance(),ex->getLearningLetters())) {
    addInstructions();
}

TWindowLearn::TWindowLearn(QString content, QWidget* parent) :
TWindowTest(content, 1, parent),
instructions_(new TPresentation(TLayout::getInstance())) {
    addInstructions();
}

TWindowLearn::TWindowLearn(TExercice* ex, int numberOfPages, QWidget* parent) :
TWindowTest(ex->buildExercice(), numberOfPages, parent) {
}

void TWindowLearn::addInstructions() {
    QStackedLayout *mainLayout = layout();
    mainLayout->insertWidget(0, instructions_);
    mainLayout->setCurrentIndex(0);
    instructions_->setFocus();
    connect(instructions_,SIGNAL(allCopied()),this,SLOT(endOfTraining()));
}

void TWindowLearn::endOfTraining() {
    layout()->removeWidget(instructions_);
    layout()->currentWidget()->setFocus();
    adjustSize();
}

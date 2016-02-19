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

#include <qt5/QtCore/qlogging.h>

#include "twindowlearn.h"

TWindowLearn::TWindowLearn(TExercice* ex, QWidget* parent) :
TWindowTest(ex->buildExercice()),
instructions_(new TPresentation("fr")) {
    delete layout();
    QLabel *lab = new QLabel("hé hé");
    QGridLayout *mainLay = new QGridLayout();
    mainLay->addWidget(lab);
    setLayout(mainLay);
}

TWindowLearn::TWindowLearn(TExercice* ex, int numberOfPages, QWidget* parent) :
TWindowTest(ex->buildExercice(), numberOfPages, parent) {
}

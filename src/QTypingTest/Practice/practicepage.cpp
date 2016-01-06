/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */

/* 
 * File:   PracticePage.cpp
 * Author: boutina
 * 
 * Created on 6 janvier 2016, 10:15
 */


#include "practicepage.h"

PracticePage::PracticePage(QWidget *parent) : QWidget(parent),
practiceAgainstTime_(tr("Against time")),
practiceDefault_(tr("Normal")),
practiceImprove_(tr("Improve")),
practiceText_(tr("Text")) {
    setupLayout();
}

PracticePage::PracticePage(const PracticePage& orig) :
QWidget(orig.parentWidget()),
practiceAgainstTime_(tr("Against time")),
practiceDefault_(tr("Normal")),
practiceImprove_(tr("Improve")),
practiceText_(tr("Text")) {
    setupLayout();
}

void PracticePage::setupLayout() {
    QGridLayout *centerLayout = new QGridLayout(this);

    practiceAgainstTime_.setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
    practiceDefault_.setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
    practiceImprove_.setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
    practiceText_.setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
    
    practiceImprove_.setEnabled(false);
    practiceText_.setEnabled(false);
    
    centerLayout->addWidget(&practiceAgainstTime_, 0, 0);
    centerLayout->addWidget(&practiceDefault_, 0, 1);
    centerLayout->addWidget(&practiceImprove_, 1, 0);
    centerLayout->addWidget(&practiceText_, 1, 1);

}



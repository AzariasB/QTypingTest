/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */

/* 
 * File:   Toolbar.cpp
 * Author: boutina
 * 
 * Created on 20 janvier 2016, 09:58
 */

#include <qt5/QtCore/qnamespace.h>
#include <qt5/QtCore/qlogging.h>

#include "ttoolbar.h"

TToolbar::TToolbar(QWidget *parent) :
QWidget(parent){
    setupToolbar();
}

TToolbar::TToolbar(const TToolbar& orig) :
QWidget(orig.parentWidget()) {
    setupToolbar();
}

void TToolbar::setupToolbar() {
    QHBoxLayout *toolbarLayout = new QHBoxLayout();

    pageProgression_ = new QLabel("");

    pauseButton_ = new QCheckBox(); //Change with an icon
    pauseButton_->setCheckable(true);
    pauseButton_->setIcon(QIcon("etc/pause.png"));
    pauseButton_->setFocusPolicy(Qt::NoFocus);


    connect(pauseButton_, SIGNAL(clicked()), this, SLOT(pauseTimer()));

    LCDtimer_ = new QLCDNumber();
    LCDtimer_->setSegmentStyle(QLCDNumber::Outline);
    LCDtimer_->setFrameStyle(QFrame::NoFrame);
    LCDtimer_->setPalette(Qt::black);
    QTime t(0,0,0);
    incrementTimer(0);

    QSpacerItem *space = new QSpacerItem(300, 0);

    toolbarLayout->addWidget(pageProgression_);
    toolbarLayout->addWidget(pauseButton_);
    toolbarLayout->addWidget(LCDtimer_);
    toolbarLayout->addItem(space);

    this->setLayout(toolbarLayout);

}

void TToolbar::pauseTimer() {    
    bool pause = pauseButton_->isChecked();
    qDebug() << pause;
    if (!pause) {
        pauseButton_->setIcon(QIcon("etc/pause.png"));
    } else {
        pauseButton_->setIcon(QIcon("etc/play.png"));
    }
    emit pauseClicked();
}

double TToolbar::incrementTimer(int increment) {
    secondsValue_ =  secondsValue_ + increment;
    QTime t(0,0,0);
    t = t.addSecs(secondsValue_);
    LCDtimer_->display(t.toString("mm:ss"));
    return secondsValue_;
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Toolbar.cpp
 * Author: boutina
 * 
 * Created on 20 janvier 2016, 09:58
 */

#include <qt5/QtCore/qnamespace.h>

#include "ttoolbar.h"

TToolbar::TToolbar(QWidget *parent) :
QWidget(parent),
timer_(new QTimer()) {
    setupToolbar();
}

TToolbar::TToolbar(const TToolbar& orig) :
QWidget(orig.parentWidget()),
timer_(new QTimer()) {
    setupToolbar();
}

void TToolbar::setupToolbar() {
    timer_->setSingleShot(false);

    //TODO : start only when the exercice start
    timer_->start(1000);

    QHBoxLayout *toolbarLayout = new QHBoxLayout();

    pageProgression_ = new QLabel("");

    pauseButton_ = new QPushButton(); //Change with an icon
    pauseButton_->setIcon(QIcon("etc/pause.png"));
    pauseButton_->setAutoDefault(false);
    pauseButton_->setFocusPolicy(Qt::NoFocus);


    connect(pauseButton_, SIGNAL(clicked()), this, SLOT(pauseTimer()));

    LCDtimer_ = new QLCDNumber();
    LCDtimer_->setSegmentStyle(QLCDNumber::Filled);

    QSpacerItem *space = new QSpacerItem(300, 0);

    toolbarLayout->addWidget(pageProgression_);
    toolbarLayout->addWidget(pauseButton_);
    toolbarLayout->addWidget(LCDtimer_);
    toolbarLayout->addItem(space);

    this->setLayout(toolbarLayout);

    connect(timer_, SIGNAL(timeout()), this, SLOT(updateTimer()));
}

void TToolbar::pauseTimer() {
    isInPause = !isInPause;
    if (isInPause) {
        timer_->start();
        pauseButton_->setIcon(QIcon("etc/pause.png"));
    } else {
        pauseButton_->setIcon(QIcon("etc/play.png"));
        timer_->stop();
    }
    emit pauseContinue(isInPause);
}

void TToolbar::updateTimer() {
    if (!isInPause) {
        emit timeout();
    }
}

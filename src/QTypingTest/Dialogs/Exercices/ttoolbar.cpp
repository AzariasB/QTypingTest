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
    LCDtimer_->setSegmentStyle(QLCDNumber::Filled);

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

void TToolbar::incrementTimer(int increment) {
    double val =  LCDtimer_->value() + increment;
    LCDtimer_->display(QString("%1").arg(val));
}

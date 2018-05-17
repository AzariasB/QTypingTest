/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */

/* 
 * File:   Toolbar.cpp
 * Author: boutina
 * 
 * Created on 20 janvier 2016, 09:58
 */

#include "ttoolbar.h"

#include <QCheckBox>
#include <QLCDNumber>
#include <QLabel>
#include <QTimer>
#include <QTime>
#include <QPushButton>
#include <QSpacerItem>
#include <QHBoxLayout>
#include <qnamespace.h>
#include <QDebug>

TToolbar::TToolbar(QWidget *parent) :
QWidget(parent),
pauseButton_(new QPushButton("Pause") ),
LCDtimer_(new QLCDNumber() ),
pageProgression_(new QLabel("")),
additionnalInfos_(new QLabel(""))
{
    setupToolbar();
}


void TToolbar::setupToolbar() {
    QHBoxLayout *toolbarLayout = new QHBoxLayout();

    pauseButton_->setCheckable(true);
    pauseButton_->setIcon(QIcon("etc/pause.png"));
    pauseButton_->setFocusPolicy(Qt::NoFocus);


    connect(pauseButton_, SIGNAL(clicked()), this, SLOT(pauseTimer()));

    LCDtimer_->setSegmentStyle(QLCDNumber::Outline);
    LCDtimer_->setFrameStyle(QFrame::NoFrame);
    LCDtimer_->setPalette(Qt::black);
    QTime t(0,0,0);
    incrementTimer(0);

    QSpacerItem *space = new QSpacerItem(500, 0);

    toolbarLayout->addWidget(pageProgression_);
    toolbarLayout->addWidget(pauseButton_);
    toolbarLayout->addWidget(LCDtimer_);
    toolbarLayout->addWidget(additionnalInfos_);
    toolbarLayout->addItem(space);

    this->setLayout(toolbarLayout);

}

void TToolbar::setProgression(const QString &text)
{
    pageProgression_->setText(text);
}

void TToolbar::setAdditionnalText(const QString &text)
{
    additionnalInfos_->setText(text);
}

void TToolbar::pauseTimer() {    
    bool pause = pauseButton_->isChecked();
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

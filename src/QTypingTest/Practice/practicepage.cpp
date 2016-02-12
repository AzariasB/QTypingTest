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

    practiceAgainstTime_.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    practiceDefault_.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    practiceImprove_.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    practiceText_.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

    practiceImprove_.setEnabled(false);

    centerLayout->addWidget(&practiceAgainstTime_, 0, 0);
    centerLayout->addWidget(&practiceDefault_, 0, 1);
    centerLayout->addWidget(&practiceImprove_, 1, 0);
    centerLayout->addWidget(&practiceText_, 1, 1);

    connectEvents();
}

void PracticePage::connectEvents() {
    connect(&practiceAgainstTime_, &QPushButton::clicked, this, [=](){
        this->startExercice(new TPracticeRace(60,this));
    });
    connect(&practiceDefault_,&QPushButton::clicked,this,[=](){
        this->startExercice(new TPracticeBase(this));
    });
    
    connect(&practiceText_,&QPushButton::clicked,this,[=](){
        this->startExercice(new TPracticeText(this));
    });
}

void PracticePage::startExercice(TWindowTest *exercice) {
    if (currentDialog_ != nullptr) {
        qDebug() << "Already running another exercice";
        //Already running
    } else {
        currentDialog_ = exercice;
        currentDialog_->show();
        connect(exercice, &TWindowTest::endOfExercice, this, &PracticePage::saveExerciceResult);
        connect(exercice,SIGNAL(closed()), this, SLOT(resetExercice()));
        
    }
}

void PracticePage::saveExerciceResult(TResult* res, QTime time) {
    //Save result and time somewhere
    QMessageBox::information(currentDialog_, "Exercice finished", res->getResume() + 
        "<br/> Realized in :" + time.toString("mm:ss"));
    resetExercice();
}

void PracticePage::resetExercice() {
    if(currentDialog_){
        currentDialog_->hide();
        currentDialog_->disconnect();
        currentDialog_ = nullptr;
    }
}

/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */

/* 
 * File:   PracticePage.cpp
 * Author: boutina
 * 
 * Created on 6 janvier 2016, 10:15
 */



#include "practicepage.h"

#include "Dialogs/twindowtest.h"
#include "Dialogs/tpracticerace.h"
#include "Dialogs/tpracticebase.h"
#include "Dialogs/tpracticetext.h"
#include "Dialogs/timprove.h"
#include "Data/tusermanager.h"
#include "tapplication.h"

PracticePage::PracticePage(QWidget *parent) : QWidget(parent),
practiceAgainstTime_(tr("Against time")),
practiceDefault_(tr("Normal")),
practiceImprove_(tr("Improve")),
practiceText_(tr("Text")),
um(tApp.getUserManager()){
    setupLayout();
}

PracticePage::PracticePage(const PracticePage& orig) :
QWidget(orig.parentWidget()),
practiceAgainstTime_(tr("Against time")),
practiceDefault_(tr("Normal")),
practiceImprove_(tr("Improve")),
practiceText_(tr("Text")),
um(tApp.getUserManager()){
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
    connect(&practiceAgainstTime_, &QPushButton::clicked, this, [ = ](){
        this->startExercise(new TPracticeRace(60, this));
    });
    connect(&practiceDefault_, &QPushButton::clicked, this, [ = ](){
        this->startExercise(new TPracticeBase(this));
    });

    connect(&practiceText_, &QPushButton::clicked, this, [ = ](){
        this->startExercise(new TPracticeText(this));
    });

    connect(&practiceImprove_, &QPushButton::clicked, this, [ = ](){
        this->startExercise(new TImprove(this));
    });

	connect(&um, SIGNAL(userChanged(TUser&)), this, SLOT(userChanges(TUser&)));
}

void PracticePage::startExercise(TWindowTest *exercise) {
    if (currentDialog_ != nullptr) {
        qWarning() << "Already running another exercise";
        //Already running
    } else {
        currentDialog_ = exercise;
        currentDialog_->show();
        connect(exercise, &TWindowTest::endOfExercise, this, &PracticePage::saveExerciseResult);
        connect(exercise, SIGNAL(closed()), this, SLOT(resetExercise()));

    }
}

void PracticePage::saveExerciseResult(TResult& res, QTime time) {
	um.saveUsers();
	QMessageBox::information(currentDialog_, "Exercise finished", res.getResume() +
            "<br/> Realized in :" + time.toString("mm:ss"));
    resetExercise();
}

void PracticePage::resetExercise() {
    if (currentDialog_) {
        currentDialog_->hide();
        currentDialog_->disconnect();
        currentDialog_ = nullptr;
    }
}

void PracticePage::updateImproveButton(TUser &nwUser) {
	const TStats &stats = nwUser.getStatistics();
	practiceImprove_.setEnabled(!stats.isEmpty());
}

void PracticePage::userChanges(TUser& nwUser) {
	updateImproveButton(nwUser);
	connect(&nwUser, SIGNAL(statsChanged(TUser&)), this, SLOT(updateImproveButton(TUser&)));
}

void PracticePage::userDisconnects()
{
	practiceImprove_.setEnabled(false);
}

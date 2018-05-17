/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */

/* 
 * File:   TPracticerace.cpp
 * Author: boutina
 * 
 * Created on 21 janvier 2016, 15:27
 */

#include "tpracticerace.h"

#include "Widgets/tpage.h"
#include "Data/texercise.h"
#include "Data/tresult.h"
#include <QShortcut>
#include <QStackedLayout>

TPracticeRace::TPracticeRace(int timeStart,QWidget *parent) :
TWindowTest(TExercise::generateExercise(TExercise::PRACTICING_RACE), parent) {
    setupPage(timeStart);
}

TPracticeRace::TPracticeRace(TExercise &exercise,int timeStart, QWidget* parent) :
TWindowTest(exercise, parent){
    setupPage(timeStart);
}


void TPracticeRace::createPage() {
	QString ex = exercise().buildExercise();
    pages_.addPage(ex);
}

void TPracticeRace::setupPage(int timeStart) {
    //HACK for testing => shortucut to end the exercise
	QShortcut endShortcut(this);
	endShortcut.setKey(Qt::CTRL + Qt::Key_E);

	connect(&endShortcut, &QShortcut::activated, [ = ](){
		TResult res;
		emit pages_.pageEnded(res);
    });
    //end of hacks

    TWindowTest::setTimeIncrement(-1);
    TWindowTest::setTimerEnd(0.f);

    connect(this,SIGNAL(timerEnded()),this,SLOT(stopRun()));


    topToolbar_.setLCDDisplayValue(timeStart);
	connect(&pages_, SIGNAL(pageEnded(TResult)), this, SLOT(createPage()));
	QString ex = exercise().buildExercise();
    pages_.addPage(ex, true);
}

void TPracticeRace::stopRun()
{
	addResult(pages_.currentPage()->getResult());
	TWindowTest::exerciseFinished();
	//emit pages_.textFinished();
}

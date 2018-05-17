/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */
/* 
 * File:   LearnPage.cpp
 * Author: boutina
 * 
 * Created on 17 décembre 2015, 17:58
 */

#include "learnpage.h"

#include "Data/tlayout.h"
#include "Data/texercise.h"
#include "Data/tresult.h"
#include "Data/tusermanager.h"
#include "Util/htmlhelper.h"
#include "Dialogs/twindowlearn.h"
#include "tapplication.h"

#include <QPushButton>
#include <QMessageBox>
#include <QTime>
#include <QDebug>
#include <QScrollArea>
#include <QGridLayout>

LearnPage::LearnPage(QWidget* parent) :
QWidget(parent),
um(tApp.getUserManager()),
learnButtons_(QVector<QPushButton*>())
{
    this->createPractice();
}

void LearnPage::createPractice() {
    QGridLayout *main = new QGridLayout(this);

    QWidget *scrollWidget = new QWidget();
    scrollWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QScrollArea *scroll = new QScrollArea();
    scrollWidget->setMinimumSize(scroll->size());


    learnButtonsLayout_ = new QGridLayout(scrollWidget);
    createButtons(learnButtonsLayout_);

    scroll->setWidget(scrollWidget);
    main->addWidget(scroll);
	connect(&um, SIGNAL(userChanged(TUser&)), this, SLOT(updateUserProgression(TUser&)));
	connect(&um, SIGNAL(userDiconnected()), this, SLOT(resetUserProgressoin()) );
}

void LearnPage::createButtons(QGridLayout *lay) {
    QStringList l = tApp.getLayout().getLearningCouples();

    int buttonWidth = 100;

    int col = 0,
            row = 0,
            index = 0;

    int maxCols = (this->size().width() / buttonWidth) - 1;

    //Create a button for each existing string and add it to the layout
    for (auto it = l.begin(); it != l.end(); ++it, index++) {
        QPushButton *button = new QPushButton((*it).replace('&', "&&"));

        connect(button, SIGNAL(clicked()), this, SLOT(lauchExercise()));
        //        button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        button->setMinimumHeight(100);
        button->setMinimumWidth(buttonWidth);
        button->setContentsMargins(1, 1, 1, 1);
        button->setFocusPolicy(Qt::NoFocus);

        int lastUserExercise = -1;
		if (um.isUserConnected()) {
			lastUserExercise = um.getCurrentUser().getProgression().getLastExericeIndex();
        }

        if (index > lastUserExercise) {
            button->setEnabled(false);
        }

        learnButtons_ << button;

        lay->addWidget(button, row, col);


        col++;
        if (col >= maxCols) {
            row++;
            col = 0;
        }

    }
}



void LearnPage::lauchExercise() {

    if (QPushButton * trigger = dynamic_cast<QPushButton*> (sender())) {

        int lastLetterIndex = learnButtons_.indexOf(trigger);
        if (lastLetterIndex == -1) {//Not found in the list ... that is weird !
            QMessageBox::critical(this, "Exercise not existing", "The exercise you are trying to do does not exist");
        } else if (currentProgression_ != -1) {
            //An exercise is currently running
            QMessageBox::critical(this, "Exercise already running", "There is alerady a running exercise");
        } else {
            currentProgression_ = lastLetterIndex;
            QString lastLetter = tApp.getLayout().getLettersAt(lastLetterIndex);
            QString allLetters = tApp.getLayout().getAllLettersTo(lastLetterIndex + 1);
            TExercise ex = TExercise::generateExercise(TExercise::LEARNING, lastLetter, allLetters);


            testWindow_ = new TWindowLearn(ex, this);

            connect(testWindow_, SIGNAL(closed()), this, SLOT(resetExercise()));
            //Connect only once the test dialog
			connect(testWindow_, SIGNAL(endOfExercise(TResult&, QTime)), this, SLOT(endExercise(TResult&, QTime)));
            testWindow_->show();
            testWindow_->focusWidget();
        }
    }//else ..nothing to do !
}

void LearnPage::endExercise(TResult& exerciseResult, const QTime &timeEx) {
    testWindow_->hide();
    QString time = QString("Made in : %1").arg(timeEx.toString("mm:ss"));

	if(!um.isUserConnected())//nothing is done then ...
		return;
    // Min time and min wpm may change depending on overall difficulty
	if (exerciseResult.getWPM() < 30) {
		QMessageBox::information(this, "Too long", "You didn't made in time.<br/>" + exerciseResult.getResume() +"<br/>" + time);
    } else {


		TProgression &curProgr = um.getCurrentUser().getProgression();
		if (currentProgression_ == curProgr.getLastExericeIndex())
			curProgr.avdvanceExIndex();

        QString text = QString("Congratulations, you finished the exercise !<br/>"
				"Results are :<br/>") + exerciseResult.getResume() + "<br/>" + time;

        QMessageBox::information(this, "End of exercise", text);
        //Unlock the last button if exercise succeeded


		if (curProgr.getLastExericeIndex() < learnButtons_.size()) {
			learnButtons_.at(curProgr.getLastExericeIndex())->setEnabled(true);
        } else {
            //Finished the game !
            QMessageBox::information(this, "End of the game", "Congratulation, you completed the game.");
            /*
             You get a firework,
             * you get a firework;
			 * EVERYBODY gets a firework !!!
             */
        }
    }

    resetExercise();
}

void LearnPage::resetExercise() {
    if (testWindow_) {
        testWindow_->hide();
        testWindow_->disconnect();
        testWindow_ = nullptr;
    }
    currentProgression_ = -1;
}

void LearnPage::updateUserProgression(TUser &nwUser) {
	int lastUserExercise = nwUser.getProgression().getLastExericeIndex();
	for (int i = 0; i <= lastUserExercise && i < learnButtons_.size(); i++) {
		learnButtons_[i]->setEnabled(true);
	}

	for (int i = lastUserExercise + 1; i < learnButtons_.size(); i++) {
		learnButtons_[i]->setEnabled(false);
	}
}

void LearnPage::resetUserProgressoin()
{
	for (QPushButton *elem : learnButtons_) {
		elem->setEnabled(false);
	}

}

void LearnPage::resizeEvent(QResizeEvent*) {
    if (learnButtonsLayout_) {
       // \todo : fits the button to the scrollbar to avoid horizontal scrolling
    }
}

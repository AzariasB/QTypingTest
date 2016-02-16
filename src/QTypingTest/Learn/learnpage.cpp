/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */
/* 
 * File:   LearnPage.cpp
 * Author: boutina
 * 
 * Created on 17 décembre 2015, 17:58
 */



#include <qt5/QtCore/qlogging.h>
#include <qt5/QtWidgets/qwidget.h>

#include "learnpage.h"

LearnPage::LearnPage(QWidget* parent) :
QWidget(parent),
learnButtons_(QVector<QPushButton*>()) {
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
    connect(&TUserManager::getInstance(), SIGNAL(userChanged(TUser*)), this, SLOT(updateUserProgression(TUser*)));
}

void LearnPage::createButtons(QGridLayout *lay) {
    QStringList l = practice_.getLetterList();

    int buttonWidth = 100;

    int col = 0,
            row = 0,
            index = 0;

    int maxCols = (this->size().width() / buttonWidth) - 1;

    //Create a button for each existing string and add it to the layout
    for (auto it = l.begin(); it != l.end(); ++it, index++) {
        QPushButton *button = new QPushButton((*it).replace('&', "&&"));

        connect(button, SIGNAL(clicked()), this, SLOT(lauchExercice()));
        //        button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        button->setMinimumHeight(100);
        button->setMinimumWidth(buttonWidth);
        button->setContentsMargins(1, 1, 1, 1);
        button->setFocusPolicy(Qt::NoFocus);

        TUser *currentUser = TUserManager::getInstance().getCurrentUser();
        int lastUserExercice = -1;
        if (currentUser) {
            lastUserExercice = currentUser->getProgression()->getLastExericeIndex();
        }

        if (index > lastUserExercice) {
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



void LearnPage::lauchExercice() {

    if (QPushButton * trigger = dynamic_cast<QPushButton*> (sender())) {

        int lastLetterIndex = learnButtons_.indexOf(trigger);
        if (lastLetterIndex == -1) {//Not found in the list ... that is weird !
            QMessageBox::critical(this, "Exercice not existing", "The exercice you are trying to do does not exist");
        } else if (currentProgression_ != -1) {
            //An exercice is currently running
            QMessageBox::critical(this, "Exercice already running", "There is alerady a running exercice");
        } else {
            currentProgression_ = lastLetterIndex;
            QString lastLetter = practice_.getLettersAt(lastLetterIndex);
            QString allLetters = practice_.getAllLettersTo(lastLetterIndex + 1);
            TExercice *ex = new TExercice(TExercice::LEARNING, lastLetter, allLetters);


            testWindow_ = new TWindowLearn(ex, this);

            connect(testWindow_, SIGNAL(closed()), this, SLOT(resetExercice()));
            //Connect only once the test dialog
            connect(testWindow_, SIGNAL(endOfExercice(TResult*, QTime)), this, SLOT(endExercice(TResult*, QTime)));
            testWindow_->show();
            testWindow_->focusWidget();
        }
    }//else ..nothing to do !
}

void LearnPage::endExercice(TResult* exerciceResult, QTime timeEx) {
    // \todo : check if the result is good enought to set the advance in the progression (Azarias)
    testWindow_->hide();

    if ((timeEx.msecsSinceStartOfDay() / 1000.f) > 120) {
        QMessageBox::information(this, "Too long", "You didn't made in time.");
    } else {
        TProgression *curProgr = TUserManager::getInstance().getCurrentUser()->getProgression();
        if (currentProgression_ == curProgr->getLastExericeIndex())
            curProgr->avdvanceExIndex();

        QString text = QString("Congratulations, you finished the exercice !<br/>"
                "Results are :<br/>") + exerciceResult->getResume();

        QMessageBox::information(this, "End of exercice", text);
        //Unlock the last button if exercice succeeded


        if (curProgr->getLastExericeIndex() < learnButtons_.size()) {
            learnButtons_.at(curProgr->getLastExericeIndex())->setEnabled(true);
        } else {
            //Finished the game !
            QMessageBox::information(this, "End of the game", "Congratulation, you completed the game.");
            /*
             You get a firework,
             * you get a firework;
             * EVERYBODY gets a fireworks !!!
             */
        }
    }

    resetExercice();
}

void LearnPage::resetExercice() {
    if (testWindow_) {
        testWindow_->hide();
        testWindow_->disconnect();
        testWindow_ = nullptr;
    }
    currentProgression_ = -1;
}

void LearnPage::updateUserProgression(TUser* nwUser) {
    if (nwUser) {
        int lastUserExercice = nwUser->getProgression()->getLastExericeIndex();
        for (int i = 0; i <= lastUserExercice && i < learnButtons_.size(); i++) {
            learnButtons_[i]->setEnabled(true);
        }

        for (int i = lastUserExercice + 1; i < learnButtons_.size(); i++) {
            learnButtons_[i]->setEnabled(false);
        }
    } else {
        for (QPushButton *elem : learnButtons_) {
            elem->setEnabled(false);
        }

    }
}

void LearnPage::resizeEvent(QResizeEvent* ev) {
    if (learnButtonsLayout_) {
       
    }
}

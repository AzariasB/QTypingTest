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



#include "learnpage.h"

LearnPage::LearnPage(QWidget* parent) :
QWidget(parent),
learnButtons_(QVector<QPushButton*>()) {
    this->createPractice();
}

void LearnPage::createPractice() {
    QGridLayout *main = new QGridLayout(this);

    QWidget *scrollWidget = new QWidget();
    QGridLayout *lay = new QGridLayout(scrollWidget);


    scrollWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QScrollArea *scroll = new QScrollArea();
    scrollWidget->setMinimumSize(scroll->size());

    QStringList l = practice_.getLetterList();

    int col = 0,
            row = 0,
            index = 0;


    //Create a button for each existing string and add it to the layout
    for (auto it = l.begin(); it != l.end(); ++it, index++) {
        QPushButton *button = new QPushButton((*it).replace('&',"&&"));

        connect(button, SIGNAL(clicked()), this, SLOT(lauchExercice()));
        button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        button->setMinimumHeight(100);
        button->setContentsMargins(1, 1, 1, 1);
        button->setFocusPolicy(Qt::NoFocus);

        if (index > TUser::currentUser()->getProgression()->getLastExericeIndex()) {
            button->setEnabled(false);
        }

        learnButtons_ << button;

        lay->addWidget(button, row, col);

        col++;
        if (col >= MAX_COL) {
            row++;
            col = 0;
        }

    }

    scroll->setWidget(scrollWidget);
    main->addWidget(scroll);
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


            testWindow_ = new TWindowLearn(ex,this);
            //Connect only once the test dialog
            connect(testWindow_, SIGNAL(endOfExercice(TResult*, QTime)), this, SLOT(endExercice(TResult*, QTime)));
            connect(testWindow_, SIGNAL(closed()), this, SLOT(resetExercice()));
            testWindow_->show();
            testWindow_->focusWidget();
        }
    }//else ..nothing to do !
}

void LearnPage::endExercice(TResult* exerciceResult, QTime timeEx) {
    //TODO : check if the result is good enought to set the advance in the progression (Azarias)
    testWindow_->hide();

    if ((timeEx.msecsSinceStartOfDay() / 1000.f) > 120) {
        QMessageBox::information(this, "Too long", "You didn't made in time.");
    } else {
        TProgression *curProgr = TUser::currentUser()->getProgression();
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
        }
    }

    resetExercice();
}

void LearnPage::resetExercice() {
    testWindow_->disconnect();
    testWindow_ = nullptr;
    currentProgression_ = -1;
}

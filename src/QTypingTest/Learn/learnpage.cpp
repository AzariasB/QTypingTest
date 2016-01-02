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
        QPushButton *button = new QPushButton(*it);

        connect(button, SIGNAL(clicked()), this, SLOT(lauchExercice()));
        button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        button->setMinimumHeight(100);
        button->setContentsMargins(1, 1, 1, 1);

        if (index > THomePage::currentUser_->getProgression()->getLastExericeIndex()) {
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
            QStringList lastLetter = practice_.getLettersAt(lastLetterIndex);
            QStringList allLetters = QStringList(practice_.getAllLettersTo(lastLetterIndex + 1));
            TExercice *ex = new TExercice(TExercice::LEARNING, lastLetter, allLetters);
            testWindow_ = new TWindowTest(ex, this);
            //Connect only once the test dialog
            connect(testWindow_, SIGNAL(endOfExercice(TResult*)), this, SLOT(endExercice(TResult*)));
            connect(testWindow_, SIGNAL(closed()), this, SLOT(resetExercice()));
            testWindow_->show();
            testWindow_->focusWidget();
        }
    }//else ..nothing to do !
}

void LearnPage::endExercice(TResult* exerciceResult) {
    //TODO : check if the result is good enought to set the advance in the progression (Azarias)

    TProgression *curProgr = THomePage::currentUser_->getProgression();
    if (currentProgression_ == curProgr->getLastExericeIndex())
        curProgr->avdvanceExIndex();

    resetExercice();

    QString text = QString("Congratulations, you finished the exercice !<br/>"
            "Results are :<br/>") + exerciceResult->getResume();

    QMessageBox::information(this, "End of exercice", text);
    testWindow_->hide();
    //Unlock the last button if exercice succeeded
    if (curProgr->getLastExericeIndex() < learnButtons_.size()) {
        learnButtons_.at(curProgr->getLastExericeIndex())->setEnabled(true);
    } else {
        //Finished the game !
    }
}

void LearnPage::resetExercice() {
    currentProgression_ = -1;
}

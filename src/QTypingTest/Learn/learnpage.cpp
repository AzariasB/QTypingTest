/* 
 * File:   LearnPage.cpp
 * Author: boutina
 * 
 * Created on 17 décembre 2015, 17:58
 */

#include <qt5/QtWidgets/qmessagebox.h>

#include "learnpage.h"

LearnPage::LearnPage(QWidget* parent) : QWidget(parent) {
    this->createPractice();
}

void LearnPage::createPractice() {

    QStringList l = practice_.getLetterList();

    int col = 0,
            row = 0,
            index = 0;
    QGridLayout *lay = new QGridLayout(this);
    //Create a button for each existing string and add it to the layout
    for (auto it = l.begin(); it != l.end(); ++it, index++) {
        QPushButton *button = new QPushButton(*it);
        connect(button, SIGNAL(clicked()), this, SLOT(lauchExercice()));
        button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

        if (index > THomePage::currentUser_->getProgression()->getLastExericeIndex()) {
            button->setEnabled(false);
        }

        lay->addWidget(button, row, col);

        col++;
        if (col >= MAX_COL) {
            row++;
            col = 0;
        }

    }
}

void LearnPage::lauchExercice() {
    int lastLetterIndex = THomePage::currentUser_->getProgression()->getLastExericeIndex();
    QStringList lastLetter = practice_.getLettersAt(lastLetterIndex);
    QStringList allLetters = QStringList(practice_.getAllLettersTo(lastLetterIndex + 1));


    TExercice *ex = new TExercice(TExercice::LEARNING, lastLetter, allLetters);
    testWindow_ = new TWindowTest(ex, this);
    //Connect only once the test dialog
    connect(testWindow_, SIGNAL(endOfExercice(TResult*)), this, SLOT(endExercice(TResult*)));
    testWindow_->show();
}

void LearnPage::endExercice(TResult* exerciceResult) {
    //TODO : check if the result is correct enought to set the advance in the progression
    TProgression *curProgr = THomePage::currentUser_->getProgression();
    curProgr->avdvanceToExercice();

    QString text = QString("Congratulations, you finished the exercice !\n"
            "Results are : WPM : %1\n"
            "Correct key strokes : %2\n"
            "Wrong key strokes : %3\n"
            "Total key strokes : %4")
            .arg(exerciceResult->getWPM())
            .arg(exerciceResult->getCorrectKeysStrokes())
            .arg(exerciceResult->getWrongKeysStrokes())
            .arg(exerciceResult->getTotalKeysStokres());

    QMessageBox::information(this, "End of exercice", text.toHtmlEscaped());
    testWindow_->hide();
    //Unlock the last button if needed
}

/* 
 * File:   LearnPage.cpp
 * Author: boutina
 * 
 * Created on 17 décembre 2015, 17:58
 */

#include "LearnPage.h"

LearnPage::LearnPage(QWidget* parent) : QWidget(parent) {
    this->createPractice();
}


void LearnPage::createPractice() {
    TPractice t = TPractice::getInstance();

    QStringList l = t.getLetterList();

    int col = 0,
            row = 0;
    QGridLayout *lay = new QGridLayout(this);
    //Create a button for each existing string and add it to the layout
    for (auto it = l.begin(); it != l.end(); ++it) {
        QPushButton *button = new QPushButton(*it);
        button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        lay->addWidget(button, row, col);

        col++;
        if (col >= MAX_COL) {
            row++;
            col = 0;
        }
    }
}

int LearnPage::lauchExercice() {
    qDebug() << "Create exercices :";
}

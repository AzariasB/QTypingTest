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
        connect(button, SIGNAL(clicked()), this, SLOT(lauchExercice()));
        button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        lay->addWidget(button, row, col);

        col++;
        if (col >= MAX_COL) {
            row++;
            col = 0;
        }
    }
}

void LearnPage::lauchExercice() {
    if (QPushButton * b = dynamic_cast<QPushButton*> (sender())) {
        qDebug() << "Create exercices : " << b->text();
    } else {
        qDebug() << "Sender is not a button";
    }
}

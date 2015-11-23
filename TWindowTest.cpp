/* 
 * File:   TWindowTest.cpp
 * Author: boutina
 * 
 * Created on 10 novembre 2015, 12:03
 */


/*
 * Options :
 *  * From file (give filename)
 *  * From letter-list ... (jf + kd + ...) => random words
 *  * From possible letters => 
 *  * From String
 */

#include "TWindowTest.h"
#include "Tline.h"

TWindowTest::TWindowTest(QString model, QWidget *parent) :
QWidget(parent),
lines(new QList<TLine*>()) {
    createLines(model);
}

void TWindowTest::createLines(QString textModel) {
    QVBoxLayout *centralLayout = new QVBoxLayout();

    QStringList words = textModel.split("");
    int charPerLines = words.size() / this->numberOfLines;
    QList<QString> models;
    words.takeLast();
    words.takeFirst(); //Remove empty strings
    //Split the word list into a single list, for each TLine
    for (int i = 0; i < numberOfLines; i++) {
        QStringList *line = new QStringList(words.mid(i*charPerLines,charPerLines));
        models += line->join("");
    }

    for (auto it = models.begin(); it != models.end(); ++it) {
        TLine *sLine = new TLine(*it);
        connect(sLine, SIGNAL(endedLine(int)), this, SLOT(nextLine()));
        centralLayout->addWidget(sLine);
        (*lines) << sLine;
    }

    this->setLayout(centralLayout);
}

//Slots

void TWindowTest::nextLine() {
    (*lines)[currentLine]->setEnabled(false);
    this->currentLine++;
    if (this->currentLine < lines->size()) {
        this->lines->at(currentLine)->setFocus();
    } else {
        emit endOfExercice();
    }
}


//Destructor

TWindowTest::~TWindowTest() {
}


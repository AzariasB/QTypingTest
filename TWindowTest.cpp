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
        //Find the closest space to do not cut a word
        int indexlast =   this->findClosestSpace(&words,charPerLines);
        QStringList *line = new QStringList(words.mid(0,indexlast));
        //Reduce the size of the original array
        words = words.mid(indexlast+1);
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


/**
 * Finding the closest space in sa list of single Qstrings
 * 
 * @param search list of QStrings containing single char each.
 * @param indexStart index where to start the search
 * @return the index of the closes space in the list, strating from indexStart
 * if no space is found, the index of the last char is returned
 */
int TWindowTest::findClosestSpace(const QStringList* search, int indexStart) {
    if(indexStart >= search->length() || search->at(indexStart) == " ") return indexStart;
    int toDecr = indexStart;
    int toIncr = indexStart;
    for(;toDecr >= 0 && toIncr < search->size();--toDecr,++toIncr){
        if(search->at(toDecr) == " ") return toDecr;
        if(search->at(toIncr) == " ") return toIncr;
    }
    return toIncr;//End of the string
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


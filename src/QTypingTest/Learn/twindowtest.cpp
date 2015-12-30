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

#include "twindowtest.h"

TWindowTest::TWindowTest(QString model, QWidget *parent) :
QDialog(parent),
lines_(new QList<tln::TLine*>()) {
    this->setModal(true);
    createLines(model.split(" "));
}

TWindowTest::TWindowTest(TExercice *exercice, QWidget *parent) :
QDialog(parent),
lines_(new QList<tln::TLine*>()) {
    this->setModal(true);
    QStringList exLetters = exercice->buildExercice();
    createLines(exLetters);
}

void TWindowTest::createLines(QStringList words) {
    //Hack for testing => shortucut to end the exercice
    QShortcut *sh = new QShortcut(this);
    sh->setKey(Qt::CTRL + Qt::Key_F);
    
    connect(sh,&QShortcut::activated,[=](){
        emit endOfExercice(totRes_);
    });
    
    QVBoxLayout *centralLayout = new QVBoxLayout();

    int charPerLines = words.size() / this->numberOfLines_;
    QList<QString> models;

    for (int i = 0; i < numberOfLines_; i++) {
        //Find the closest space to do not cut a word
        int indexlast = this->findClosestSpace(&words, charPerLines);
        QStringList *line = new QStringList(words.mid(0, indexlast));
        //Reduce the size of the original array
        words = words.mid(indexlast + 1);
        models += line->join("");
    }
    
    qDebug() << models;

    for (auto it = models.begin(); it != models.end(); ++it) {
        tln::TLine *sLine = new tln::TLine(*it);
        sLine->setEnabled(false); //Disable all to prevent user to switch of lineEdit
        connect(sLine, SIGNAL(endedLine(TResult*)), this, SLOT(nextLine(TResult*)));
        centralLayout->addWidget(sLine);
        (*lines_) << sLine;
    }
    lines_->at(0)->setEnabled(true); //Enable first line

    connect(lines_->at(0), SIGNAL(startedLine()), this, SLOT(beginExercice()));
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
    if (indexStart >= search->length() || search->at(indexStart) == " ") return indexStart;
    int toDecr = indexStart;
    int toIncr = indexStart;
    for (; toDecr >= 0 && toIncr < search->size(); --toDecr, ++toIncr) {
        if (search->at(toDecr) == " ") return toDecr;
        if (search->at(toIncr) == " ") return toIncr;
    }
    
    return toIncr; //End of the string
}


//Slots

void TWindowTest::nextLine(TResult* previousScore) {
    *this->totRes_ += *previousScore;
    (*lines_)[currentLine_]->setEnabled(false);
    this->currentLine_++;
    if (this->currentLine_ < lines_->size()) {
        this->lines_->at(currentLine_)->setEnabled(true);
        this->lines_->at(currentLine_)->setFocus();
    } else {
        int elapsedMS = this->timeStart_.elapsed();
        float mnElapsed = (float) elapsedMS / 60000.f; //Ms to minutes
        totRes_->updateWPM(mnElapsed);
        emit endOfExercice(totRes_);
    }
}

void TWindowTest::beginExercice() {
    this->timeStart_.start();
}


//Destructor

TWindowTest::~TWindowTest() {
}


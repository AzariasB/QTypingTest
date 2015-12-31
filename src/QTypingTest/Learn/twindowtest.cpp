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
lines_(QList<tln::TLine*>()) {
    setupWidget(model.split(" "));
}

TWindowTest::TWindowTest(TExercice *exercice, QWidget *parent) :
QDialog(parent),
lines_(QList<tln::TLine*>()) {
    QStringList exLetters = exercice->buildExercice();
    setupWidget(exLetters);
}

void TWindowTest::setupWidget(QStringList words) {
    //Setup window
    this->setModal(true);
    this->setFocusPolicy(StrongFocus);
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    this->move(0, 0);

    //Hack for testing => shortucut to end the exercice
    QShortcut *sh = new QShortcut(this);
    sh->setKey(CTRL + Key_F);

    connect(sh, &QShortcut::activated, [ = ](){
        emit endOfExercice(totRes_);
    });
    //end of hack


    QStringList models = splitText(words);

    lines_ = createLines(models);

    lines_[0]->setEnabled(true); //Enable first line

    connect(lines_[0], SIGNAL(startedLine()), this, SLOT(beginExercice()));
}

QList<tln::TLine*> TWindowTest::createLines(QStringList model) {
    QVBoxLayout *centralLayout = new QVBoxLayout();
    QList<tln::TLine*> lines;

    for (int i = 0; i < model.size(); i++) {
        tln::TLine *sLine = new tln::TLine(model[i]);
        sLine->setEnabled(false); //Disable all to preventLine -> user to switch of lineEdit
        connect(sLine, SIGNAL(endedLine(TResult*)), this, SLOT(nextLine(TResult*)));
        centralLayout->addWidget(sLine);
        if (i > 0) {
            connect(sLine, SIGNAL(eraseOverflow()), this, SLOT(previousLine()));
        }
        lines << sLine;

    }

    this->setLayout(centralLayout);
    return lines;
}

void TWindowTest::previousLine() {
    //Pop the last result
    
    //Disable the current tline
    lines_[currentLine_]->setEnabled(false);
    
    currentLine_--;
    
    //Enable the current tline and erase the last char
    lines_[currentLine_]->setEnabled(true);
    lines_[currentLine_]->eraseAnswer();
}


QStringList TWindowTest::splitText(QStringList text) {
    int charPerLines = text.size() / this->numberOfLines_;

    QStringList models;

    for (int i = 0; i < numberOfLines_; i++) {
        //Find the closest space to do not cut a word
        int indexlast = this->findClosestSpace(&text, charPerLines);
        QStringList *line = new QStringList(text.mid(0, indexlast));
        //Reduce the size of the original array
        text = text.mid(indexlast + 1);
        models << line->join("") + " ";
    }
    return models;
}

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

//Protected

void TWindowTest::keyPressEvent(QKeyEvent* ev) {
    this->lines_[currentLine_]->update(ev);
}

void TWindowTest::moveEvent(QMoveEvent *ev) {
    qDebug() << "moving !";
    ev->ignore();
    ev->setAccepted(false);
}



//Slots

void TWindowTest::nextLine(TResult* previousScore) {
    *this->totRes_ += *previousScore;
    lines_[currentLine_]->setEnabled(false);
    this->currentLine_++;
    if (this->currentLine_ < lines_.size()) {
        this->lines_[currentLine_]->setEnabled(true);
        this->lines_[currentLine_]->setFocus();
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


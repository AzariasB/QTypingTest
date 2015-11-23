/* 
 * File:   TLabel.cpp
 * Author: boutina
 * 
 * Created on 4 novembre 2015, 18:21
 */

#include <qt5/QtWidgets/qlineedit.h>
#include <qt5/QtGui/qguiapplication.h>

#include "TLabel.h"
#ifdef TLABEL_H

TLabel::TLabel(QString textLine) : QWidget() {
    this->initStyleSheet();
    this->setLabels(textLine);
}

TLabel::TLabel(QString text, QWidget* parent) : QWidget(parent) {
    this->initStyleSheet();
    this->setLabels(text);
}

void TLabel::setLabels(QString labelLine) {
    QHBoxLayout *lineLayout = new QHBoxLayout(this);
    lineLayout->setSpacing(0);
    QString previousWord = "";
    for (QString word : labelLine.split(" ").toVector()) {
        QLabel *aWord = new QLabel(word);
        aWord->move(previousWord.length() * 10, 0);
        aWord->setContentsMargins(2, 0, 1, 0);
        lineLayout->addWidget(aWord);
        previousWord = word;
        this->labels.append(aWord);
    }
    lineLayout->addStretch();//To align all labels to the left
}

/**
 * Set the string to copy to the next label
 * 
 * @return if there is anther word to copy
 */
bool TLabel::nextWord() {
    if (wordIsCorrect) {
        //Set color of label to green
        this->labels.at(currentWord)->setStyleSheet("QLabel{color : #0D5F1C}");
    } else {
        //Wrong => red
        this->labels.at(currentWord)->setStyleSheet("QLabel{color : #5F0D1B}");
    }
    if (this->currentWord < this->labels.size() - 1) {
        this->currentWord++;
        return true;
    }
    wordIsCorrect = true;
    return false;
}

/**
 * Check if the answer the user is entering is correct
 * 
 * @param wordTyped the whole word the user typed
 * @return if the answer is the good one
 */
bool TLabel::correctAnswer(QString wordTyped) {
    QString finalBgColor = "#3188FF"; //Selectionné
    QString finalColor = "black";
    bool isCorrect = true;

    auto *currentWord = this->labels.at(this->currentWord);
    wordTyped = wordTyped.split(" ").last();

    //Not the same word => wrong
    if (currentWord->text().indexOf(wordTyped) != 0) {
        finalBgColor = "#AB001E";
        nbrErrors++;
        isCorrect = false;
    }

    if (!wordTyped.isEmpty()) wordIsCorrect = isCorrect;

    currentWord->setStyleSheet("QLabel{border-color : " + finalBgColor + "; background-color : " + finalBgColor + ";color : " + finalColor + "}");
    return isCorrect;
}

void TLabel::initStyleSheet() {
    //    this->setStyleSheet("QLabel{padding : 0px; margin : 0px; border-style: solid;border-width: 5px;border-radius : 10px; border-color : rbga(0,0,0,0); }");
}

//TODO : créer un objet plus complet pour la précision

int TLabel::getNbrErrors() {
    return nbrErrors;
}

TLabel::~TLabel() {
}

#endif
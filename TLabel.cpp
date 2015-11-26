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
    if (exactSame) {
        //Set color of label to green
        this->labels.at(currentWord)->setStyleSheet("QLabel{color : #0D5F1C}");
    } else {
        //Wrong => red
        this->labels.at(currentWord)->setStyleSheet("QLabel{color : #5F0D1B}");
    }
    if (this->currentWord < this->labels.size() - 1) {
        this->currentWord++;
        return true;//Some words remains
    }
    exactSame = true;//Reinit the bool to default : true
    return false;//No more words
}

/**
 * Check if the answer the user is entering is correct
 * 
 * @param wordTyped the whole word the user typed
 * @return if the answer exactly the same as the text to copy
 */
bool TLabel::updateLabelColor(QString wordTyped) {
    QString finalBgColor = "#3188FF"; //Selectionné
    QString finalColor = "black";

    auto *currentWord = this->labels.at(this->currentWord);
    QStringList splited = wordTyped.split(" ");
    wordTyped = splited.takeLast();
    //Find the first non-empty word (must be last or before-last)
    while(splited.size() > 0 && wordTyped.isEmpty()) wordTyped = splited.takeLast();
    
    

    //Not the same word => wrong
    if (currentWord->text().indexOf(wordTyped) != 0) {
        finalBgColor = "#AB001E";
        nbrErrors++;
    }

    exactSame = wordTyped.trimmed() == currentWord->text();

    currentWord->setStyleSheet("QLabel{border-color : " + finalBgColor + "; background-color : " + finalBgColor + ";color : " + finalColor + "}");
    return exactSame;
}

void TLabel::initStyleSheet() {
    //    this->setStyleSheet("QLabel{padding : 0px; margin : 0px; border-style: solid;border-width: 5px;border-radius : 10px; border-color : rbga(0,0,0,0); }");
}


int TLabel::getNbrErrors() {
    return nbrErrors;
}

QString TLabel::getCurrentWord() {
    return labels.at(currentWord)->text();
}


TLabel::~TLabel() {
}

#endif
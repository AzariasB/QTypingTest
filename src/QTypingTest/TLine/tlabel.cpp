/* 
 * File:   TLabel.cpp
 * Author: boutina
 * 
 * Created on 4 novembre 2015, 18:21
 */


#include "tlabel.h"
#ifdef TLABEL_H

TLabel::TLabel(QString textLine) : QWidget() {
    this->setLabels(textLine);
}

TLabel::TLabel(QString text, QWidget* parent) : QWidget(parent) {
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
        this->labels_.append(aWord);
    }
    lineLayout->addStretch(); //To align all labels to the left
}

/**
 * Set the string to copy to the next label
 * 
 * @return if there is anther word to copy
 */
bool TLabel::nextWord() {
    if (exactSame_) {
        //Set color of label to green
        this->labels_.at(currentWord_)->setStyleSheet("QLabel{color : #0D5F1C}");
    } else {
        //Wrong => red
        this->labels_.at(currentWord_)->setStyleSheet("QLabel{color : #5F0D1B}");
    }
    if (this->currentWord_ < this->labels_.size() - 1) {
        this->currentWord_++;
        return true; //Some words remains
    }
    exactSame_ = true; //Reinit the bool to default : true
    return false; //No more words
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

    auto *currentWord = this->labels_.at(this->currentWord_);
    QStringList splited = wordTyped.split(" ", QString::SkipEmptyParts);
    wordTyped = splited.takeLast();

    QString purified = html::removeTag(currentWord->text());

    //Not the same word => wrong
    if (purified.indexOf(wordTyped) != 0) {
        finalBgColor = "#AB001E";
        nbrErrors_++;
    } else if (wordTyped.size() < purified.size()) {
        //Bold next char
        purified = html::addTagAt(purified, "b", wordTyped.size());

    }

    exactSame_ = wordTyped == purified;

    currentWord->setText(purified);

    QString stylesheed = QString("QLabel{border-color : %1; "
            "background-color : %1; color %2;}")
            .arg(finalBgColor)
            .arg(finalColor);
    currentWord->setStyleSheet(stylesheed);

    return exactSame_;
}

int TLabel::getNbrErrors() {

    return nbrErrors_;
}

QString TLabel::getCurrentWord() {

    return labels_.at(currentWord_)->text();
}

TLabel::~TLabel() {
}

#endif
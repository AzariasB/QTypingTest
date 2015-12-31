/* 
 * File:   TLabel.cpp
 * Author: boutina
 * 
 * Created on 4 novembre 2015, 18:21
 */


#include "tlabel.h"
#ifdef TLABEL_H

TLabel::TLabel(QString textLine) :
QLabel(),
stringToCopy_(textLine) {
    this->setLabels();
}

TLabel::TLabel(QString text, QWidget* parent) :
QLabel(parent),
stringToCopy_(text) {
    this->setLabels();
}

void TLabel::setLabels() {
    this->setFont(labelFont_);
    this->setText(html::addTagsAt(stringToCopy_, "b,u", 0));
}

bool TLabel::nextChar(bool currendIsCorrect) {
    //    QString finalBgColor = "#7378E8"; //Selectionné
    //    QString finalColor = "black";
    //    finalBgColor = "#FF5E58";

    QString htmlized = this->text();
    
    if (!currendIsCorrect) {
        htmlized = html::addTagsAt(htmlized, "i", currentChar_);
    }else{
        htmlized = html::addTagsAt(htmlized,"span",currentChar_);
    }
    
    currentChar_++;
    htmlized = html::addTagsAt(htmlized,"b,u",currentChar_);
    this->setText(htmlized);
    
    return currentChar_ < stringToCopy_.size() - 1;
    //    auto *currentWord = this->labels_.at(this->currentWord_);
    //    QString purified = html::removeTag(currentWord->text());
    //
    //    if (!wordTyped.isEmpty() &&
    //            (wordTyped.at(wordTyped.size() - 1) == ' ' ||
    //            wordTyped.split(" ", QString::SkipEmptyParts).takeLast().size() == purified.size())) {
    //        nextWord(wordTyped == purified);
    //    }
    //
    //
    //    QStringList splited = wordTyped.split(" ", QString::SkipEmptyParts);
    //    if (!splited.isEmpty()) {
    //        wordTyped = splited.takeLast();
    //
    //
    //        //Not the same word => wrong
    //        if (purified.indexOf(wordTyped) != 0) {
    //            
    //            nbrErrors_++;
    //        }
    //
    //        //Add the position indicator
    //        purified = html::addTagsAt(purified, "b,u", wordTyped.size());
    //
    //    } else {
    //        purified = html::addTagsAt(purified, "b,u", 0);
    //    }
    //    currentWord->setText(purified);



    //    QString stylesheed = QString("QLabel{border-color : %1; "
    //            "background-color : %1; color %2;}")
    //            .arg(finalBgColor)
    //            .arg(finalColor);
    //    currentWord->setStyleSheet(stylesheed);

    //To be changed to return something more usefull
}

TLabel::~TLabel() {
}

#endif
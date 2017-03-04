
/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */


/* 
 * File:   TLabel.cpp
 * Author: boutina
 * 
 * Created on 4 novembre 2015, 18:21
 */


#include "tlabel.h"
#ifdef TLABEL_H

TLabel::TLabel(QString text, QWidget* parent):
QLabel(parent),
stringToCopy_(text){
    this->setLabels();
}

void TLabel::setLabels() {
    this->setFont(labelFont_);
    splitedChars_ = stringToCopy_.split("", QString::SkipEmptyParts);
    
    this->setText(splitedChars_.join(""));
}

bool TLabel::nextChar(bool currendIsCorrect) {
    html::removeTag(splitedChars_[currentChar_]);
    if (!currendIsCorrect) {
        html::addTags(splitedChars_[currentChar_], "u", "style='color : #FF5E58;'");
    } else {
        html::addTags(splitedChars_[currentChar_], "span", "style='color : #8E8EFF';");
        currentChar_++;
    }

    if (currentChar_ < stringToCopy_.size()) {
        html::addTags(splitedChars_[currentChar_], "b,u");
    }
    this->setText(splitedChars_.join(""));

    return currentChar_ < stringToCopy_.size();
}

bool TLabel::previousChar() {
    if (currentChar_ == 0)return false;

    if (currentChar_ < splitedChars_.size())
        html::removeTag(splitedChars_[currentChar_]);

    currentChar_--;
    html::removeTag(splitedChars_[currentChar_]);
    html::addTags(splitedChars_[currentChar_], "b,u");
    this->setText(splitedChars_.join(""));
    return true;
}

TLabel::~TLabel() {
}

#endif

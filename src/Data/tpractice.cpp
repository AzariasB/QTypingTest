
/* 
 * File:   TPractice.cpp
 * Author: boutina
 * 
 * Created on 17 décembre 2015, 11:35
 */


#include "tpractice.h"

void TPractice::initLetters(KEYBOARD_LAYOUT layout) {
    //TODO : change it to accept others layouts
    layout = AZERTY;
    (*this->letterOrder_) << "fj"
            << "dk"
            << "sl"
            << "qm"
            << "gh"
            << "ty"
            << "ru"
            << "ei"
            << "zo"
            << "ap"
            << "v,"
            << "c;"
            << "x:,"
            << "w!"
            << "bn"
            << "ù"
            << "&="
            << "é)"
            << "\"à"
            << "'ç"
            << "(_"
            << "-è"
            << "FJ"
            << "DK"
            << "SL"
            << "QM"
            << "GH"
            << "TY"
            << "RU"
            << "EI"
            << "ZO"
            << "AP"
            << "V?"
            << "C."
            << "X/"
            << "W§"
            << "1+"
            << "2°"
            << "30"
            << "49"
            << "58"
            << "67";
}

QStringList TPractice::getAllLettersTo(int lastIndex) {
    if (lastIndex == -1) lastIndex = this->letterOrder_->size();
    QStringList res;
    for (int i = 0; i < lastIndex; i++)
        res << this->letterOrder_->at(i).split("", QString::SkipEmptyParts);




    return res;
}

QStringList TPractice::getLettersAt(int index) {
    return this->letterOrder_->at(index).split("", QString::SkipEmptyParts);
}

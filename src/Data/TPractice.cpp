
/* 
 * File:   TPractice.cpp
 * Author: boutina
 * 
 * Created on 17 décembre 2015, 11:35
 */


#include "TPractice.h"

void TPractice::initLetters(KEYBOARD_LAYOUT layout) {
    //TODO : change it to accept others layouts
    layout = AZERTY;
    (*this->letterOrder) << "df"
            << "dk"
            << "sl"
            << "qm"
            << "gh"
            << "ty"
            << "ru"
            << "ei"
            << "zo"
            << "ap"
            << "vb"
            << "cn"
            << "cx,"
            << "w;"
            << ":!";
}



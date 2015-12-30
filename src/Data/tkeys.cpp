/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */

/* 
 * File:   TKeys.cpp
 * Author: boutina
 * 
 * Created on 30 décembre 2015, 11:47
 */


#include "tkeys.h"

QList<int> TKeys::letters_;

TKeys::TKeys() {
}


QList<int> TKeys::validLetters() {
    if (TKeys::letters_.isEmpty()) {
        //List of all valids key pressed
        //To be completed !
        TKeys::letters_ << Key_A << Key_B << Key_C << Key_D << Key_E
                << Key_F << Key_G << Key_H << Key_I << Key_J
                << Key_K << Key_L << Key_M << Key_N << Key_P
                << Key_P << Key_Q << Key_R << Key_S << Key_T
                << Key_U << Key_U << Key_V << Key_W << Key_X
                << Key_Y << Key_Z << Key_Comma << Key_Semicolon
                << Key_Question << Key_Space;
    }
    return TKeys::letters_;
}

bool TKeys::isValidLetter(int letterCode) {
    return validLetters().indexOf(letterCode) != -1;
}

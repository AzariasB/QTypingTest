/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */
/* 
 * File:   TVirtualKeyboard.cpp
 * Author: boutina
 * 
 * Created on 27 janvier 2016, 10:32
 */

#include "tvirtualkeyboard.h"


TVirtualKeyboard::TVirtualKeyboard(const TVirtualKeyboard& orig):
QWidget(orig.parentWidget()){
}

TVirtualKeyboard::TVirtualKeyboard(QString lang, QWidget* parent):
QWidget(parent){

}

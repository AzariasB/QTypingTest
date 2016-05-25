/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */

/* 
 * File:   TPracticeText.cpp
 * Author: boutina
 * 
 * Created on 26 janvier 2016, 18:48
 */

#include "tpracticetext.h"

TPracticeText::TPracticeText(QWidget *parent):
TWindowTest(parent){
    TExercice *ex = new TExercice(TExercice::PRACTICING_TEXT,true);
    pages_.setupPages(ex->buildExercice());
    updateToolbarProgression();
}

TPracticeText::TPracticeText(const TPracticeText& orig) :
TWindowTest(orig.pages_.getText(),orig.parentWidget()){
    updateToolbarProgression();
}

TPracticeText::TPracticeText(QString text, QWidget* parent):
TWindowTest(text,parent){
    updateToolbarProgression();
}

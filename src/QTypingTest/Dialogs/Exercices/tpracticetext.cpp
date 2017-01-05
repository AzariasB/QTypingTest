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
    TExercice *ex = TExercice::generateExercice(TExercice::PRACTICING_TEXT);
    //Set the number of page depending on the text's length
    //40 words per page
    QString exo = ex->buildExercice();
    qDebug() << ex->getNumberOfWords();
    pages_.setNumberOfPages(ex->getNumberOfWords() / 30);
    pages_.setupPages(exo);
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

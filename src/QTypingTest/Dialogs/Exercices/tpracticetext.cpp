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
    int wordsPerPage = 30;
    pages_.setNumberOfPages(ex->getNumberOfWords() / wordsPerPage);
    pages_.setupPages(exo);

    topToolbar_.setAdditionnalText(findTitleAndAuthor(ex));
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


QString TPracticeText::findTitleAndAuthor(TExercice *exo)
{
    QString author = exo->hasAttribute("author") ? exo->findAttribute("author") : "";
    QString title = exo->hasAttribute("title") ? exo->findAttribute("title") : "";
    QString authorPres = author.isEmpty() ? "" : "<b>Author : </b> " + author;
    QString titlePres = title.isEmpty() ? "" : "<b>Title : </b> " + title;
    return authorPres + (titlePres.isEmpty() ? "" : "<br/>" + titlePres);
}

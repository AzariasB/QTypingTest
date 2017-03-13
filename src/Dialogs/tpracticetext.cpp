/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */

/* 
 * File:   TPracticeText.cpp
 * Author: boutina
 * 
 * Created on 26 janvier 2016, 18:48
 */

#include "tpracticetext.h"

#include "Data/texercise.h"


TPracticeText::TPracticeText(QWidget *parent):
TWindowTest(TExercise::generateExercise(TExercise::PRACTICING_TEXT), parent){
    //Set the number of page depending on the text's length
    //40 words per page
	QString exo = exercise().buildExercise();
    int wordsPerPage = 30;
	pages_.setNumberOfPages(exercise().getNumberOfWords() / wordsPerPage);
    pages_.setupPages(exo);

    topToolbar_.setAdditionnalText(findTitleAndAuthor(exercise()));
    updateToolbarProgression();
}

TPracticeText::TPracticeText(const TPracticeText& orig) :
TWindowTest(orig.pages_.getText(), TExercise::generateExercise(TExercise::PRACTICING_TEXT), orig.parentWidget()){
    updateToolbarProgression();
}

TPracticeText::TPracticeText(QString text, QWidget* parent):
TWindowTest(text, TExercise::generateExercise(TExercise::PRACTICING_TEXT), parent){
    updateToolbarProgression();
}


QString TPracticeText::findTitleAndAuthor(TExercise &exo)
{
	QString author = exo.hasAttribute("author") ? exo.findAttribute("author") : "";
	QString title = exo.hasAttribute("title") ? exo.findAttribute("title") : "";
    QString authorPres = author.isEmpty() ? "" : "<b>Author : </b> " + author;
    QString titlePres = title.isEmpty() ? "" : "<b>Title : </b> " + title;
    return authorPres + (titlePres.isEmpty() ? "" : "<br/>" + titlePres);
}

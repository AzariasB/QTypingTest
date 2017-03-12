/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */


/* 
 * File:   TPracticeText.h
 * Author: boutina
 *
 * Created on 26 janvier 2016, 18:48
 */

#ifndef TPRACTICETEXT_H
#define TPRACTICETEXT_H

#include <QWidget>

#include "twindowtest.h"

class TExercice;

class TPracticeText : public TWindowTest {
    Q_OBJECT
public:
    TPracticeText(QWidget *parent = 0);
    TPracticeText(QString text, QWidget *parent = 0);
    TPracticeText(const TPracticeText& orig);


    virtual ~TPracticeText() {

    }

private:
	QString findTitleAndAuthor(TExercice &exo);
    
};

#endif /* TPRACTICETEXT_H */


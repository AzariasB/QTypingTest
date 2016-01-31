/*
 * QTypingTest by Pierre and Azarias - //website//
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

#include "Data/texercice.h"
#include "QTypingTest/Dialogs/twindowtest.h"

class TPracticeText : public TWindowTest {
    Q_OBJECT
public:
    TPracticeText(QWidget *parent = 0);
    TPracticeText(QString text, QWidget *parent = 0);
    TPracticeText(const TPracticeText& orig);

    virtual ~TPracticeText() {

    }

    
protected:

    void updateClock(){
        topToolbar_.incrementTimer(1);
    }
    
};

#endif /* TPRACTICETEXT_H */

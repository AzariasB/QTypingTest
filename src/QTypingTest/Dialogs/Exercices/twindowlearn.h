/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */

/* 
 * File:   TWindowLearn.h
 * Author: boutina
 *
 * Created on 10 janvier 2016, 11:40
 */

#ifndef TWINDOWLEARN_H
#define TWINDOWLEARN_H

#include <QWidget>
#include "QTypingTest/Dialogs/twindowtest.h"
#include "QTypingTest/Learn/tpresentation.h"
#include "Data/texercice.h"

class TWindowLearn : public TWindowTest {
    Q_OBJECT
public:
    TWindowLearn(QString content,QWidget *parent = 0);
    TWindowLearn(TExercice *ex, QWidget *parent = 0);
    TWindowLearn(TExercice *ex, int numberOfPages, QWidget *parent = 0);

    virtual ~TWindowLearn() {
    };

protected:
    
    void updateClock() override{
        topToolbar_.incrementTimer(1);
    };
    

private:
    TPresentation *instructions_;
};

#endif /* TWINDOWLEARN_H */


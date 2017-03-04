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
#include "twindowtest.h"

class TExercice;
class TPresentation;

class TWindowLearn : public TWindowTest {
    Q_OBJECT
public:
    TWindowLearn(QString content, QWidget *parent = 0);
    TWindowLearn(TExercice *ex, QWidget *parent = 0);
    TWindowLearn(TExercice *ex, int numberOfPages, QWidget *parent = 0);

    virtual ~TWindowLearn() {
    }

public slots:
    /* Called when the presentation is over */
    void endOfTraining();


private:
    TPresentation *instructions_;

    void addInstructions(TExercice *exo = 0);
};

#endif /* TWINDOWLEARN_H */


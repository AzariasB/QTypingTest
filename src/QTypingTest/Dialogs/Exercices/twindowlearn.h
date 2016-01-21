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

class TWindowLearn : public TWindowTest {
    Q_OBJECT
public:
    TWindowLearn(QString model, QWidget *parent = 0);
    TWindowLearn(QString model, int numberOfPages,QWidget *parent = 0);

    virtual ~TWindowLearn() {
    };
private:

};

#endif /* TWINDOWLEARN_H */


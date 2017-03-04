/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */
/* 
 * File:   TImprove.h
 * Author: boutina
 *
 * Created on 12 février 2016, 17:45
 */

#ifndef TIMPROVE_H
#define TIMPROVE_H

#include <QWidget>
#include <QChar>

#include "twindowtest.h"

class TImprove : public TWindowTest {
public:
    TImprove(QWidget *parent = 0);
    virtual ~TImprove();
private:
    

    void updateClock(){
        topToolbar_.incrementTimer(1);
    }


    QString listToString(const QList<QChar> &chars);
};

#endif /* TIMPROVE_H */


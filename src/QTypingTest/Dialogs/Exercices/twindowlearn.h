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


#include "QTypingTest/Dialogs/twindowtest.h"

class TWindowLearn : public TWindowTest {
    Q_OBJECT
public:
    TWindowLearn(QString model,QWidget *parent = 0):TWindowTest(parent)
    {
        
    };
    virtual ~TWindowLearn();
private:
    void createToolBar();
    QList<tln::TPage*> createPages(QStringList model) override;

};

#endif /* TWINDOWLEARN_H */


/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */

/* 
 * File:   TPractice.h
 * Author: boutina
 *
 * Created on 24 janvier 2016, 11:55
 */

#ifndef TPRACTICEBASE_H
#define TPRACTICEBASE_H

#include <QWidget>

#include "QTypingTest/Dialogs/twindowtest.h"
#include "Data/texercice.h"

class TPracticeBase : public TWindowTest {
    Q_OBJECT
public:
    TPracticeBase(QWidget *parent = 0);
    TPracticeBase(TExercice *generator,QWidget *parent = 0);
    TPracticeBase(const TPracticeBase& orig);
    virtual ~TPracticeBase(){
        
    }

    TExercice *getGenerator() const{
        return generator_;
    }
    
protected:
    
    void updateClock(){
        topToolbar_.incrementTimer(1);
    }

    
private:

    TExercice *generator_;
    
    void setupText();
};

#endif /* TPRACTICEBASE_H */

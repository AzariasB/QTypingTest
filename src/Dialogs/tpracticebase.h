/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
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

#include "twindowtest.h"

class TExercice;

class TPracticeBase : public TWindowTest {
    Q_OBJECT
public:
    TPracticeBase(QWidget *parent = 0);
    TPracticeBase(TExercice *generator,QWidget *parent = 0);
    TPracticeBase(const TPracticeBase& orig);
	virtual ~TPracticeBase(){
		delete generator_;
    }

    TExercice *getGenerator() const{
        return generator_;
    }
    
private:

    TExercice *generator_;
    
    void setupText();
};

#endif /* TPRACTICEBASE_H */


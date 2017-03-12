/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */

/* 
 * File:   TPracticerace.h
 * Author: boutina
 *
 * Created on 21 janvier 2016, 15:27
 */

#ifndef TPRACTICERACE_H
#define TPRACTICERACE_H

#define RACE_TIME 60

#include <QWidget>
#include <QDebug>

#include "twindowtest.h"

class TExercice;
class TResult;

class TPracticeRace : public TWindowTest {
    Q_OBJECT
public:
    TPracticeRace(int timeStart = RACE_TIME, QWidget *parent = 0);
	TPracticeRace(TExercice &exercise, int timeStart = RACE_TIME, QWidget *parent = 0);

    virtual ~TPracticeRace() {
    }

public slots:

    /**
     * @brief stopRun
     */
    void stopRun();

    /**
     * Generate a new page for the exercice
     * 
     * @param prevPageRes the result of the page that was just finished
     */
    void createPage();

private:


    /**
     * Because this type of exercice is way different from the others
     * (genrate a page when one is finished), a lot of configuration
     * must be applied to the stackpage object
     */
    void setupPage(int timeStart = RACE_TIME);
};

#endif /* TPRACTICERACE_H */


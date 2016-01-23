/*
 * QTypingTest by Pierre and Azarias - //website//
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

#include <QWidget>
#include <QDebug>


#include "QTypingTest/Dialogs/twindowtest.h"
#include "Data/texercice.h"
#include "Data/tresult.h"

class TPracticeRace : public TWindowTest {
    Q_OBJECT
public:
    TPracticeRace(QWidget *parent = 0);
    TPracticeRace(TExercice *generator, QWidget *parent = 0);
    TPracticeRace(const TPracticeRace& orig);

    virtual ~TPracticeRace() {
    };

    TExercice exerciceGenerator() const {
        return generator_;
    }

public slots:

    /**
     * @Override
     * 
     * decrement the time on the counter
     */
    void updateClock();


    /**
     * Generate a new page for the exercice
     * 
     * @param prevPageRes the result of the page that was just finished
     */
    void createPage(TResult *prev = 0);

private:
    /**
     * The exercice that will generate the pages
     */
    TExercice generator_;


    /**
     * Because this type of exercice is way different from the others
     * (genrate a page when one is finished), a lot of configuration
     * must be applied to the stackpage object
     */
    void setupPage();
};

#endif /* TPRACTICERACE_H */


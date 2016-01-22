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
    
    
    TExercice exerciceGenerator() const{
        return generator_;
    }

public slots:
    /**
     * Called to update the clock of the toolbar
     */
    void updateClock();


    /**
     * Generate a new page for the exercice
     * 
     * @param prevPageRes the result of the page that was just finished
     */
    void createPage(TResult* prevPageRes);
    
private:
    /**
     * The exercice that will generate the pages
     */
    TExercice generator_;
    
    void handleEvents();

};

#endif /* TPRACTICERACE_H */


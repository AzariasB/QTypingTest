/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */

/* 
 * File:   PracticePage.h
 * Author: boutina
 *
 * Created on 6 janvier 2016, 10:15
 */

#ifndef PRACTICEPAGE_H
#define PRACTICEPAGE_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include <QDebug>
#include <QTime>

#include "Dialogs/twindowtest.h"
#include "Dialogs/tpracticerace.h"
#include "Dialogs/tpracticebase.h"
#include "Dialogs/tpracticetext.h"
#include "Dialogs/timprove.h"

class PracticePage : public QWidget {
    Q_OBJECT
public:
    PracticePage(QWidget *parent = 0);
    PracticePage(const PracticePage& orig);

    virtual ~PracticePage() {
    };

public slots:
    /* Start a practice against time */
    void startExercice(TWindowTest *exercice);

    /* Save the result and the time at the end of each exercice */
    void saveExerciceResult(TResult *res, QTime time);

    /* Reset the dialog (disconnect and set to null) */
    void resetExercice();
    
    /**
     * Called whenever the user changes, or
     * when the user finished an exercice (and has some new errors)
     * to update the button 'improve'
     */    
    void updateImproveButton(TUser *nwUser);
    
    /**
     */
    void userChanges(TUser *nwUser);

private:
    /* Setup the widget on the page */
    void setupLayout();

    /* Connect the events of each button */
    void connectEvents();


    /*Button to acces an exercice against the time*/
    QPushButton practiceAgainstTime_;

    /* To access the 'default' exercice */
    QPushButton practiceDefault_;

    /* Improve the keys where the user makes the most mistakes */
    QPushButton practiceImprove_;

    /* Practice on a text */
    QPushButton practiceText_;

    /* Dialog of the exercice */
    QDialog *currentDialog_ = nullptr;
};

#endif /* PRACTICEPAGE_H */


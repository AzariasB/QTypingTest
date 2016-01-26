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

#include "QTypingTest/Dialogs/twindowtest.h"
#include "QTypingTest/Dialogs/Exercices/tpracticerace.h"
#include "QTypingTest/Dialogs/Exercices/tpracticebase.h"
#include "QTypingTest/Dialogs/Exercices/tpracticetext.h"

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
    void saveExerciceResult(TResult *res,QTime time);

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


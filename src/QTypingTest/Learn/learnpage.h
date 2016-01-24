/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */

/* 
 * File:   LearnPage.h
 * Author: boutina
 *
 * Created on 17 décembre 2015, 17:58
 */

#ifndef LEARNPAGE_H
#define LEARNPAGE_H

#define MAX_COL 6


#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QGridLayout>
#include <QDebug>
#include <QVector>
#include <QScrollArea>


#include "Data/tpractice.h"
#include "Data/texercice.h"
#include "Data/tresult.h"
#include "Data/tuser.h"
#include "Util/filehelper.h"
#include "Util/htmlhelper.h"
#include "QTypingTest/Dialogs/Exercices/twindowlearn.h"


//Thomepage is for the current user. TODO : change the location of the current user
#include "QTypingTest/thomepage.h"

class LearnPage : public QWidget {
    Q_OBJECT
public:
    LearnPage(QWidget *parent = 0);
    //TODO : add constructor with User as parameter to set the buttons


    LearnPage(const LearnPage& orig);

    virtual ~LearnPage() {
    };

public slots:
    void lauchExercice();
    /**
     * Called when an exercice is finished
     */
    void endExercice(TResult *exerciceResult,QTime timeEx);


    /**
     * Called when an exercice is finished or when the exerice
     * dialog is closed to reset all the necessary values
     */
    void resetExercice();

private:
    /**
     * Get the current keyboard layout, and display the exercices depending on 
     * the layout
     */
    void createPractice();
    

    //Save the tpractice instead of instanciate it over and over
    TPractice practice_ = TPractice::getInstance();

    //Have a unique window for the exercice that will change depending on the exercices
    TWindowLearn *testWindow_;

    /*A list of button to save the state (activated or not) of each depending on the user progression*/
    QVector<QPushButton*> learnButtons_;
    
    /**
     * When a user start a new exercice, this int is set to the index of the letter he's doing
     */
    int currentProgression_ = -1;
};

#endif /* LEARNPAGE_H */


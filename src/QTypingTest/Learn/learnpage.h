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

#define BUTTON_WIDTH 100

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QGridLayout>
#include <QDebug>
#include <QVector>
#include <QScrollArea>

#include "Data/tlayouts.h"
#include "Data/texercice.h"
#include "Data/tresult.h"
#include "Data/tusermanager.h"
#include "Util/htmlhelper.h"
#include "QTypingTest/Dialogs/Exercices/twindowlearn.h"


//Thomepage is for the current user.  \todo : change the location of the current user
#include "QTypingTest/thomepage.h"

class LearnPage : public QWidget {
    Q_OBJECT
public:
    LearnPage(QWidget *parent = 0);
    // \todo : add constructor with User as parameter to set the buttons


    LearnPage(const LearnPage& orig);

    virtual ~LearnPage(){
        
    }

public slots:
    void lauchExercice();
    /**
     * Called when an exercice is finished
     */
    void endExercice(TResult *exerciceResult, QTime timeEx);


    /**
     * Called when an exercice is finished or when the exerice
     * dialog is closed to reset all the necessary values
     */
    void resetExercice();

    void updateUserProgression(TUser *nwUser);

protected:
     void resizeEvent(QResizeEvent *);


private:
    /**
     * Get the current keyboard layout, and display the exercices depending on 
     * the layout
     */
    void createPractice();

    /**
     * Creates the buttons
     * of the learn page, based 
     * on the actual layout
     */
    void createButtons(QGridLayout *lay);
   


    //Save the tpractice instead of instanciate it over and over
    TLayouts practice_ = TLayouts::getInstance("azerty");

    //Have a unique window for the exercice that will change depending on the exercices
    TWindowLearn *testWindow_;

    /*A list of button to save the state (activated or not) of each depending on the user progression*/
    QVector<QPushButton*> learnButtons_;

    /**
     * When a user start a new exercice, this int is set to the index of the letter he's doing
     */
    int currentProgression_ = -1;
    
    QGridLayout *learnButtonsLayout_;
};

#endif /* LEARNPAGE_H */


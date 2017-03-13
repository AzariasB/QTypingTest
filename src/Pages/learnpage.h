/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
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
#include <QTime>
#include "Data/tusermanager.h"
#include "Data/tlayout.h"

class TExercise;
class TResult;
class TUserManager;
class TWindowLearn;
class TUser;

class LearnPage : public QWidget {
    Q_OBJECT
public:
    LearnPage(QWidget *parent = 0);


    LearnPage(const LearnPage& orig);

    virtual ~LearnPage(){
        
    }

public slots:
    void lauchExercise();
    /**
     * Called when an exercise is finished
     */
	void endExercise(TResult &exerciseResult, QTime timeEx);


    /**
     * Called when an exercise is finished or when the exerice
     * dialog is closed to reset all the necessary values
     */
    void resetExercise();

	void updateUserProgression(TUser &nwUser);

	/**
	 * @brief resetUserProgressoin
	 * Called when a user disconnects
	 */
	void resetUserProgressoin();

protected:
     void resizeEvent(QResizeEvent *);


private:
    /**
     * Get the current keyboard layout, and display the exercises depending on 
     * the layout
     */
    void createPractice();

    /**
     * Creates the buttons
     * of the learn page, based 
     * on the actual layout
     */
    void createButtons(QGridLayout *lay);
   
	//Reference to the app's user manager
	TUserManager &um;

    //Save the tpractice instead of instanciate it over and over
    TLayout practice_ = TLayout::getInstance();

    //Have a unique window for the exercise that will change depending on the exercises
    TWindowLearn *testWindow_;

    /*A list of button to save the state (activated or not) of each depending on the user progression*/
    QVector<QPushButton*> learnButtons_;

    /**
     * When a user start a new exercise, this int is set to the index of the letter he's doing
     */
    int currentProgression_ = -1;
    
    QGridLayout *learnButtonsLayout_;
};

#endif /* LEARNPAGE_H */


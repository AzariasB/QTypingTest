/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LearnPage.h
 * Author: boutina
 *
 * Created on 17 décembre 2015, 17:58
 */

#ifndef LEARNPAGE_H
#define LEARNPAGE_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QGridLayout>
#include <QDebug>
#include <QVector>

#include "../../Data/tpractice.h"
#include "../../Data/texercice.h"
#include "../../Data/tresult.h"
#include "../twindowtest.h"

//Thomepage is for the current user. TODO : change the location of the current user
#include "../thomepage.h"

#define MAX_COL 5

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
    void endExercice(TResult *exerciceResult);

private:
    /**
     * Get the current keyboard layout, and display the exercices depending on 
     * the layout
     */
    void createPractice();

    //Save the tpractice instead of instanciate it over and over
    TPractice practice_ = TPractice::getInstance();
    
    //Have a unique window for the exercice that will change depending on the exercices
    TWindowTest *testWindow_;
    
    /*A list of button to save the state (activated or not) of each depending on the user progression*/
    QVector<QPushButton*> learnButtons_;
};

#endif /* LEARNPAGE_H */


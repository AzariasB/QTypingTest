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
#include <QGridLayout>
#include <QDebug>

#include "../../Data/tpractice.h"

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

private:
    /**
     * Get the current keyboard layout, and display the exercices depending on 
     * the layout
     */
    void createPractice();
};

#endif /* LEARNPAGE_H */


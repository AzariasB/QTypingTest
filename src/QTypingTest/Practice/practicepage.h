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

class PracticePage : public QWidget {
    Q_OBJECT
public:
    PracticePage(QWidget *parent = 0);
    PracticePage(const PracticePage& orig);
    virtual ~PracticePage(){};
private:
    void setupLayout();
    
    /*Button to acces an exercice against the time*/
    QPushButton practiceAgainstTime_;
    
    /* To access the 'default' exercice */
    QPushButton practiceDefault_;
    
    /* Improve the keys where the user makes the most mistakes */
    QPushButton practiceImprove_;
    
    /* Practice on a text */
    QPushButton practiceText_;
};

#endif /* PRACTICEPAGE_H */


/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */

/* 
 * File:   TVirtualKey.h
 * Author: boutina
 *
 * Created on 27 janvier 2016, 10:32
 */

#ifndef TVIRTUALKEY_H
#define TVIRTUALKEY_H


#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

class TVirtualKey : public QWidget{
    Q_OBJECT
public:
    //No predefined letters
    TVirtualKey(QWidget *parent = 0);
    
    //Define only main letter
    TVirtualKey(QChar def,QWidget *parent = 0);
    
    //Define main letter and shift
    TVirtualKey(QChar def,QChar shift,QWidget *parent = 0);
    
    //Define main letter, shift letter an altgre letter
    TVirtualKey(QChar def,QChar shift,QChar alt,QWidget *parent = 0);
    TVirtualKey(const TVirtualKey& orig);
    
    virtual ~TVirtualKey(){
        
    }
    
    QChar getAlt() const{
        return altgred_;
    };

    QChar getDefault() const {
        return default_;
    }

    QChar getShift() const{
        return shifted_;
    };

    
private:
    void constructLetters(QChar def = '\0',QChar shift = '\0',QChar altg = '\0');
    
    /* The letter when the user simply press the key */
    QChar default_;
    
    /* The letter when the user press the key + shift */
    QChar shifted_;
    
    /* The letter when the user press the key + altGr */
    QChar altgred_;
    
    /* Render the layout depending on the available keys */
    void setupKey();
};

#endif /* TVIRTUALKEY_H */


/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */

/* 
 * File:   TVirtualKeyboard.h
 * Author: boutina
 *
 * Created on 27 janvier 2016, 10:32
 */

#ifndef TVIRTUALKEYBOARD_H
#define TVIRTUALKEYBOARD_H


#include <QWidget>
#include "tvirtualkey.h"

class TVirtualKeyboard : public QWidget {
    Q_OBJECT
public:
    TVirtualKeyboard(QString lang = "en", QWidget *parent = 0);
    TVirtualKeyboard(const TVirtualKeyboard& orig);
    virtual ~TVirtualKeyboard(){
        
    }
private:

};

#endif /* TVIRTUALKEYBOARD_H */


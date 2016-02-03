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

#include <QHash>
#include <QRegExp>
#include <QDebug>
#include <QList>
#include <QHash>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTimer>

#include "tvirtualkey.h"
#include "Util/filehelper.h"
#include "Data/tlayouts.h"

class TVirtualKeyboard : public QWidget {
    Q_OBJECT
public:
    TVirtualKeyboard(QString lang = "en", QWidget *parent = 0);
    TVirtualKeyboard(const TVirtualKeyboard& orig);

    virtual ~TVirtualKeyboard() {
    }

    QHash<QChar, TVirtualKey*> *getKeys() const {
        return keys_;
    }

    /**
     * Will update the keyboard depending on the
     *  key event (release or pressed)
     * and return the key that was updated
     * 
     * @param ev the key event
     * @return the virtualkey corresponding to the event
     */
    TVirtualKey *updateKeyboard(QKeyEvent *ev, bool itsWrong = false);
    
    
    TVirtualKey *highlightKey(QChar keyChar);


private:
    /**
     * Read the layout's file 
     * and display the keyboard
     * depending on the language
     * 
     * @param lan the language of the keyboard
     */
    void setupWidget(QString lan);


    /**
     * Will create and add to the layout the
     * TVirtual key from the code of each String
     * and add them to the corresponding line
     * depending on their index in the list :
     * 1 - Number line
     * 2 - Upper line
     * 3 - Baseline
     * 4 - Bottom line
     * 
     * @param keyChars the list of list of key code
     */
    void createKeys(QList<QStringList> *keyChars);

    /**
     * Create the line containin the number in the
     * keyboard, will add them to the widget
     * and return this widget
     * 
     * @param keys the keys of the line
     * @return the widget containing all the letters of the line
     */
    QWidget *numberLine(QStringList keys);

    /**
     * Creates the upper line of the keyboard
     * 
     * @param keys the keys of the line
     * @return the widget containing all the letters of the line
     */
    QWidget *upperLine(QStringList keys);

    /**
     * Will create the baseline of the keyboard
     * This function will also underline the 
     * 'base keys' (F and J on the major parts of the keyboards)
     * 
     * @param keys the keys of the line
     * @return the widget containing all the letters of the line
     */
    QWidget *middleLine(QStringList keys);

    /**
     * Created the bottom line of the keyboard
     * 
     * @param keys the keys of the line
     * @return the widget containing all the letters of the line
     */
    QWidget *bottomLine(QStringList keys);

    /**
     * 
     * @return the widget with all the virtualkey on it
     */
    QWidget *spaceBarLine();
    /**
     * Create a TVirtual key from the given attributes :
     * 1 - A single char => Simple key
     * 2 - Two chars => key with default + shift char
     * 3 - Three char => key with default + shift char + alt char
     * Add it the to the QHash
     * 
     * @param attributes the attributes of the key
     * @return the created TVirtualKey
     */
    TVirtualKey *createKey(QString attributes);

    /* All the 'normal' keys that can change of position on the 
     * keyboard
     *  */
    QHash<QChar, TVirtualKey*> *keys_;
    
    /*
     All the 'special' keys that will always be on the same position
     * on the keyboard (spacebar, shift, enter, ...)
     */
    QHash<int,TVirtualKey*> *modifiers_;
    
    //Separate the two shift (qt does not separate left and right shift)
    TVirtualKey *leftShift_;
    TVirtualKey *rightShift_;
};

#endif /* TVIRTUALKEYBOARD_H */


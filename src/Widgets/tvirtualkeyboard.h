/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
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

#include "tvirtualkey.h"
#include "Data/tlayout.h"

class TVirtualKeyboard : public QWidget {
    Q_OBJECT
public:
    TVirtualKeyboard(TLayout&layout, QWidget *parent = 0);
    TVirtualKeyboard(const TVirtualKeyboard& orig);

    virtual ~TVirtualKeyboard() {
    }


    QHash<uint, TVirtualKey*> getKeys() const {
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
    TVirtualKey *updateKeyboard(QKeyEvent *ev, QChar expected = '\0');
    
    /**
     * @brief highlightKey
     * Hilights a key from the given char
     *
     * @param keyChar the char of the key to higlight
     * @return the highlighted key (if found) else nullptr
     */
    TVirtualKey *highlightKey(QChar keyChar);

	/**
	 * @brief highlightModifier
	 * Highlight the modifier with the given id
	 * The problem is : for shift key, there is only
	 * one key code in Qt
	 *
	 * @param modId
	 * @return
	 */
    TVirtualKey *highlightModifier(int modId);

	/**
	 * @brief highlightShift
	 * Highlights the shift with the given index :
	 *  0 = left shift
	 *  1 = right shift
	 *
	 * @param index
	 * @return
	 */
	TVirtualKey *highlightShift(short index);

	/**
	 * @brief reset
	 * Remove all the higlithed keys
	 */
	void reset();


private:
    /**
     * Read the layout's file 
     * and display the keyboard
     * depending on the language
     * 
     * @param lan the language of the keyboard
     * @param country the country code of the keyboard
     */
    void setupWidget(TLayout&layout);


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
    void createKeys(const QList<QStringList> &keyChars);

    /**
     * @brief setOriginalState
     * Changes the state of the key back to its original,
     * the original state can be one these two :
     *  - example, if the key is a modifier (shift or altgr)
     *  and the expected char actually needs a modifier or
     * if the char typed is typed on the good key, but not
     * with the good modifier
     *  - reset otherwise (not the good key, or not the good
     * modifier)
     *
     *
     * @param key the key that will have its state changed back to its original state
     * @param ev the event (key released)
     * @param expected the char expected to be pressed (to know wether or not the
     * virtualkey must be reset or set as example)
     */
    void setOriginalState(TVirtualKey *key, QKeyEvent *ev, QChar expected);

    /**
     * Create the line containin the number in the
     * keyboard, will add them to the widget
     * and return this widget
     * 
     * @param keys the keys of the line
     * @return the widget containing all the letters of the line
     */
    QWidget *numberLine(const QStringList &keys);

    /**
     * Creates the upper line of the keyboard
     * 
     * @param keys the keys of the line
     * @return the widget containing all the letters of the line
     */
    QWidget *upperLine(const QStringList &keys);

    /**
     * Will create the baseline of the keyboard
     * This function will also underline the 
     * 'base keys' (F and J on the major parts of the keyboards)
     * 
     * @param keys the keys of the line
     * @return the widget containing all the letters of the line
     */
    QWidget *middleLine(const QStringList &keys);

    /**
     * Created the bottom line of the keyboard
     * 
     * @param keys the keys of the line
     * @return the widget containing all the letters of the line
     */
    QWidget *bottomLine(const QStringList &keys);

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
    TVirtualKey *createKey(const QString &attributes);

    /* All the 'normal' keys that can change of position on the 
     * keyboard
     *  */
    QHash<uint, TVirtualKey*> keys_;

	/**
	 * @brief getKeyCode
	 * Gets the Qt key code from the character
	 *
	 * @param c the character to convert
	 * @return the converted keycode
	 */
	uint getKeyCode(QChar c);
    
    /*
     All the 'special' keys that will always be on the same position
     * on the keyboard (spacebar, shift, enter, ...)
     */
    QHash<int,TVirtualKey*> modifiers_;
    
    //Separate the two shift (qt does not separate left and right shift)
    TVirtualKey *leftShift_;
    TVirtualKey *rightShift_;
};

#endif /* TVIRTUALKEYBOARD_H */


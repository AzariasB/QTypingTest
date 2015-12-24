/* 
 * File:   TPractice.h
 * Author: boutina
 *
 * Created on 17 décembre 2015, 11:35
 */

#ifndef TPRACTICE_H
#define TPRACTICE_H

#include <QStringList>

/**
 * This class is here to have a way to create the exercices
 * on a certain order based on the keyboard layou
 */
class TPractice {
public:
    static TPractice &getInstance(){
        static TPractice instance;
        return instance;
    }
    
    //TODO : find a way to let the user add his own keyboard
    enum KEYBOARD_LAYOUT{QWERTY,AZERTY,QWERTZ};
    
    QStringList getLetterList(){
        return *this->letterOrder_;
    }
    
    virtual ~TPractice(){};
private:
    QStringList *letterOrder_;
    TPractice(){
        this->letterOrder_ = new QStringList();
        this->initLetters(AZERTY);
    };
    /**
     * Init the list of letters
     * 
     * @param layout layout of the keyboard
     */
    void initLetters(KEYBOARD_LAYOUT layout);
    
};

#endif /* TPRACTICE_H */


/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */
/* 
 * File:   TExercice.h
 * Author: boutina
 *
 * Created on 18 décembre 2015, 11:42
 */

#ifndef TEXERCICE_H
#define TEXERCICE_H

#include <QStringList>
#include <QDebug>

#include "tresult.h"
#include "Util/factory.h"

/**
 * A model class to define the type of exercice the user is about to do
 * There are differents types of exercices and depending of these, differents parameters
 */
class TExercice {
public:

    enum EXERCICE_TYPE {
        LEARNING, PRACTICING, PRACTICING_RACE, PRACTICING_TEXT
    };

    TExercice(EXERCICE_TYPE exType, QStringList mainLetter, QStringList availableLetters);
    TExercice(EXERCICE_TYPE exType, bool allLetters);
    TExercice(const TExercice& orig);

    QString buildExercice() const;

    virtual ~TExercice() {

    };

    QStringList learningLetters() const{
        return learningLetters_;
    }
    
    
private:
    bool allLetters_ = false;
    QStringList learningLetters_;
    QStringList availableLetters_;
    EXERCICE_TYPE exerciceType_ = LEARNING;
    
    QStringList getAllLetters() const;
};

#endif /* TEXERCICE_H */


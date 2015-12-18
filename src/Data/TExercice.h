/* 
 * File:   TExercice.h
 * Author: boutina
 *
 * Created on 18 décembre 2015, 11:42
 */

#ifndef TEXERCICE_H
#define TEXERCICE_H

#include <QStringList>

/**
 * A model class to define the type of exercice the user is about to do
 * There are differents types of exercices and depending of these, differents parameters
 */
class TExercice {
public:

    enum EXERCICE_TYPE {
        LEARNING, PRACTICING, TEXT_PRACTICING
    };

    TExercice(EXERCICE_TYPE exType, QStringList mainLetter, QStringList availableLetters);
    TExercice(EXERCICE_TYPE exType, bool allLetters);
    TExercice(const TExercice& orig);

    QStringList buildExercice();

    virtual ~TExercice() {

    };
private:
    bool allLetters = false;
    QStringList learningLetters;
    QStringList availableLetters;
    EXERCICE_TYPE exerciceType = LEARNING;
    
    QStringList getAllLetters();
};

#endif /* TEXERCICE_H */


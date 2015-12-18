/* 
 * File:   TExercice.cpp
 * Author: boutina
 * 
 * Created on 18 décembre 2015, 11:42
 */


#include <qt5/QtCore/qstringlist.h>

#include "TExercice.h"

TExercice::TExercice(EXERCICE_TYPE exType, bool allLetters) :
exerciceType(exType),
allLetters(allLetters) {
    this->availableLetters = this->allLetters ? getAllLetters() : QStringList();
}

TExercice::TExercice(EXERCICE_TYPE exType, QStringList mainLetter, QStringList availableLetters) :
exerciceType(exType),
learningLetters(mainLetter),
availableLetters(availableLetters) {
}

TExercice::TExercice(const TExercice& orig) :
exerciceType(orig.exerciceType),
learningLetters(orig.learningLetters),
availableLetters(orig.availableLetters),
allLetters(orig.allLetters) {
}

QStringList TExercice::buildExercice() {
    return QStringList();
}

QStringList TExercice::getAllLetters() {
    return QStringList("abcdefghijklmnopqrstuvwxyz");
}

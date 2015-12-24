/* 
 * File:   TExercice.cpp
 * Author: boutina
 * 
 * Created on 18 décembre 2015, 11:42
 */


#include <qt5/QtCore/qstringlist.h>

#include "texercice.h"

TExercice::TExercice(EXERCICE_TYPE exType, bool allLetters) :
exerciceType_(exType),
allLetters_(allLetters) {
    this->availableLetters_ = this->allLetters_ ? getAllLetters() : QStringList();
}

TExercice::TExercice(EXERCICE_TYPE exType, QStringList mainLetter, QStringList availableLetters) :
exerciceType_(exType),
learningLetters_(mainLetter),
availableLetters_(availableLetters) {
}

TExercice::TExercice(const TExercice& orig) :
exerciceType_(orig.exerciceType_),
learningLetters_(orig.learningLetters_),
availableLetters_(orig.availableLetters_),
allLetters_(orig.allLetters_) {
}

QStringList TExercice::buildExercice() {
    return QStringList();
}

QStringList TExercice::getAllLetters() {
    return QStringList("abcdefghijklmnopqrstuvwxyz");
}

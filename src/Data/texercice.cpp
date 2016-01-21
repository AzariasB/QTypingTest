/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */
/* 
 * File:   TExercice.cpp
 * Author: boutina
 * 
 * Created on 18 décembre 2015, 11:42
 */



#include "texercice.h"

TExercice::TExercice(EXERCICE_TYPE exType, bool allLetters) :
allLetters_(allLetters),
exerciceType_(exType)
{
    this->availableLetters_ = this->allLetters_ ? getAllLetters() : QStringList();
}

TExercice::TExercice(EXERCICE_TYPE exType, QStringList mainLetter, QStringList availableLetters) :
learningLetters_(mainLetter),
availableLetters_(availableLetters),
exerciceType_(exType){
}

TExercice::TExercice(const TExercice& orig) :
allLetters_(orig.allLetters_),
learningLetters_(orig.learningLetters_),
availableLetters_(orig.availableLetters_),
exerciceType_(orig.exerciceType_) {
}

QString TExercice::buildExercice() {
    if (exerciceType_ == LEARNING) {
        return factory::generateLearning(learningLetters_, availableLetters_);
    }else{
        return factory::generateLearning(availableLetters_,availableLetters_);
    }
}

QStringList TExercice::getAllLetters() {
    return QStringList("abcdefghijklmnopqrstuvwxyz");
}

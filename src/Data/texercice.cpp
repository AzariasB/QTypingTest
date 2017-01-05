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

TExercice::TExercice() :
allLetters_(true),
learningLetters_(""),
availableLetters_(""),
exerciceType_(PRACTICING) {
}

TExercice::TExercice(EXERCICE_TYPE exType, bool allLetters) :
allLetters_(allLetters),
exerciceType_(exType) {
    this->availableLetters_ = this->allLetters_ ? TLayouts::getInstance("qwerty").getAllAvailableLetters() : "";
}

TExercice::TExercice(EXERCICE_TYPE exType, QString mainLetter, QString availableLetters) :
learningLetters_(mainLetter),
availableLetters_(availableLetters),
exerciceType_(exType) {
}

TExercice::TExercice(const TExercice& orig) :
allLetters_(orig.allLetters_),
learningLetters_(orig.learningLetters_),
availableLetters_(orig.availableLetters_),
exerciceType_(orig.exerciceType_) {
}

QString TExercice::buildExercice() const {
    switch (exerciceType_) {
        case LEARNING:
            return factory::generateLearning(learningLetters_, availableLetters_);
        case PRACTICING:
            return factory::generatePractice(TLayouts::getInstance("qwerty").getAllAvailableLetters());
        case PRACTICING_RACE:// \todo : change the number of words to generate
            return factory::generatePractice(TLayouts::getInstance("qwerty").getAllAvailableLetters());
        case PRACTICING_TEXT:
            return factory::generateText().text();
        default:
            return factory::generateLearning(availableLetters_, availableLetters_);
    }
}

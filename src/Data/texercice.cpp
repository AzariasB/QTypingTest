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
learningLetters_(""),
availableLetters_(TLayouts::getInstance().getAllAvailableLetters()),
exerciceType_(PRACTICING){
}

TExercice::TExercice(EXERCICE_TYPE exType, QString mainLetter, QString availableLetters) :
learningLetters_(mainLetter),
availableLetters_(availableLetters),
exerciceType_(exType)
{
}

TExercice::TExercice(const TExercice& orig) :
learningLetters_(orig.learningLetters_),
availableLetters_(orig.availableLetters_),
exerciceType_(orig.exerciceType_){
}

TExercice* TExercice::generateExercice(EXERCICE_TYPE type, QString mainLetters, QString availableLetters)
{
    switch(type){
        case LEARNING:
            return new TExercice(type, mainLetters, availableLetters);
        default:    // \todo : get computer's layout
            return new TExercice(type, "", TLayouts::getInstance().getAllAvailableLetters() );
    }
}

QString TExercice::buildExercice() const {
    switch (exerciceType_) {
        case LEARNING:
            return factory::generateLearning(learningLetters_, availableLetters_);
        case PRACTICING:
        case PRACTICING_RACE:
            return factory::generatePractice(availableLetters_);
        case PRACTICING_TEXT:
            return factory::generateText().text();
        default:
            return factory::generateLearning(availableLetters_, availableLetters_);
    }
}

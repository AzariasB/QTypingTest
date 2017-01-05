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
        default:
            return new TExercice(type, "", TLayouts::getInstance().getAllAvailableLetters() );
    }
}

QString TExercice::buildExercice() {
    QString exo;
    switch (exerciceType_) {
        case LEARNING:
            exo = factory::generateLearning(learningLetters_, availableLetters_);
            break;
        case PRACTICING:
        case PRACTICING_RACE:
            exo = factory::generatePractice(availableLetters_);
            break;
        case PRACTICING_TEXT:
            exo = factory::generateText().text();
            break;
        default:
            exo =  factory::generateLearning(availableLetters_, availableLetters_);
            break;
    }
    numberOfWords_ = exo.split(" ").size();
    return exo;
}

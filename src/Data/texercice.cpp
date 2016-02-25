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
            return factory::generateText(40); //Generate a text of 40 words
        default:
            return factory::generateLearning(availableLetters_, availableLetters_);
    }
}

QDataStream &operator<<(QDataStream& out, const TExercice& ex) {
    out << ex.getAllLetters();
    out << ex.getAvailableLetters();
    qint16 type = static_cast<qint16> (ex.getExerciceType());
    out << type;
    out << ex.getLearningLetters();
    return out;
}

QDataStream &operator>>(QDataStream& in, TExercice& ex) {
    bool allLetters;
    in >> allLetters;
    QString availableLetters;
    in >> availableLetters;
    qint16 type;
    in >> type;
    TExercice::EXERCICE_TYPE exeT = static_cast<TExercice::EXERCICE_TYPE>(type);
    QString learningLetters;
    in >> learningLetters;
    ex = TExercice(exeT, learningLetters, availableLetters);
    ex.setAllLetters(allLetters);
    return in;
}

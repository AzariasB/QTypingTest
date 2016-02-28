/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */

/* 
 * File:   TUser.cpp
 * Author: boutina
 * 
 * Created on 18 décembre 2015, 18:54
 */

#include "tuser.h"


QDateTime TUser::addResult(TExercice* exTyp, TResult* exRes) {
    date_exercice_ key;
    key.dateResult = QDateTime::currentDateTime();
    key.exercice = *exTyp;
    practiceHistory_[key] = *exRes;
    return key.dateResult;
}

void TUser::oneMoreMistake(const QChar& mistaken) {
    this->statistics_[mistaken]++;
    emit statsChanged(this);
}


TUser::~TUser() {
}


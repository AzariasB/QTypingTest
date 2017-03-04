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

#include "tjsonobject.h"

QDateTime TUser::addResult(TExercice* exo, TResult* exRes, QDateTime date) {
    date_exercice_ key;
    key.dateResult = date;
    key.exercice = *exo;
    practiceHistory_[key] = *exRes;
    emit statsChanged(this);
    return key.dateResult;
}

void TUser::oneMoreMistake(const QChar& mistaken) {
    this->statistics_[mistaken]++;
    //emit statsChanged(this);
}


TUser::~TUser() {
}


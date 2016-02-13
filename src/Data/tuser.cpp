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

QDataStream &operator<<(QDataStream& out, const TUser& user) {
    out << user.getPseudo();
    out << *user.getProgression();
    out << user.getStatistics();
    out << user.getPracticeHistory();
    return out;
}

QDataStream &operator>>(QDataStream& in, TUser &user) {
    QString pseudo;
    in >> pseudo;
    user.setPseudo(pseudo);
    TProgression progress;
    in >> progress;
    user.setProgression(new TProgression(progress));
    TStats stat;
    in >> stat;
    user.setStatistics(stat);
    QHash<date_exercice_, TResult> history;
    in >> history;
    user.setPracticeHistory(history);
    return in;
}

QDataStream &operator<<(QDataStream& out, const date_exercice_& dateEx) {
    out << dateEx.dateResult;
    out << dateEx.exercice;
    return out;
}

QDataStream &operator>>(QDataStream& in, date_exercice_& dateEx) {
    QDateTime time;
    in >> time;
    TExercice ex;
    in >> ex;
    dateEx.dateResult = time;
    dateEx.exercice = ex;
    return in;
}
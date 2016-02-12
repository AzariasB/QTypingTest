/* 
 * File:   TUser.cpp
 * Author: boutina
 * 
 * Created on 18 décembre 2015, 18:54
 */



#include "tuser.h"

TUser::TUser(QString pseudo) :
pseudo_(pseudo),
progress_(new TProgression()),
statistics_(TStats()) {
}

TUser::TUser(const TUser &orig) :
pseudo_(orig.pseudo_),
progress_(orig.progress_),
statistics_(orig.statistics_),
practiceHistory_(orig.practiceHistory_) {
}

QDateTime TUser::addResult(TExercice* exTyp, TResult* exRes) {
    date_exercice_ key;
    key.dateResult = QDateTime::currentDateTime();
    key.exercice = *exTyp;
    practiceHistory_[key] = *exRes;
    return key.dateResult;
}

void TUser::oneMoreMistake(const QChar& mistaken) {
    this->statistics_[mistaken]++;
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
    user = TUser(pseudo);
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
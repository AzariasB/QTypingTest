/* 
 * File:   TUser.cpp
 * Author: boutina
 * 
 * Created on 18 décembre 2015, 18:54
 */


#include "tuser.h"

TUser::TUser(QString pseudo):
pseudo_(pseudo),
progress_(new TProgression()){
}

QDateTime TUser::addResult(TExercice* exTyp, TResult* exRes) {
    date_exercice_ key;
    key.dateResult = QDateTime::currentDateTime();
    key.exercice = exTyp;
    practiceHistory_[&key] = exRes;
    return key.dateResult;
}


TUser::~TUser() {

}

QDataStream &operator<<(QDataStream& out, const TUser& user) {
    out << user.getPseudo();
    return out;
}

QDataStream &operator>>(QDataStream& in, TUser &user) {
    QString pseudo;
    in >> pseudo;
    user = TUser(pseudo);
    return in;
}

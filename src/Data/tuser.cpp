/* 
 * File:   TUser.cpp
 * Author: boutina
 * 
 * Created on 18 décembre 2015, 18:54
 */


#include "tuser.h"

TUser::TUser(QString pseudo) {
    this->pseudo_ = pseudo;
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

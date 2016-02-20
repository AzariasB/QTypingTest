/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */


/* 
 * File:   TUserManager.cpp
 * Author: boutina
 * 
 * Created on 11 février 2016, 16:50
 */

#include "tusermanager.h"



TUserManager::~TUserManager() {
}

QDataStream &TUserManager::readUsers(QDataStream &in)
{
    while (!in.atEnd()) {
        TUser u;
        in >> u;
        users_.append(new TUser(u));
    }
    return in;
}

QDataStream &TUserManager::saveUsers(QDataStream &out)
{
    foreach (auto elem, users_) {
        out << *elem;
    }
    return out;
}

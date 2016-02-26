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

QList<TUser*> TUserManager::readUsers()
{
    QFile f(":/users.dat");
    if (!f.exists() || !f.open(QFile::ReadOnly)) {
        qDebug() << "File 'users.dat' not found";
        return QList<TUser*>();
    }

    QDataStream in(&f);
    while (!in.atEnd()) {
        TUser u;
        in >> u;
        users_.append(new TUser(u));
    }
    f.close();
    return users_;
}

bool TUserManager::saveUsers()
{
    QFile f(":/users.dat");
    if(!f.open(QFile::WriteOnly)) return false;

    QDataStream out(&f);

    foreach (auto elem, users_) {
        out << *elem;
    }
    f.close();
    emit usersSaved();
    return true;
}

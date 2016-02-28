/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */


/* 
 * File:   tusermanager.cpp
 * Author: boutina
 * 
 * Created on 11 février 2016, 16:50
 */

#include "tusermanager.h"


TUserManager::TUserManager() :
    QObject(),
    saveTarget_("QTypingTest")
{
    currentUser_ = 0;
    readUsers();
}

TUserManager::~TUserManager() {
}

QList<TUser*> TUserManager::readUsers()
{
    saveTarget_.beginGroup("users");
    bool allValid = true;
    QList<TUser*> usersTemp;
    QStringList keys= saveTarget_.childKeys();
    for(const QString &k : keys){
        QVariant v = saveTarget_.value(k);
        allValid = allValid && v.isValid();
        if(v.isValid())
            usersTemp << new TUser(v.value<TUser>());
    }
    saveTarget_.endGroup();

    if(allValid)
        users_ = usersTemp;
    return users_;
}

void TUserManager::saveUsers()
{
    saveTarget_.beginGroup("users");
    saveTarget_.clear();
    for(const TUser *u : users_){
        QVariant uVariant = QVariant::fromValue(*u);
        if(uVariant.isValid())
            saveTarget_.setValue(u->getPseudo(),uVariant);
        else
            qDebug() << "Tried to save an invalid user";
    }
    saveTarget_.endGroup();
    emit usersSaved();
}






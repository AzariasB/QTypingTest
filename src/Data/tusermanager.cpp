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


TUserManager TUserManager::_instance;

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
    users_.clear();
    saveTarget_.beginGroup("users");
    QStringList keys= saveTarget_.childKeys();
    qDebug() << keys;
    for(const QString &k : keys){
        QVariant v = saveTarget_.value(k);
        if(v.isValid())
            users_ << new TUser(v.value<TUser>());
        else
            qDebug() << "Tried to read an invalid user";
    }
    saveTarget_.endGroup();
    return users_;
}

void TUserManager::saveUsers()
{
    saveTarget_.beginGroup("users");
    for(const TUser *u : users_){
        QVariant uVariant = QVariant::fromValue(*u);
        if(uVariant.isValid())
            saveTarget_.setValue(u->getPseudo(),uVariant);
        else
            qDebug() << "Tried to save an invalid user";
    }
    saveTarget_.endGroup();
}






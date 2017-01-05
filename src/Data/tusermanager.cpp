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
    bool allValid = true;
    int arrSize = saveTarget_.beginReadArray("users");
    QList<TUser*> usersTemp;
    for(int i =0; i < arrSize;i++){
        saveTarget_.setArrayIndex(i);
        QString key = saveTarget_.childKeys()[0];
        QVariant v = saveTarget_.value(key);
        allValid = allValid && v.isValid();
        if(v.isValid())
            usersTemp << new TUser(v.value<TUser>());
    }
    saveTarget_.endArray();

    if(allValid)
        users_ = usersTemp;
    return users_;
}

void TUserManager::saveUsers()
{
    saveTarget_.beginWriteArray("users");
    saveTarget_.clear();
    for(int i = 0; i< users_.size();i++){
        saveTarget_.setArrayIndex(i);
        TUser *u = users_[i];
        QVariant uVariant = QVariant::fromValue(*u);
        if(uVariant.isValid())
            saveTarget_.setValue(u->getPseudo(),uVariant);
        else
            qDebug() << "Tried to save an invalid user";
    }
    saveTarget_.endArray();
    emit usersSaved();
}






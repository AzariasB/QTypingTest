/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */


/* 
 * File:   tusermanager.cpp
 * Author: boutina
 * 
 * Created on 11 février 2016, 16:50
 */

#include "tusermanager.h"
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

TUserManager::TUserManager(const QString &destFilePath) :
QObject(),
saveFile_(destFilePath){
    currentUser_ = 0;
}

void TUserManager::disconnectCurrentUser(){
    currentUser_ = nullptr;
    emit userDiconnected();
}

TUser &TUserManager::getCurrentUser() {
    if(currentUser_ == nullptr){
        qWarning() << "Tried to get user when not connected";
    }
    return *currentUser_;
}

bool TUserManager::setCurrentUser(TUser &nwUser) {
    //Can only set an existing user
    if(users_.contains(nwUser)){
        currentUser_ = &nwUser;
        emit userChanged(*currentUser_);
        return true;
    }else{
        qWarning() <<  "Trying to set a non-existing user";
        return false;
    }
}

TUserManager::~TUserManager() {
}

QList<TUser> &TUserManager::readUsers()
{
	if(!saveFile_.open(QIODevice::ReadOnly | QIODevice::Text)){
		qWarning("Failed to open save file.");
		return users_;
	}

	QJsonDocument loadDoc = QJsonDocument::fromJson(saveFile_.readAll());
	saveFile_.close();

	QJsonObject root = loadDoc.object();
	for(QJsonValue v : root["users"].toArray()){
		if(v.isObject()){
			TUser usr;
			usr.read(v.toObject());
			qDebug() << "Read user " << usr.getPseudo() << endl;
			users_ << usr;
		}
	}

	return users_;
}

void TUserManager::addUser(const TUser &nwUser)
{
    users_.append(nwUser);
}

bool TUserManager::removeUser(const TUser &toRemove)
{
	if(currentUser_ != nullptr && toRemove == *currentUser_)
		disconnectCurrentUser();

	return users_.contains(toRemove) && users_.removeOne(toRemove);
}

void TUserManager::saveUsers()
{
	QJsonObject usrObject;
	QJsonArray usersArr;
    for(const TUser &user : users_){
		QJsonObject jsonUsr;
		user.write(jsonUsr);

		usersArr << jsonUsr;
	}

	usrObject["users"] = usersArr;
	QJsonDocument saveDoc(usrObject);

	if(!saveFile_.open(QIODevice::WriteOnly)){
		qWarning("Failed to open save target.");
		return;
	}
	saveFile_.write(saveDoc.toJson());

	saveFile_.close();
	emit usersSaved();
}






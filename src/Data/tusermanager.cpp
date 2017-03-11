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

TUserManager::TUserManager() :
    QObject(),
    saveTarget_("QTypingTest"){
    currentUser_ = 0;
}

TUserManager::~TUserManager() {
}

QList<TUser*> TUserManager::readUsers(QFile &readTarget)
{
	if(!readTarget.open(QIODevice::ReadOnly)){
		qWarning("Failed to open save file.");
		return users_;
	}

	QJsonDocument loadDoc = QJsonDocument::fromBinaryData(readTarget.readAll());
	QJsonObject root = loadDoc.object();
	for(QJsonValue v : root["users"].toArray()){
		if(v.isObject()){
			TUser *usr = new TUser();
			usr->read(v.toObject());
			qDebug() << "Read user " << usr->getPseudo() << endl;
			users_ << usr;
		}
	}

	readTarget.flush();
	readTarget.close();
	return users_;
}

void TUserManager::saveUsers(QFile &saveTarget)
{
	if(!saveTarget.open(QIODevice::WriteOnly)){
		qWarning("Failed to open save target.");
		return;
	}

	QJsonObject usrObject;
	QJsonArray usersArr;
	for(TUser *user : users_){
		QJsonObject jsonUsr;
		user->write(jsonUsr);

		usersArr << jsonUsr;
	}

	usrObject["users"] = usersArr;
	QJsonDocument saveDoc(usrObject);
	saveTarget.write(saveDoc.toJson());

	saveTarget.flush();
	saveTarget.close();
	emit usersSaved();
}






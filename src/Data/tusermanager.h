/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */


/* 
 * File:   TUserManager.h
 * Author: boutina
 *
 * Created on 11 février 2016, 16:50
 */

#ifndef TUSERMANAGER_H
#define TUSERMANAGER_H

#include <QObject>
#include <QList>
#include <QDataStream>
#include <QJsonDocument>
#include <QFile>

#include "tuser.h"

class TUserManager : public QObject {

    Q_OBJECT

public:

	TUserManager(QString destFilePath);

	void disconnectCurrentUser(){
		currentUser_ = nullptr;
		emit userDiconnected();
	}

	bool setCurrentUser(TUser &nwUser) {
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

	/**
	 * @brief getCurrentUser
	 * returns the content
	 *
	 * @return pointer to the current user
	 */
	TUser &getCurrentUser() {
		if(currentUser_ == nullptr){
			qWarning() << "Tried to get user when not connected";
		}
		return *currentUser_;
    }

	bool isUserConnected(){
		return currentUser_ != nullptr;
	}



	QFile &getSaveFile(){
		return saveFile_;
	}

	QList<TUser> &users()
    {
        return users_;
    }

	QList<TUser> &readUsers();

	void saveUsers();


    virtual ~TUserManager();

	void addUser(const TUser nwUser);

	bool removeUser(const TUser &toRemove);

	void operator<<(TUser nwUser){
		addUser(nwUser);
    }

#ifdef QT_DEBUG
    /**
     * ONLY FOR TESTING
     *
     * The aim of this function is to start with no users
     * this function must not be called in production
     *
     *
     * @brief removeAllUsers
     */
    void removeAllUsers(){
        users_.clear();
    }
#endif

    //Respect singleton patter, prevent assigning values by any mean
    TUserManager(const TUserManager& orig) = delete;
    void operator=(TUserManager const&)    = delete;

signals:
	//Emited when the user (a new one is connecting)
	void userChanged(TUser &);

	//Emitted when the user is diconnected and nobody connects
	void userDiconnected();

    void usersSaved();

private:
	/**
	 * @brief currentUser_
	 * Pointer to the current user
	 * We're using a pointer to be able to "disconnect" the user
	 * and thus, setting the pointer to 'nullptr'
	 */
	TUser *currentUser_;

	QList<TUser> users_;

	QFile saveFile_;
};

#endif /* TUSERMANAGER_H */


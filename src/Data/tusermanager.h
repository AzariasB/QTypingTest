/*
 * QTypingTest by Pierre and Azarias - //website//
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
#include <QSettings>

#include "tuser.h"

class TUserManager : public QObject {

    Q_OBJECT

public:

    static TUserManager& getInstance() {
        static TUserManager instance;
        return instance;
    }

    void setCurrentUser(TUser *nwUser = 0) {
        //Can only set an existing user
        if(!nwUser ||  users_.contains(nwUser)){
            currentUser_ = nwUser;
        }else{
			qWarning() <<  "Trying to set a non-existing user";
        }

        if(currentUser_){
            connect(currentUser_,SIGNAL(settingsChanged(TUser*)),this,SLOT(saveUsers()));
            connect(currentUser_,SIGNAL(statsChanged(TUser*)),this,SLOT(saveUsers()));
        }
        emit userChanged(currentUser_);
    }

    TUser *getCurrentUser() {
        return currentUser_;
    }

    const QList<TUser*> &users()
    {
        return users_;
    }

    QList<TUser *> readUsers();


    virtual ~TUserManager();

    void operator<<(TUser *nwUser){
        users_ << nwUser;
        saveUsers();
    }

    bool operator -(TUser *userLess)
    {
		if(currentUser_ != nullptr && (*userLess) == (*currentUser_)){
            setCurrentUser(nullptr);
        }
        bool rmed = users_.removeOne(userLess);
        saveUsers();
        return rmed;
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
        saveTarget_.beginGroup("users");
        saveTarget_.clear();
        saveTarget_.endGroup();
    }
#endif

    //Respect singleton patter, prevent assigning values by any mean
    TUserManager(const TUserManager& orig) = delete;
    void operator=(TUserManager const&)    = delete;

public slots:
    void saveUsers();

signals:
    void userChanged(TUser *);

    void usersSaved();

private:
    QSettings saveTarget_;

    TUser *currentUser_;

    QList<TUser*> users_;

    TUserManager();
};

#endif /* TUSERMANAGER_H */


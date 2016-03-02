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
        currentUser_ = nwUser;
        if(currentUser_){
            connect(currentUser_,SIGNAL(settingsChanged(TUser*)),this,SLOT(saveUsers()));
            connect(currentUser_,SIGNAL(statsChanged(TUser*)),this,SLOT(saveUsers()));
        }
        emit userChanged(currentUser_);
    }

    TUser *getCurrentUser() const {
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
        bool rmed = users_.removeOne(userLess);
        saveUsers();
        return rmed;
    }

    /**
     * ONLY FOR TESTING
     *
     * The aim of this function is to start with no users
     * this function must not be called in production
     *
     * \todo : add preprocessor for DEBUG only
     *
     * @brief removeAllUsers
     */
    void removeAllUsers(){
        users_.clear();
        saveTarget_.beginGroup("users");
        saveTarget_.clear();
        saveTarget_.endGroup();
    }

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


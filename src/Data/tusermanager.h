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

#include "tuser.h"

class TUserManager : public QObject {

    Q_OBJECT
public:

    static TUserManager& getInstance() {
        static TUserManager manager;
        return manager;
    }

    void setCurrentUser(TUser *nwUser) {
        currentUser_ = nwUser;
        emit userChanged(currentUser_);
    }

    TUser *getCurrentUser() const {
        return currentUser_;
    }

    const QList<TUser*> users()
    {
        return users_;
    }

    QDataStream &saveUsers(QDataStream &out);

    QDataStream &readUsers(QDataStream &in);


    virtual ~TUserManager();

    void operator<<(TUser *nwUser){
        users_ << nwUser;
    }

    bool operator -(TUser *userLess)
    {
        return users_.removeOne(userLess);
    }

    TUserManager(const TUserManager& orig) = delete;
    void operator=(TUserManager const&) = delete;

signals:
    void userChanged(TUser *);

private:

    TUser *currentUser_;

    QList<TUser*> users_;


    TUserManager() : QObject() {
        currentUser_ = 0;
    }



};

#endif /* TUSERMANAGER_H */


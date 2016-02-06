/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */

/* 
 * File:   HomePage.h
 * Author: boutina
 *
 * Created on 6 février 2016, 14:24
 */

#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include <QList>
#include <QFile>
#include <QDataStream>
#include <QDebug>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QInputDialog>

#include "Data/tuser.h"
#include "Util/filehelper.h"

class HomePage : public QWidget {
    Q_OBJECT
public:
    HomePage(QWidget *parent = 0);

    virtual ~HomePage() {

    }

public slots:
    void createUser();
    
    void saveUsers();
    
    void updateUserDisplay();
    
private:
    QList<TUser*> users_;

    /**
     * List of the users
     * this layout is updated
     * every time the users list if modified
     */
    QVBoxLayout *usersList_;
    
    /**
     * Read the file 'users.dat' and recover
     * all the saved users
     * If the file does not exist,
     * a new one is created
     */
    QList<TUser*> getUsers();

    /**
     * Create the widgets
     * depending on the users
     * each users is represented as a button
     * on which the user can click to access to his
     * account
     */
    void setupWidgets();
    
    void clearLayout(QLayout *layout);

};

#endif /* HOMEPAGE_H */

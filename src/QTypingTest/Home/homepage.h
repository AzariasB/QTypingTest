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
#include <QMessageBox>

#include "Data/tusermanager.h"
#include "Util/filehelper.h"

class HomePage : public QWidget {
    Q_OBJECT
public:

    static HomePage &getInstance(QWidget *parent = 0){
        static HomePage home(parent);
        return home;
    }

    virtual ~HomePage() {
    }

    /**
     * Read the file 'users.dat' and recover
     * all the saved users
     * If the file does not exist,
     * a new one is created
     */
    QList<TUser*> getUsers();

public slots:
    void createUser();

    /**
     * @brief saveUsers
     * open the target file to save users, and write them in (by default users.dat)
     */
    bool saveUsers();

    void updateUserDisplay();
    
private:

    HomePage(QWidget *parent = 0);


    QList<TUser*> users_;

    /**
     * List of the users
     * this layout is updated
     * every time the users list if modified
     */
    QVBoxLayout *usersList_;
    

    /**
     * Create the widgets
     * depending on the users
     * each users is represented as a button
     * on which the user can click to access to his
     * account
     */
    void setupWidgets();
    
    void clearLayout(QLayout *layout);
    
    /**
     * Competely erase a user, in the list
     * and in the files
     * A message of confirmation is asked before
     * to confirm the deletion
     */
    void deleteUser(TUser *user );
};

#endif /* HOMEPAGE_H */


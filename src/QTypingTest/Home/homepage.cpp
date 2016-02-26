/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */

/* 
 * File:   HomePage.cpp
 * Author: boutina
 * 
 * Created on 6 février 2016, 14:24
 */



#include "homepage.h"

HomePage::HomePage(QWidget* parent) :
QWidget(parent),
usersList_(new QVBoxLayout()) {
    setupWidgets();
}

void HomePage::setupWidgets() {
    QVBoxLayout *mainLay = new QVBoxLayout(this);
    updateUserDisplay();
    QPushButton *nwUser = new QPushButton("Create new user");
    connect(nwUser, SIGNAL(clicked()), this, SLOT(createUser()));
    mainLay->addLayout(usersList_);
    mainLay->addWidget(nwUser);
}

void HomePage::createUser() {
    bool ok;
    QString pseudo = QInputDialog::getText(this, "Create new user",
            "User's pseudo :", QLineEdit::Normal, "", &ok);
    if (ok) {
        TUserManager::getInstance() << new TUser(pseudo);
        updateUserDisplay();
    }
}

void HomePage::updateUserDisplay() {
    clearLayout(usersList_);
    for (auto elem : TUserManager::getInstance().users() ) {
        QHBoxLayout *userLine = new QHBoxLayout();
        QPushButton *userButton = new QPushButton(elem->getPseudo());
        TUser *currentUser = TUserManager::getInstance().getCurrentUser();
        if (currentUser && elem == currentUser){
            userButton->setEnabled(false);
        }
        
        connect(userButton, &QPushButton::clicked, this, [this, elem]() {
            TUserManager::getInstance().setCurrentUser(elem);
            updateUserDisplay();
        });
        userLine->addWidget(userButton, 1);

        QPushButton *deleteUser = new QPushButton(QIcon(file::getImagePath("bin.png")), "");
        connect(deleteUser, &QPushButton::clicked, this, [this, elem]() {
            this->deleteUser(elem);
        });
        userLine->addWidget(deleteUser, 0);

        usersList_->addLayout(userLine);
    }
}

void HomePage::clearLayout(QLayout* layout) {
    QLayoutItem *child;
    while (layout->count() != 0) {
        child = layout->takeAt(0);
        if (child->layout() != 0) {
            clearLayout(child->layout());
        } else if (child->widget() != 0) {
            delete child->widget();
        }
        delete child;
    }
}

void HomePage::deleteUser(TUser *user) {
    int button = QMessageBox::warning(this, "Deleter user",
            "Are you sure to delete this user ?", QMessageBox::Yes | QMessageBox::No);
    if (button == QMessageBox::Yes) {
        TUserManager::getInstance() - user;
        updateUserDisplay();
    }
}

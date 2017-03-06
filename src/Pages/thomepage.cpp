/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */
/* 
 * File:   THomePage.cpp
 * Author: boutina
 * 
 * Created on 16 décembre 2015, 15:27
 */



#include "thomepage.h"

#include "Dialogs/toptiondialog.h"

#include "learnpage.h"
#include "practicepage.h"
#include "gamepage.h"
#include "homepage.h"

#include "Data/tlayout.h"
#include "Data/tusermanager.h"



THomePage::THomePage(QWidget *parent) :
QMainWindow(parent)
{
    ui.setupUi(this);
//    TUserManager::getInstance().setCurrentUser(new TUser("timmy"));
    connectEvents();
    this->setGeometry(QStyle::alignedRect(
                            Qt::LeftToRight,
                            Qt::AlignCenter,
                            this->size(),
                            qApp->desktop()->availableGeometry()
                          ));
}

THomePage::~THomePage() {
}

void THomePage::showAboutDialogs(){
    QMessageBox::about(this,"About","<h1>QTypingTest</h1><p> created by :</p><br/> Pierre and Azarias <br/> Version : 0.1");
}

void THomePage::showOptionDialog(){
    TOptionDialog *opt = new TOptionDialog(*TUserManager::getInstance().getCurrentUser(),this);
    opt->show();
    connect(opt,&QDialog::finished ,this,[=](int res){
        if(res == 1){
            TUser *currentUser = TUserManager::getInstance().getCurrentUser();
            currentUser->setSettings(opt->getCurrentSettings());
        }
        delete opt;
    });
}

void THomePage::connectEvents() {
    connect(ui.action_about,SIGNAL(triggered(bool)),this,SLOT(showAboutDialogs()));
    connect(ui.action_option,SIGNAL(triggered(bool)),this,SLOT(showOptionDialog()));
    connect(ui.action_change_user,SIGNAL(triggered(bool)),this,SLOT(changeUser()));
    connect(ui.action_homepage,SIGNAL(triggered(bool)),this,SLOT(goToHomePage()));
    connect(ui.action_aboutQt,SIGNAL(triggered(bool)),qApp,SLOT(aboutQt()));
    connect(&TUserManager::getInstance(),&TUserManager::usersSaved,this,[=](){
        ui.statusbar->showMessage("Users saved !",4000);
    });
    connect(&TUserManager::getInstance(),SIGNAL(userChanged(TUser*)),this,SLOT(updateUI(TUser*)) );

    buttonsStacks_[ui.button_home] = ui.page_home;
    buttonsStacks_[ui.button_learn] = ui.page_learn;
    buttonsStacks_[ui.button_games] = ui.page_games;
    buttonsStacks_[ui.button_stats] = ui.page_stats;
    buttonsStacks_[ui.button_practice] = ui.page_practice;

    //Iterate over the buttons-page couple
    for (auto it = buttonsStacks_.begin(); it != buttonsStacks_.end(); ++it) {
        //If child is not nullptr create a simple layout with parent and add the child into it
        if (!TUserManager::getInstance().getCurrentUser()) {
            it.key()->setEnabled(false);
        }
        connect(it.key(), &QPushButton::clicked, [ = ](){
            qDebug() << it.value();
            ui.stack_main->setCurrentWidget(it.value());
        });
    }
    ui.stack_main->setCurrentWidget(ui.page_home);
}

void THomePage::updateUI(TUser* nwUser) {
    bool enable = nwUser != 0;
    ui.action_option->setEnabled(enable);
    ui.action_change_user->setEnabled(enable);
    ui.action_homepage->setEnabled(enable);
    for (auto it = buttonsStacks_.begin(); it != buttonsStacks_.end(); ++it) {
        it.key()->setEnabled(enable);
    }
}


void THomePage::changeUser()
{
    TUserManager::getInstance().setCurrentUser();
    goToHomePage();
}

void THomePage::goToHomePage()
{
    ui.stack_main->setCurrentWidget(ui.page_home);
}

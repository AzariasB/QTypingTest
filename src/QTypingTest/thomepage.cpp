/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */
/* 
 * File:   THomePage.cpp
 * Author: boutina
 * 
 * Created on 16 décembre 2015, 15:27
 */



#include "thomepage.h"


THomePage::THomePage(QWidget *parent) :
QMainWindow(parent),
pagesButtons_(QVector<button_stack>())
{
    ui.setupUi(this);
//    TUserManager::getInstance().setCurrentUser(new TUser("timmy"));
    connectEvents();
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
    TUserManager::getInstance().readUsers();
    connect(ui.action_about,SIGNAL(triggered(bool)),this,SLOT(showAboutDialogs()));
    connect(ui.action_option,SIGNAL(triggered(bool)),this,SLOT(showOptionDialog()));
    connect(ui.action_change_user,SIGNAL(triggered(bool)),this,SLOT(changeUser()));
    connect(ui.action_homepage,SIGNAL(triggered(bool)),this,SLOT(goToHomePage()));
    connect(ui.action_aboutQt,SIGNAL(triggered(bool)),qApp,SLOT(aboutQt()));
    connect(&TUserManager::getInstance(),&TUserManager::usersSaved,this,[=](){
        ui.statusbar->showMessage("Users saved !",4000);
    });
    connect(&TUserManager::getInstance(),SIGNAL(userChanged(TUser*)),this,SLOT(updateUI(TUser*)) );

    button_stack sHome = {
        ui.button_home,
        ui.page_home
    };
    button_stack sLearn = {
        ui.button_learn,
        ui.page_learn
    };
    button_stack sGames = {
        ui.button_games,
        ui.page_games
    };
    button_stack sStat = {
        ui.button_stats,
        ui.page_stats
    };
    button_stack sPractice = {
        ui.button_practice,
        ui.page_practice
    };

    //Adding the structures to the array
    pagesButtons_ << sHome << sLearn << sGames << sPractice << sStat;

    //Iterate over the buttons-page couple
    for (auto it = pagesButtons_.begin(); it != pagesButtons_.end(); ++it) {
        button_stack s = *it;
        //If child is not nullptr create a simple layout with parent and add the child into it
        if (!TUserManager::getInstance().getCurrentUser()) {
            s.triggerer->setEnabled(false);
        }

        connect(s.triggerer, &QPushButton::clicked, [ = ](){
            ui.stack_main->setCurrentWidget(s.container);
        });
    }
    ui.stack_main->setCurrentWidget(ui.page_home);
}

void THomePage::updateUI(TUser* nwUser) {
    bool enable = nwUser != 0;
    ui.action_option->setEnabled(enable);
    ui.action_change_user->setEnabled(enable);
    ui.action_homepage->setEnabled(enable);
    for (auto it = pagesButtons_.begin(); it != pagesButtons_.end(); ++it) {
        it->triggerer->setEnabled(enable);
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


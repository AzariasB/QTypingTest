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
    connect(&TUserManager::getInstance(),&TUserManager::usersSaved,this,[=](){
        ui.statusbar->showMessage("Users saved !",4000);
    });
    connect(&TUserManager::getInstance(),SIGNAL(userChanged(TUser*)),this,SLOT(updateUI(TUser*)) );

    button_stack sHome = {
        ui.button_home,
        ui.page_home,
        new HomePage()
    };
    button_stack sLearn = {
        ui.button_learn,
        ui.page_learn,
        new LearnPage()
    };
    button_stack sGames = {
        ui.button_games,
        ui.page_games,
        new GamePage()
    };
    button_stack sStat = {
        ui.button_stats,
        ui.page_stats,
        nullptr // \todo : create statistics page
    };
    button_stack sPractice = {
        ui.button_practice,
        ui.page_practice,
        new PracticePage()
    };

    //Adding the structures to the array
    pagesButtons_ << sHome << sLearn << sGames << sPractice << sStat;

    //Iterate over the buttons-page couple
    for (auto it = pagesButtons_.begin(); it != pagesButtons_.end(); ++it) {
        button_stack s = *it;
        //If child is not nullptr create a simple layout with parent and add the child into it
        if (s.child) {
            QHBoxLayout *l = new QHBoxLayout(s.parent);
            l->addWidget(s.child);
        }
        if (!TUserManager::getInstance().getCurrentUser()) {
            s.triggerer->setEnabled(false);
        }

        connect(s.triggerer, &QPushButton::clicked, [ = ](){
            int i = ui.stack_main->indexOf(s.parent);
            ui.stack_main->setCurrentIndex(i);
        });
    }
    ui.stack_main->setCurrentWidget(ui.page_home);
}

void THomePage::updateUI(TUser* nwUser) {
    if (nwUser) {
        ui.action_option->setEnabled(true);
        for (auto it = pagesButtons_.begin(); it != pagesButtons_.end(); ++it) {
            it->triggerer->setEnabled(true);
        }
    }
}

/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */
/*
 * File:   toptiondialog.cpp
 * Author: boutina
 *
 * Created on 16 février
 */

#include "toptiondialog.h"

TOptionDialog::TOptionDialog(QWidget *parent):
 QDialog(parent)
{
    ui_option.setupUi(this);
    showUserOptions();
}

void TOptionDialog::showUserOptions(){
    TUser *currentUser = TUserManager::getInstance().getCurrentUser();
//    ui_option.comboBox_language->set
    ui_option.line_pseudo->setText(currentUser->getPseudo());
}


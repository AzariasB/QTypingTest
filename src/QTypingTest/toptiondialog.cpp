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


TOptionDialog::TOptionDialog(const TUser &user,QWidget *parent):
 QDialog(parent)
{
    QStringList layouts = TLayout::getInstance().getAvailablLayoutLangs();
    ui_option.setupUi(this);
    showUserOptions(user);
}

void TOptionDialog::showUserOptions(const TUser &settingsReference){
    ui_option.line_pseudo->setText(settingsReference.getPseudo());
    QString lay  = settingsReference.getLayout();
}


TUser TOptionDialog::getCurrentSettings(){
    TUser sets;
    sets.setPseudo(ui_option.line_pseudo->text());
    return sets;
}

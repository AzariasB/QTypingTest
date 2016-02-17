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
//    ui_option.comboBox_language->set
    QStringList layouts = TLayouts::getAvailablLayouLangs();
    ui_option.setupUi(this);
    ui_option.comboBox_layout->addItems(layouts);
    ui_option.comboBox_language->addItems(layouts);
    showUserOptions(user);
}

void TOptionDialog::showUserOptions(const TUser &settingsReference){

//    ui_option.comboBox_language->set
    ui_option.line_pseudo->setText(settingsReference.getPseudo());
    QString lang = settingsReference.getSettings().getCurrentLang();
    QString lay  = settingsReference.getSettings().getLayout();
    int indexLang = ui_option.comboBox_language->findText(lang);
    int indexLay  = ui_option.comboBox_layout->findText(lay);
    ui_option.comboBox_language->setCurrentIndex(indexLang);
    ui_option.comboBox_layout->setCurrentIndex(indexLay);
}


TSettings TOptionDialog::getCurrentSettings(){
    TSettings sets;
    sets.setCurrentLang(ui_option.comboBox_language->currentText());
    sets.setCurrentLayout(ui_option.comboBox_layout->currentText());
    return sets;
}

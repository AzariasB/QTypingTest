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
    QStringList layouts = TLayouts::getInstance("qwerty").getAvailablLayoutLangs();
    ui_option.setupUi(this);
    ui_option.comboBox_layout->addItems(layouts);
    showUserOptions(user);
}

void TOptionDialog::showUserOptions(const TUser &settingsReference){
    ui_option.line_pseudo->setText(settingsReference.getPseudo());
    QString lay  = settingsReference.getLayout();
    int indexLay  = ui_option.comboBox_layout->findText(lay);
    ui_option.comboBox_layout->setCurrentIndex(indexLay);
}


TUser TOptionDialog::getCurrentSettings(){
    TUser sets;
    sets.setPseudo(ui_option.line_pseudo->text());
    sets.setLayout(ui_option.comboBox_layout->currentText());
    return sets;
}

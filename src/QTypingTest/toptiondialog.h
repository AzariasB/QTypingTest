/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */
/*
 * File:   toptiondialog.h
 * Author: boutina
 *
 * Created on 16 février
 */

#ifndef TOPTIONDIALOG_H
#define TOPTIONDIALOG_H

#include <QDialog>
#include <QDebug>

#include "ui/ui_options.h"
#include "Data/tusermanager.h"

class TOptionDialog : public QDialog
{
public:
    TOptionDialog(const TUser &user,QWidget *parent =0);

    /**
     * \todo return a TUser (and delete settings)
     * @brief getCurrentSettings
     * @return the settings selected
     */
    TUser getCurrentSettings();
private :
    Ui_Dialog ui_option;

    /**
     * \todo : separate layout and language origin
     * @brief showUserOptions change the fileds of the dialog to show the user's settings
     * @param settingsReference the user
     */
    void showUserOptions(const TUser &settingsReference);
};

#endif // TOPTIONDIALOG_H

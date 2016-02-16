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
    TOptionDialog(QWidget *parent =0);
private :
    Ui_Dialog ui_option;

    void showUserOptions();
};

#endif // TOPTIONDIALOG_H

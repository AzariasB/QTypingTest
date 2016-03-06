/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */
/* 
 * File:   THomePage.h
 * Author: boutina
 *
 * Created on 16 décembre 2015, 15:27
 */

#ifndef THOMEPAGE_H
#define THOMEPAGE_H

#include <QWidget>
#include <QMainWindow>
#include <QVector>
#include <QPushButton>
#include <QDebug>
#include <QHBoxLayout>

#include "Learn/learnpage.h"
#include "Practice/practicepage.h"
#include "Games/gamepage.h"
#include "Home/homepage.h"

#include "Data/tlayouts.h"
#include "Data/tusermanager.h"
#include "ui/ui_homepage.h"
#include "toptiondialog.h"


struct button_stack {
    QPushButton *triggerer;
    QWidget *container;
};

class THomePage : public QMainWindow {
    Q_OBJECT
public:
    THomePage(QWidget *parent = 0);
    virtual ~THomePage();

public slots:
    void updateUI(TUser *nwUser);

    void showAboutDialogs();

    void showOptionDialog();

private slots:
    /**
     * @brief changeUser disonnect the current user
     * redirect him to the homepage
     */
    void changeUser();

    /**
     * @brief goToHomePage set the current widget of the
     * main stack to homepage
     */
    void goToHomePage();

private:
    /**
     *  Connect the basics event for the main window,,
     *  namely change current stack index when button click
     * and connect event about the menu options 
     */
    void connectEvents();
    Ui_MainWindow ui;

    QVector<button_stack> pagesButtons_;

};

#endif /* THOMEPAGE_H */



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

#include "../Data/TPractice.h"
#include "../ui/ui_homepage.h"


class THomePage : public QMainWindow {
    Q_OBJECT
public:
    THomePage(QWidget *parent = 0);
    virtual ~THomePage();


private:
    /**
     *  Connect the basics event for the main window,,
     *  namely change current stack index when button click
     * and connect event about the menu options 
     */
    void connectEvents();
    Ui::MainWindow ui;
};

#endif /* THOMEPAGE_H */


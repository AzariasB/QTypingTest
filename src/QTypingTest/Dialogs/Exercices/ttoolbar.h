/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Toolbar.h
 * Author: boutina
 *
 * Created on 20 janvier 2016, 09:58
 */

#ifndef TTOOLBAR_H
#define TTOOLBAR_H

#include <QWidget>
#include <QCheckBox>
#include <QLCDNumber>
#include <QLabel>
#include <QTimer>
#include <QSpacerItem>
#include <QHBoxLayout>
#include <qnamespace.h>

#include <QDebug>

class TToolbar : public QWidget {
    Q_OBJECT
public:
    TToolbar(QWidget *parent = 0);
    TToolbar(const TToolbar& orig);

    virtual ~TToolbar() {
        ;
    };

    void setProgression(QString text) {
        pageProgression_->setText(text);
    }

public slots:
    /**
     * Called whenever the user click on the pause/play button
     */
    void pauseTimer();

    /**
     * Add the value increment to the current value of the ldc display
     * 
     * @param increment the value of incrementation of the LDC display
     */
    void incrementTimer(int increment);



signals:
    /**
     * Triggered whenever the user click on the pause/play button
     * 
     * @param inPause true if the state change to pause, false otherwise
     */
    void pauseClicked();


private:
    /**
     * Create the toolbar and
     * init all its components
     */
    void setupToolbar();

    /* Allow the player to pause the game */
    QCheckBox *pauseButton_;

    /* Display the time */
    QLCDNumber *LCDtimer_;

    /* Display the progression of the user */
    QLabel *pageProgression_;


};

#endif /* TOOLBAR_H */


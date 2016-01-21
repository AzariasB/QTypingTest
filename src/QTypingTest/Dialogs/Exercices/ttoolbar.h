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
#include <QPushButton>
#include <QLCDNumber>
#include <QLabel>
#include <QTimer>
#include <QSpacerItem>
#include <QHBoxLayout>
#include <qnamespace.h>

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
     * Called every second to warn update the timer
     */
    void updateTimer();

signals:
    /**
     * Triggered whenever the user click on the pause/play button
     * 
     * @param inPause true if the state change to pause, false otherwise
     */
    void pauseContinue(bool inPause);

    /**
     * Called every second by the timer
     * usefull to update GUI elements such as the timer
     */
    void timeout();

private:
    /**
     * Create the toolbar and
     * init all its components
     */
    void setupToolbar();


    /* To peridically update the LCDNumber */
    QTimer *timer_;

    /* Allow the player to pause the game */
    QPushButton *pauseButton_;

    /* Display the time */
    QLCDNumber *LCDtimer_;

    /* Display the progression of the user */
    QLabel *pageProgression_;


    /* Save the state of the dialog : in pause or in 'normal' mode*/
    bool isInPause = false;

};

#endif /* TOOLBAR_H */


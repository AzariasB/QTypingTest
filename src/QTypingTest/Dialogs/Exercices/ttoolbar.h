/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
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
#include <QTime>
#include <QPushButton>
#include <QSpacerItem>
#include <QHBoxLayout>
#include <qnamespace.h>

#include <QDebug>

class TToolbar : public QWidget {
    Q_OBJECT
public:
    explicit TToolbar(QWidget *parent = 0);

    virtual ~TToolbar() {
        ;
    }

    void setProgression(QString text) {
        pageProgression_->setText(text);
    }
    
    void setLCDDisplayValue(int value){
        secondsValue_ = value;
        incrementTimer(0);
    }

public slots:
    /**
     * Called whenever the user click on the pause/play button
     */
    void pauseTimer();

    /**
     * Add the value increment to the current value of the ldc display
     * and update the display
     * 
     * @param increment the value of incrementation of the LDC display
     */
    double incrementTimer(int increment);

    /**
     * @brief setAdditionnalText changes the current additionnal text of the toolbard
     * @param text the text to add
     */
    void setAdditionnalText(const QString &text);

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
    QPushButton *pauseButton_;

    /* Display the time */
    QLCDNumber *LCDtimer_;

    /* Display the progression of the user */
    QLabel *pageProgression_;

    /* If needed (for example for test training) */
    QLabel *additionnalInfos_;
    
    int secondsValue_ = 0;
};

#endif /* TOOLBAR_H */


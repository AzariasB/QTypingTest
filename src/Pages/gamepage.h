/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */

/* 
 * File:   GamePage.h
 * Author: boutina
 *
 * Created on 3 février 2016, 09:58
 */

#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QDialog>

#include "Games/bouncemain.h"

class TPresentation;

class GamePage : public QWidget {
    Q_OBJECT
public:
    GamePage(QWidget *parent = 0);

    ~GamePage();

public slots:
    void showInteractiveKeyboard();

	void showBounceGame();


private:
    QPushButton *interactiveKeyboard_;
	QPushButton *bounceGame_;

    void setupWidgets();

    void connectEvents();

};

#endif /* GAMEPAGE_H */


/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */
/* 
 * File:   TVirtualKey.cpp
 * Author: boutina
 * 
 * Created on 27 janvier 2016, 10:32
 */

#include "tvirtualkey.h"
#include <QLabel>
#include <QGridLayout>
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>


TVirtualKey::TVirtualKey(const QString &content, QWidget *parent) :
QWidget(parent) {
    constructLetters(content);
    setupKey();
    setContentsMargins(0, 0, 0, 0);
}

TVirtualKey::TVirtualKey(const TVirtualKey& orig) :
QWidget(orig.parentWidget()) {
    constructLetters(orig.associatedFinger() + orig.getDefault() + orig.getShift() + orig.getAlt());
    setupKey();
    setContentsMargins(0, 0, 0, 0);

}

TVirtualKey::TVirtualKey(int w, const QString &text, TFingerPosition::FINGER associatedFinger, QWidget *parent) :
QWidget(parent) {
    setAutoFillBackground(true);
    setFixedSize(w, 50);
    associateFinger_ = associatedFinger;
    QLabel *lab = new QLabel(text);
    QGridLayout *center = new QGridLayout();
    center->addWidget(lab, 0, 0, Qt::AlignHCenter);
    this->setLayout(center);
    setContentsMargins(0,0,0,0);
}

/*
 * These are the different possibilities of key layouts
 * Exemples are based on a AZERTY keyboard but also
 * applies on QWERTY and QWERTZ
 */

/**
 * Without any shift or alt :
 * -----
 * | A | <- Default letter >
 * -----
 * 
 * With a shift only :
 * -------
 * |  ?  | <- Shift lettter >
 * |  ,  | <- Default letter >
 * -------
 * 
 * With a shift and an alt
 * -------
 * | 2   | <- Shift letter >
 * | é ~ | <- Default - altgr letter >
 * -------
 */
void TVirtualKey::setupKey() {
    //Set a fixed size
    //    this->setStyleSheet("border : 1px solid black;");
    setAutoFillBackground(true);
    this->setFixedSize(50, 50);
    QLabel *defLab = new QLabel(default_);
    QGridLayout *grid = new QGridLayout();

    if (shifted_.isNull()) {
        //simply add the label to the widget
        grid->addWidget(defLab, 0, 0, Qt::AlignHCenter);
    } else {
        QLabel *shiftLab = new QLabel(shifted_);
        grid->addWidget(shiftLab, 0, 0, Qt::AlignHCenter);

        if (altgred_.isNull()) {
            if (default_ != shifted_.toLower()) {
                //If there are the same letters, 
                //we only need to display the uppercase one
                //Otherwise ..
                grid->addWidget(defLab, 0, 0, 2, 1, Qt::AlignHCenter | Qt::AlignBottom);
            }
        } else {
            QLabel *altLab = new QLabel(altgred_);
            shiftLab->setStyleSheet("font-size : 12px;");
            defLab->setStyleSheet("font-size : 12px;");
            altLab->setStyleSheet("font-size : 12px;");
            grid->addWidget(defLab, 1, 0, Qt::AlignHCenter);
            grid->addWidget(altLab, 1, 1, Qt::AlignHCenter);
        }
    }
    this->setLayout(grid);
}

void TVirtualKey::constructLetters(const QString &letters) {
    default_ = '\0';
    shifted_ = '\0';
    altgred_ = '\0';
    associateFinger_ = TFingerPosition::NO_FINGER;
    switch (letters.size()) {
        case 4:
            altgred_ = letters[3];
            //Voluntary no break
        case 3:
            shifted_ = letters[2];
        case 2:
            associateFinger_ = (TFingerPosition::FINGER) letters[0].digitValue();
            default_ = letters[1];
            break;
    }
}

void TVirtualKey::paintEvent(QPaintEvent *e) {
    QPainter painter(this);
    painter.drawRect(0, 0, width() - 1, height() - 1);
    QWidget::paintEvent(e);
}

void TVirtualKey::setText(const QString &text) {
    default_ = '\0';
    altgred_ = '\0';
    shifted_ = '\0';
    QLabel *lab = new QLabel(text);
    QGridLayout *center = new QGridLayout();
    center->addWidget(lab, 0, 0, Qt::AlignHCenter);
    //Destruct the existing layout
    delete layout();
    setLayout(center);
}

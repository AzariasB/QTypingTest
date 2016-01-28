/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */
/* 
 * File:   TVirtualKey.cpp
 * Author: boutina
 * 
 * Created on 27 janvier 2016, 10:32
 */

#include "tvirtualkey.h"

TVirtualKey::TVirtualKey(QChar def, QWidget* parent) :
QWidget(parent) {
    constructLetters(def);
    setupKey();
}

TVirtualKey::TVirtualKey(QChar def, QChar shift, QWidget* parent) :
QWidget(parent) {
    constructLetters(def, shift);
    setupKey();
}

TVirtualKey::TVirtualKey(QChar def, QChar shift, QChar alt, QWidget* parent) :
QWidget(parent) {
    constructLetters(def, shift, alt);
    setupKey();
}

TVirtualKey::TVirtualKey(QWidget *parent) :
QWidget(parent) {
    constructLetters();
    setupKey();
}

TVirtualKey::TVirtualKey(const TVirtualKey& orig) :
QWidget(orig.parentWidget()) {
    constructLetters(orig.getDefault(), orig.getShift(), orig.getAlt());
    setupKey();
}

TVirtualKey::TVirtualKey(int w, QString text, QWidget *parent) :
QWidget(parent) {
    setAutoFillBackground(true);
    setFixedSize(w, 50);
    QLabel *lab = new QLabel(text);
    QGridLayout *center = new QGridLayout();
    center->addWidget(lab, 0, 0, Qt::AlignHCenter);
    this->setLayout(center);
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

void TVirtualKey::constructLetters(QChar def, QChar shift, QChar altg) {
    default_ = def;
    shifted_ = shift;
    altgred_ = altg;
}

void TVirtualKey::setText(QString text) {
    default_ = '\0';
    altgred_ = '\0';
    shifted_ = '\0';
    QLabel *lab = new QLabel(text);
    QGridLayout *center = new QGridLayout();
    center->addWidget(lab,0,0,Qt::AlignHCenter);
    //Destruct the existing layout
    delete layout();
    setLayout(center);
}

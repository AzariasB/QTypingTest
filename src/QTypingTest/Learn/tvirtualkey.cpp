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
    this->setFixedSize(50, 50);
    QLabel *defLab = new QLabel(default_);
    QVBoxLayout *mainLayout = new QVBoxLayout();

    if (shifted_.isNull()) {
        //simply add the label to the widget
        mainLayout->addWidget(defLab);
    } else {
        QLabel *shiftLab = new QLabel(shifted_);
        mainLayout->addWidget(shiftLab);

        if (altgred_.isNull()) {
            if (default_ != shifted_.toLower()) {
                //If there are the same letters, 
                //we only need to display the uppercase one
                mainLayout->addWidget(defLab);
            }
        } else {
            QHBoxLayout *combi = new QHBoxLayout();
            QLabel *altLab = new QLabel(altgred_);
            combi->addWidget(defLab);
            combi->addWidget(altLab);
            mainLayout->addItem(combi);
        }
    }
    this->setLayout(mainLayout);
}

void TVirtualKey::constructLetters(QChar def, QChar shift, QChar altg) {
    default_ = def;
    shifted_ = shift;
    altgred_ = altg;
}

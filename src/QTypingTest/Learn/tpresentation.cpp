/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */

/* 
 * File:   tpresentation.cpp
 * Author: boutina
 * 
 * Created on 31 janvier 2016, 15:38
 */

#include <qt5/QtCore/qlogging.h>

#include "tpresentation.h"

TPresentation::TPresentation(QString lang, QWidget* parent) :
QWidget(parent),
keyboard_(new TVirtualKeyboard(lang)),
positions_(new TFingerPosition()) {
    QVBoxLayout *lay = new QVBoxLayout();
    lay->addWidget(keyboard_);
    lay->addWidget(positions_,Qt::AlignRight);
    setLayout(lay);
}

void TPresentation::keyPressEvent(QKeyEvent *ev) {
    TVirtualKey *updated = keyboard_->updateKeyboard(ev);
    if (updated) {
        positions_->enableFinger(updated->associatedFinger());
    }
}

void TPresentation::keyReleaseEvent(QKeyEvent *ev) {
    TVirtualKey *updated = keyboard_->updateKeyboard(ev);
    if (updated) {
        positions_->disableFinger(updated->associatedFinger());
    }
}

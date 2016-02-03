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
    setupWidgets();
}

TPresentation::TPresentation(QString lang, QString charsToCopy, QWidget* parent) :
QWidget(parent),
keyboard_(new TVirtualKeyboard(lang)),
positions_(new TFingerPosition()) {
    setupWidgets();
    if (!charsToCopy.isEmpty()) {
        for (auto elem : charsToCopy) {
            keyboard_->highlightKey(elem);
        }
    }
}

void TPresentation::setupWidgets() {
    QVBoxLayout *lay = new QVBoxLayout();
    lay->addWidget(keyboard_);
    lay->addWidget(positions_, 0, Qt::AlignHCenter);
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

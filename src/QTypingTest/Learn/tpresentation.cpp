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
positions_(new TFingerPosition()),
toPress_(charsToCopy) {
    setupWidgets();
    nextCharToCopy();

}

void TPresentation::nextCharToCopy() {
    if (!toPress_.isEmpty()) {
        currentExample_ = toPress_[0];
        TVirtualKey* hilighted = keyboard_->highlightKey(currentExample_);
        if (hilighted) {
            positions_->enableFinger(hilighted->associatedFinger());
            toPress_ = toPress_.remove(0,1);
        }
    } else {
        emit allCopied();
    }
}

void TPresentation::setupWidgets() {
    QVBoxLayout *lay = new QVBoxLayout();
    lay->addWidget(keyboard_);
    lay->addWidget(positions_, 0, Qt::AlignHCenter);
    setLayout(lay);
}

void TPresentation::keyPressEvent(QKeyEvent *ev) {
    if (currentExample_.isNull()) {
        TVirtualKey *updated = keyboard_->updateKeyboard(ev);
        if (updated) {
            positions_->enableFinger(updated->associatedFinger());
        }
    } else {
        keyboard_->updateKeyboard(ev, currentExample_);
    }
}

void TPresentation::keyReleaseEvent(QKeyEvent *ev) {
    
    if (currentExample_.isNull()) {
        TVirtualKey *updated = keyboard_->updateKeyboard(ev);
        if (updated) {
            positions_->disableFinger(updated->associatedFinger());
        }
    } else {
        TVirtualKey *rightKey = keyboard_->updateKeyboard(ev,currentExample_);
        if(rightKey){
            positions_->disableFinger(rightKey->associatedFinger());
            nextCharToCopy();
        }
    }
}

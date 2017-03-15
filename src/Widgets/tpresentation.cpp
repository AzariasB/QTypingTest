/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */

/* 
 * File:   tpresentation.cpp
 * Author: boutina
 * 
 * Created on 31 janvier 2016, 15:38
 */

#include "tpresentation.h"

#include "tapplication.h"

TPresentation::TPresentation(TLayout&layout, QWidget* parent) :
QWidget(parent),
keyboard_(new TVirtualKeyboard(layout)),
positions_(new TFingerPosition()) {
    setupWidgets();
}

TPresentation::TPresentation(TLayout&layout, QString charsToCopy, QWidget* parent) :
QWidget(parent),
keyboard_(new TVirtualKeyboard(layout)),
positions_(new TFingerPosition()){

	foreach (QChar c, charsToCopy) {
		toPress_.enqueue(c);
	}


    setupWidgets();
    nextCharToCopy();

}

void TPresentation::nextCharToCopy() {
	if (!toPress_.isEmpty()) {
		QChar current = toPress_.head();
		TVirtualKey* hilighted = keyboard_->highlightKey(current);
        if (hilighted) {
            positions_->enableFinger(hilighted->associatedFinger());
        }
		if(tApp.getLayout().needsShiftModifier(current)){
			//If left hand needed for character => right shift, else, left shift
			short shiftSide = TFingerPosition::isLeftHand(hilighted->associatedFinger()) ? 1 : 0;
			TVirtualKey *shift = keyboard_->highlightShift(shiftSide);
            if(shift){
                positions_->enableFinger(shift->associatedFinger() );
            }
        }

		if(tApp.getLayout().needsAltgrModifier(current)){
            TVirtualKey *altGr = keyboard_->highlightModifier(Qt::Key_AltGr);
            if(altGr){
                positions_->enableFinger(altGr->associatedFinger() );
            }
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
	if (toPress_.isEmpty()) {
        TVirtualKey *updated = keyboard_->updateKeyboard(ev);
        if (updated) {
            positions_->enableFinger(updated->associatedFinger());
        }
    } else {
		keyboard_->updateKeyboard(ev, toPress_.head());
		QString txt = ev->text();
		if(!txt.isEmpty() && toPress_.head() == txt[0] ){
			toPress_.dequeue();
			keyboard_->reset();
			positions_->reset();
			nextCharToCopy();
		}
    }
}

void TPresentation::keyReleaseEvent(QKeyEvent *ev) {

	if (toPress_.isEmpty()) {
		TVirtualKey *updated = keyboard_->updateKeyboard(ev);
		if (updated) {
			positions_->disableFinger(updated->associatedFinger());
		}
	} else {
		TVirtualKey *rightKey = keyboard_->updateKeyboard(ev,toPress_.head());
		if(rightKey){
			positions_->disableFinger(rightKey->associatedFinger());
		}
	}
}

/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */
/* 
 * File:   TVirtualKeyboard.cpp
 * Author: boutina
 * 
 * Created on 27 janvier 2016, 10:32
 */

#include "tvirtualkeyboard.h"
#include "tapplication.h"

using namespace Qt;

TVirtualKeyboard::TVirtualKeyboard(const TVirtualKeyboard& orig) :
QWidget(orig.parentWidget()),
keys_(orig.getKeys()),
modifiers_(new QHash<int, TVirtualKey*>()) {

}

TVirtualKeyboard::TVirtualKeyboard(TLayout&layout, QWidget* parent) :
QWidget(parent),
keys_(new QHash<uint, TVirtualKey*>()),
modifiers_(new QHash<int, TVirtualKey*>()) {
    setupWidget(layout);
}

void TVirtualKeyboard::setupWidget(TLayout&layout) {
    leftShift_ = new TVirtualKey(55, "Shift", TFingerPosition::LEFT_PINKY );
    rightShift_ = new TVirtualKey(155, "Shift", TFingerPosition::RIGHT_PINKY );
    modifiers_->insert(Qt::Key_Shift,leftShift_);
    //Insert right shift
    createKeys(layout.getLayouLines());
}

void TVirtualKeyboard::createKeys(QList<QStringList> keyChars) {
    QVBoxLayout *mainLay = new QVBoxLayout();
    for (int i = 0; i < keyChars.size(); i++) {
        QStringList lst = keyChars[i];
        QWidget *line;
        switch (i) {
            case 0: line = numberLine(lst);
                break;
            case 1: line = upperLine(lst);
                break;
            case 2: line = middleLine(lst);
                break;
            case 3: line = bottomLine(lst);
                break;
        }
        mainLay->addWidget(line, AlignLeft);
    }
    mainLay->addWidget(spaceBarLine());
    mainLay->setContentsMargins(0, 0, 0, 0);
    this->setLayout(mainLay);
}

QWidget *TVirtualKeyboard::numberLine(QStringList keys) {
    QWidget *line = new QWidget();
    QHBoxLayout *lay = new QHBoxLayout();
    //Create the '²' key
    lay->addWidget(createKey("²"));
    for (auto elem : keys) {
        lay->addWidget(createKey(elem));
    }
    //The 'backspace' key
    TVirtualKey *backspace = new TVirtualKey(130, "Backspace", TFingerPosition::RIGHT_PINKY);
    lay->addWidget(backspace);
	keys_->insert(Qt::Key_Backspace, backspace);
    lay->setContentsMargins(0, 0, 0, 0);
    line->setLayout(lay);
    return line;
}

QWidget *TVirtualKeyboard::upperLine(QStringList keys) {
    QWidget *line = new QWidget();
    QHBoxLayout *lay = new QHBoxLayout();
    //The 'tab' key
    TVirtualKey *tab = new TVirtualKey(70, "Tab", TFingerPosition::LEFT_PINKY );
    lay->addWidget(tab);
	keys_->insert(Qt::Key_Tab, tab);
	keys_->insert(Qt::Key_Backtab, tab);

    for (auto elem : keys) {
		lay->addWidget(createKey(elem));
    }
    //The upper part of the 'enter' key
    lay->addWidget(new TVirtualKey(80, "Enter", TFingerPosition::RIGHT_PINKY));
    lay->setContentsMargins(0, 0, 0, 0);
    line->setLayout(lay);
    return line;
}

QWidget *TVirtualKeyboard::middleLine(QStringList keys) {
    QWidget *line = new QWidget();
    QHBoxLayout *lay = new QHBoxLayout();
    //The 'caps lock' key
    TVirtualKey *capsLock = new TVirtualKey(80, "Caps lock", TFingerPosition::RIGHT_PINKY);
    lay->addWidget(capsLock);
	keys_->insert(Key_CapsLock, capsLock);

    int index = 0;
    for (auto elem : keys) {
        TVirtualKey *key = createKey(elem);
        if (index == 3 || index == 6) {
            //Underline
            QString underLine = QString("<u>") + key->getShift() + QString("</u>");
            key->setText(underLine);
        }
        lay->addWidget(key);
        index++;
    }
    //The lower part of the 'enter' key
    TVirtualKey *lowerEnter = new TVirtualKey(70, "Enter", TFingerPosition::RIGHT_PINKY);
    lay->addWidget(lowerEnter);
    lay->setContentsMargins(0, 0, 0, 0);
	keys_->insert(Qt::Key_Return, lowerEnter);
    line->setLayout(lay);
    return line;
}

QWidget *TVirtualKeyboard::bottomLine(QStringList keys) {
    QWidget *line = new QWidget();
    QHBoxLayout *lay = new QHBoxLayout();
    //The left 'shift' key
    lay->addWidget(leftShift_);
    for (auto elem : keys) {
        lay->addWidget(createKey(elem));
    }
    //The right 'shift' key
    lay->addWidget(rightShift_);
    //The 'up' key
    lay->addWidget(new TVirtualKey(50, ""));
    lay->setContentsMargins(0, 0, 0, 0);
    line->setLayout(lay);
    return line;
}

TVirtualKey *TVirtualKeyboard::createKey(QString attributes) {
    TVirtualKey *key = new TVirtualKey(attributes);
    switch (attributes.size()) {
        case 4:
			keys_->insert(getKeyCode( attributes[3] ), key);//no break
        case 3:
			keys_->insert(getKeyCode( attributes[2] ), key);//no break
        case 2:
			keys_->insert(getKeyCode( attributes[1] ), key);//STOP !
            break;
    }
    return key;
}

uint TVirtualKeyboard::getKeyCode(QChar c)
{
	return QKeySequence(QString(c))[0];
}

QWidget* TVirtualKeyboard::spaceBarLine() {
    QWidget *line = new QWidget();
    QHBoxLayout *lay = new QHBoxLayout();

    TVirtualKey *ctrl = new TVirtualKey(55, "Ctrl", TFingerPosition::LEFT_PINKY);
    lay->addWidget(ctrl);
    modifiers_->insert(Key_Control, ctrl);

    lay->addWidget(new TVirtualKey(50, "Fn")); //Change from laptop to computer

    TVirtualKey *home = new TVirtualKey(50, "Win", TFingerPosition::LEFT_PINKY);
    lay->addWidget(home);
	modifiers_->insert(Key_Meta, home);

	TVirtualKey *alt = new TVirtualKey(50, "Alt", TFingerPosition::LEFT_INCH);
    lay->addWidget(alt);
    modifiers_->insert(Key_Alt, alt);

    TVirtualKey *space = new TVirtualKey(350, "Space");
    lay->addWidget(space);
	keys_->insert(Qt::Key_Space, space);

	TVirtualKey *altGr = new TVirtualKey(55, "AltGr", TFingerPosition::RIGHT_INCH);
    lay->addWidget(altGr);
    modifiers_->insert(Key_AltGr, altGr);

    lay->addWidget(new TVirtualKey(50, "Opt"));
    lay->addWidget(new TVirtualKey(50, ""));
    lay->addWidget(new TVirtualKey(50, ""));

    lay->setContentsMargins(0, 0, 0, 0);
    line->setLayout(lay);
    return line;
}

TVirtualKey* TVirtualKeyboard::updateKeyboard(QKeyEvent* ev, QChar expected) {
    TVirtualKey *target = 0;
	bool needsModifier = !tApp.getLayout().needsNoModifier(expected);
    bool wrongKey = !expected.isNull() && !needsModifier;

	if (ev->key() == Qt::Key_Shift) {
        // \todo : is that working on other machines ?
        target = ev->nativeScanCode() == 62 ? rightShift_ : leftShift_;
    } else if (modifiers_->contains(ev->key())) {
        target = modifiers_->value(ev->key());
	} else {
		uint keyCode = ev->key();
		if (keys_->contains(keyCode)) {
			target = keys_->value(keyCode);
			wrongKey = !expected.isNull() && ev->text() != expected;
        }
    }

    if (target) {
        if (ev->type() == QEvent::KeyPress) {
            if (wrongKey) {
                target->wrong();
                return 0;
            } else {
				if(needsModifier && ev->text().isEmpty()){
					if((tApp.getLayout().needsShiftModifier(expected) && ev->key() == Qt::Key_Shift) ||
							(tApp.getLayout().needsAltgrModifier(expected) && ev->key() == Qt::Key_AltGr)){
                        target->right();
                    }else{
                        target->wrong();
                    }
                }else{
                    target->right();
                }
            }
        } else if (ev->type() == QEvent::KeyRelease) {
			setOriginalState(target, ev, expected);
			if(expected.isNull()) return target;
			if (wrongKey || !tApp.getLayout().needsNoModifier(expected)) return 0;
        }
    }
    return target;
}

void TVirtualKeyboard::setOriginalState(TVirtualKey *key, QKeyEvent *ev, QChar expected)
{
	if(expected.isNull()){
		key->reset();
		return;
	}


	bool altgrReset = ev->key() == Qt::Key_AltGr && tApp.getLayout().needsAltgrModifier(expected);
	bool textReset = ev->text().size() > 0 && key->possibleToType(expected) && ev->text() != expected;

	bool shiftReset = false;
	if(ev->key() == Qt::Key_Shift && tApp.getLayout().needsShiftModifier(expected)){
		qDebug() << expected;
		TVirtualKey *needed = keys_->value(getKeyCode(expected));
		shiftReset = (TFingerPosition::isLeftHand(needed->associatedFinger()) && key == rightShift_) ||
					(TFingerPosition::isRightHand(needed->associatedFinger()) && key == leftShift_);
	}

	if(altgrReset || textReset || shiftReset){
		// Typed right key, but not the good content
		key->example();
	}else{
		key->reset();
	}
}


TVirtualKey* TVirtualKeyboard::highlightKey(QChar keyChar) {
	uint keyCode = getKeyCode(keyChar);
	if (keys_->contains(keyCode)) {
		TVirtualKey *target = keys_->value(keyCode);
        target->example();
        return target;
    }
    return 0;
}


TVirtualKey *TVirtualKeyboard::highlightModifier(int modId)
{
    if(modifiers_->contains(modId)){
        TVirtualKey *target = modifiers_->value(modId);
        target->example();
        return target;
    }
    return 0;
}


void TVirtualKeyboard::reset(){
	leftShift_->reset();
	rightShift_->reset();
	for(auto it = keys_->begin(); it != keys_->end();++it){
		it.value()->reset();
	}
	for(auto it = modifiers_->begin(); it != modifiers_->end(); ++it){
		it.value()->reset();
	}
}

TVirtualKey *TVirtualKeyboard::highlightShift(short index){
	if(index == 0){
		leftShift_->example();
		return leftShift_;
	}else if(index == 1){
		rightShift_->example();
		return rightShift_;
	}
	return 0;
}

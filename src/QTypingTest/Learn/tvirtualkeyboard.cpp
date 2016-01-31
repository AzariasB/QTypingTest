/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */
/* 
 * File:   TVirtualKeyboard.cpp
 * Author: boutina
 * 
 * Created on 27 janvier 2016, 10:32
 */

#include <qt5/QtCore/qlogging.h>

#include "tvirtualkeyboard.h"

using namespace Qt;

TVirtualKeyboard::TVirtualKeyboard(const TVirtualKeyboard& orig) :
QWidget(orig.parentWidget()),
keys_(orig.getKeys()),
modifiers_(new QHash<int, TVirtualKey*>()) {
}

TVirtualKeyboard::TVirtualKeyboard(QString lang, QWidget* parent) :
QWidget(parent),
keys_(new QHash<QChar, TVirtualKey*>()),
modifiers_(new QHash<int, TVirtualKey*>()) {
    setupWidget(lang);
}

void TVirtualKeyboard::setupWidget(QString lan) {
    leftShift_ = new TVirtualKey(55, "Shift");
    rightShift_ = new TVirtualKey(155, "Shift");


    QString layouts = file::readFile("etc/layouts.txt");
    QString config = findCorrespondingLayout(layouts, lan);
    if (config.isEmpty()) {
        qDebug() << "No correct config found";
    } else {
        QList<QStringList> * keys = decomposeLayout(config);
        createKeys(keys);
    }
}

void TVirtualKeyboard::createKeys(QList<QStringList>* keyChars) {
    QVBoxLayout *mainLay = new QVBoxLayout();
    for (int i = 0; i < keyChars->size(); i++) {
        QStringList lst = keyChars->at(i);
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
    TVirtualKey *backspace = new TVirtualKey(130, "Backspace");
    lay->addWidget(backspace);
    modifiers_->insert(Key_Backspace, backspace);

    line->setLayout(lay);
    return line;
}

QWidget *TVirtualKeyboard::upperLine(QStringList keys) {
    QWidget *line = new QWidget();
    QHBoxLayout *lay = new QHBoxLayout();
    //The 'tab' key
    TVirtualKey *tab = new TVirtualKey(70, "Tab");
    lay->addWidget(tab);
    modifiers_->insert(Key_Tab, tab);
    modifiers_->insert(Key_Backtab, tab);

    for (auto elem : keys) {
        lay->addWidget(createKey(elem));
    }
    //The upper part of the 'enter' key
    lay->addWidget(new TVirtualKey(80, "Enter"));
    line->setLayout(lay);
    return line;
}

QWidget *TVirtualKeyboard::middleLine(QStringList keys) {
    QWidget *line = new QWidget();
    QHBoxLayout *lay = new QHBoxLayout();
    //The 'caps lock' key
    TVirtualKey *capsLock = new TVirtualKey(80, "Caps lock");
    lay->addWidget(capsLock);
    modifiers_->insert(Key_CapsLock, capsLock);

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
    TVirtualKey *lowerEnter = new TVirtualKey(70, "Enter");
    lay->addWidget(lowerEnter);
    modifiers_->insert(Key_Return, lowerEnter);

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
    line->setLayout(lay);
    return line;
}

TVirtualKey *TVirtualKeyboard::createKey(QString attributes) {
    TVirtualKey *key = new TVirtualKey(attributes);
    switch (attributes.size()) {
        case 4:
            keys_->insert(attributes[3], key);
        case 3:
            keys_->insert(attributes[2], key);
        case 2:
            keys_->insert(attributes[1], key);
            break;
    }
    return key;
}

QWidget* TVirtualKeyboard::spaceBarLine() {
    QWidget *line = new QWidget();
    QHBoxLayout *lay = new QHBoxLayout();

    TVirtualKey *ctrl = new TVirtualKey(55, "Ctrl");
    lay->addWidget(ctrl);
    modifiers_->insert(Key_Control, ctrl);

    lay->addWidget(new TVirtualKey(50, "Fn")); //Change from laptop to computer

    TVirtualKey *home = new TVirtualKey(50, "Win");
    lay->addWidget(home);
    modifiers_->insert(Key_Meta, home);

    TVirtualKey *alt = new TVirtualKey(50, "Alt");
    lay->addWidget(alt);
    modifiers_->insert(Key_Alt, alt);

    TVirtualKey *space = new TVirtualKey(350, "Space");
    lay->addWidget(space);
    modifiers_->insert(Key_Space, space);

    TVirtualKey *altGr = new TVirtualKey(55, "AltGr");
    lay->addWidget(altGr);
    modifiers_->insert(Key_AltGr, altGr);

    lay->addWidget(new TVirtualKey(50, "Opt"));
    lay->addWidget(new TVirtualKey(50, ""));
    lay->addWidget(new TVirtualKey(50, ""));
    line->setLayout(lay);
    return line;
}

QList<QStringList> *TVirtualKeyboard::decomposeLayout(QString layout) {
    QStringList lines = layout.split("$$", QString::SkipEmptyParts);
    if (lines.size() != 4) {
        qDebug() << "Incorrect config, the keyboard must have 4 lines";
        return new QList<QStringList>();
    } else {
        QList<QStringList> *parts = new QList<QStringList>();
        for (auto elem : lines) {
            parts->append(elem.trimmed().split(" ", QString::SkipEmptyParts));
        }
        return parts;
    }

}

QString TVirtualKeyboard::findCorrespondingLayout(QString config, QString lang) {
    QRegExp decomposition("\\$\\$(\\n\\n|$)");
    //Split all the possible configurations
    QStringList configs = config.split(decomposition, QString::SkipEmptyParts);

    //Find the one that begins with 'lang'
    QStringList filt = configs.filter(QRegExp("^" + lang + ":"));

    if (filt.isEmpty()) {
        //No config found, return empty String
        return "";
    } else {
        //Take the first one (even if there are several same configs)
        //Remove the lang (we don't need it anymore, and spaces at beginning/end of the string)
        return filt[0].mid(lang.size() + 1).trimmed();

    }
}

TVirtualKey* TVirtualKeyboard::updateKeyboard(QKeyEvent* ev) {
    TVirtualKey *target = 0;
    if (ev->key() == Key_Shift) {
        //TODO : is that working on other machines ?
        target = ev->nativeScanCode() == 62 ? rightShift_ : leftShift_;
    } else if (modifiers_->contains(ev->key())) {
        target = modifiers_->value(ev->key());
    } else if (!ev->text().isEmpty()) {
        QChar txt = ev->text()[0];
        if (keys_->contains(txt)) {
            target = keys_->value(txt);
        }
    }
    if(target){
        if(ev->type() == QEvent::KeyPress){
            target->right();
        }else if(ev->type() == QEvent::KeyRelease){
            target->reset();
        }
    }
    return target;
}
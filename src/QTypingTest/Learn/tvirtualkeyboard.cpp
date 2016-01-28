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
keys_(orig.getKeys()) {
}

TVirtualKeyboard::TVirtualKeyboard(QString lang, QWidget* parent) :
QWidget(parent),
keys_(new QHash<QChar, QList<TVirtualKey*> >()) {
    setupWidget(lang);
}

void TVirtualKeyboard::setupWidget(QString lan) {
    leftShift_ = new TVirtualKey(55, "Shift");
    rightShift_ = new TVirtualKey(155, "Shift");
    altGr_ = new TVirtualKey(55, "AltGr");

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
    lay->addWidget(new TVirtualKey(130, "Backspace"));
    line->setLayout(lay);
    return line;
}

QWidget *TVirtualKeyboard::upperLine(QStringList keys) {
    QWidget *line = new QWidget();
    QHBoxLayout *lay = new QHBoxLayout();
    //The 'tab' key
    lay->addWidget(new TVirtualKey(70, "Tab"));
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
    lay->addWidget(new TVirtualKey(80, "Caps lock"));
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
    lay->addWidget(new TVirtualKey(70, "Enter"));
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
    QList<TVirtualKey*> combin;
    QList<TVirtualKey*> oldKeys;
    TVirtualKey *key;
    switch (attributes.size()) {
        case 1:
            key = new TVirtualKey(attributes[0]);
            combin.append(key);
            keys_->insert(attributes[0], combin);
            return key;
        case 2:
            key = new TVirtualKey(attributes[0], attributes[1]);
            combin.append(key);
            combin.append(leftShift_);
            //Add the the hash
            keys_->insert(attributes[1], combin);
            createKey(attributes.mid(0, 1));

            //update the sub-key
            oldKeys = keys_->value(attributes[0]);
            oldKeys.replace(0, key);
            keys_->insert(attributes[0], oldKeys);
            return key;

        case 3:
            //Create the key with alt,shift,and default
            key = new TVirtualKey(attributes[0], attributes[1], attributes[2]);

            //Add to the list of combinaisons
            combin.append(key);
            combin.append(altGr_);

            //Add the the hash
            keys_->insert(attributes[2], combin);
            createKey(attributes.mid(0, 2));

            //update the sub-key
            oldKeys = keys_->value(attributes[1]);
            oldKeys.replace(0, key);
            keys_->insert(attributes[1], oldKeys);

            //and the sub-sub key
            oldKeys = keys_->value(attributes[0]);
            oldKeys.replace(0, key);
            keys_->insert(attributes[0], oldKeys);

            return key;

        default: return new TVirtualKey(); //Must NOT happen
    }
}

QWidget* TVirtualKeyboard::spaceBarLine() {
    QWidget *line = new QWidget();
    QHBoxLayout *lay = new QHBoxLayout();

    lay->addWidget(new TVirtualKey(55, "Ctrl"));
    lay->addWidget(new TVirtualKey(50, "Fn"));
    lay->addWidget(new TVirtualKey(50, "Win"));
    lay->addWidget(new TVirtualKey(50, "Alt"));
    lay->addWidget(new TVirtualKey(350, "Space"));
    lay->addWidget(altGr_);
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

void TVirtualKeyboard::keyPressEvent(QKeyEvent *ev) {
    if (!ev->text().isEmpty()) {
        QChar txt = ev->text()[0];
        QList<TVirtualKey*> pressed = keys_->value(txt);
        for (auto key : pressed) {
            key->right();
        }
    }
}

void TVirtualKeyboard::keyReleaseEvent(QKeyEvent *ev) {
    if (!ev->text().isEmpty()) {
        QChar txt = ev->text()[0];
        QList<TVirtualKey*> pressed = keys_->value(txt);
        for (auto key : pressed) {
            key->reset();
        }
    }
}

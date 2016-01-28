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
keys_(new QList<TVirtualKey*>()) {
    QString layouts = file::readFile("etc/layouts.dat");
}

TVirtualKeyboard::TVirtualKeyboard(QString lang, QWidget* parent) :
QWidget(parent),
keys_(new QList<TVirtualKey*>()) {
    QString layouts = file::readFile("etc/layouts.dat");
    QString config = findCorrespondingLayout(layouts, lang);
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
        //        qDebug() << ↑*line;
        mainLay->addWidget(line, AlignLeft);
    }
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
    lay->addWidget(new TVirtualKey(55, "Shift"));
    for (auto elem : keys) {
        lay->addWidget(createKey(elem));
    }
    //The right 'shift' key
    lay->addWidget(new TVirtualKey(150, "Shift"));
    //The 'up' key
    //    lay->addWidget(new TVirtualKey('↑'));
    line->setLayout(lay);
    return line;
}

TVirtualKey *TVirtualKeyboard::createKey(QString attributes) {
    switch (attributes.size()) {
        case 1: return new TVirtualKey(attributes[0]);
        case 2: return new TVirtualKey(attributes[0], attributes[1]);
        case 3: return new TVirtualKey(attributes[0], attributes[1], attributes[2]);
        default: return new TVirtualKey();
    }
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


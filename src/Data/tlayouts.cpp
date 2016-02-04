/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */
/* 
 * File:   tlayouts.cpp
 * Author: boutina
 * 
 * Created on 17 décembre 2015, 11:35
 */


#include "tlayouts.h"

QString TLayouts::allAvailableLetters_("");
TLayouts TLayouts::instance("fr");

void TLayouts::initLetters(QString lang) {
    QString layouts = file::readFile("etc/layouts.txt");
    QString config = findCorrespondingLayout(layouts, lang);
    if (config.isEmpty()) {
        qDebug() << "No correct config found";
    } else {
        lettersList_ = QStringList(); // reset the lettersList
        TLayouts::allAvailableLetters_ = "";
        layoutLines_ = decomposeLayout(config);
    }
}

QList<QStringList> *TLayouts::decomposeLayout(QString layout) {
    QStringList lines = layout.split("\n", QString::SkipEmptyParts);
    if (lines.size() != 4) {
        qDebug() << "Incorrect config, the keyboard must have 4 lines";
        return new QList<QStringList>();
    } else {
        QList<QStringList> *parts = new QList<QStringList>();
        for (auto elem : lines) {
            //Add the whole line to the 
            QStringList splitedLine = elem.trimmed().split(" ", QString::SkipEmptyParts);
            parts->append(splitedLine);
            TLayouts::allAvailableLetters_ += splitedLine.replaceInStrings(QRegExp("^\\d"), "").join("");
        }
        return parts;
    }

}

QString TLayouts::findCorrespondingLayout(QString config, QString lang) {
    QRegExp decomposition("(\\n\\n|$)");
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

QStringList TLayouts::getLetterList() {
    if (lettersList_.isEmpty()) {
        //Adding the 'basics' letters (if any)
        //then the 'shifted' letters (if any)
        //and finally the 'altgred' letters (if any)
        for (int j = 1; j <= 3; j++) {
            for (int i = 0; i < 21; i++) {
                int *elem = listOrder_[i];
                QStringList curLine = layoutLines_->at(elem[0]);
                QString wordLeft = curLine[elem[1]];
                QString wordRight = curLine[elem[2]];
                wordLeft = j < wordLeft.size() ? QString(wordLeft[j]) : "";
                wordRight = j < wordRight.size() ? QString(wordRight[j]) : "";
                if (!(wordLeft + wordRight).isEmpty()) {
                    lettersList_ << wordLeft + wordRight;
                }
            }
        }
    }
    return lettersList_;
}
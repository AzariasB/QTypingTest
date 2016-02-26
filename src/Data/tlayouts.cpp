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


void TLayouts::initLetters(QString layout, QString country) {
    QString layouts = file::readFile("etc/layouts.txt");
    findAvailableLangs(layouts);
    QString config = findCorrespondingLayout(layouts, layout, country);
    if (config.isEmpty()) {
        layoutLines_ = new QList<QStringList>;
        qDebug() << "No correct config found";
    } else {
        lettersList_ = QStringList(); // reset the lettersList
        TLayouts::allAvailableLetters_ = "";
        layoutLines_ = decomposeLayout(config);
    }
}

void TLayouts::findAvailableLangs(const QString &fileContent){
    QRegExp ex("^([a-z]{2,})(-([A-Z]{2,}))?(?=:)[\\d\\D]*");
    QStringList match = fileContent.split("\n\n");
    match.replaceInStrings(ex,"\\1 (\\3)");
    match.replaceInStrings("()","");
    TLayouts::setAvailableLangs(match);
}

QList<QStringList> *TLayouts::decomposeLayout(QString layout) {
    QStringList lines = layout.split("\n", QString::SkipEmptyParts);
    if (lines.size() != 4) {
        qDebug() << "Incorrect config, the keyboard must have 4 lines of config";
        return new QList<QStringList>();
    } else {
        QList<QStringList> *parts = new QList<QStringList>;
        for (auto elem : lines) {
            //Add the whole splitted line to the main lines
            QStringList splitedLine = elem.trimmed().split(" ", QString::SkipEmptyParts);
            parts->append(splitedLine);
            //Remove the first number of each string of the list (since it's not a char of the keyboard)
            //but an indication to tell the corresponding finger
            //And join all the rest
            TLayouts::allAvailableLetters_ += splitedLine.replaceInStrings(QRegExp("^\\d"), "").join("");
        }
        return parts;
    }

}

QString TLayouts::findCorrespondingLayout(QString config, QString layout, QString country) {
    if(!country.isEmpty()){
        country = "-" + country;
    }
    QRegExp decomposition("(\\n\\n|$)");
    //Split all the possible configurations
    QStringList configs = config.split(decomposition, QString::SkipEmptyParts);

    //Find the one that begins with 'layout' (and has a country if country is not empty)
    QStringList filt = configs.filter(QRegExp("^" + layout + country + ":"));

    if (filt.isEmpty()) {
        //No correct config found, return empty String
        return "";
    } else {
        //Take the first one (even if there are several same configs)
        //Remove the lang (we don't need it anymore, and spaces at beginning/end of the string)
        return filt[0].mid(filt[0].indexOf(':')+1).trimmed();

    }
}

QStringList TLayouts::getLetterList() {
    if(layoutLines_->isEmpty())
        return QStringList();
    if (lettersList_.isEmpty()) {
        //Adding the 'basics' letters (if any)
        //then the 'shifted' letters (if any)
        //and finally the 'altgred' letters (if any)
        for (int j = 1; j <= 3; j++)
        {
            for (int i = 0; i < 21; i++)
            {
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

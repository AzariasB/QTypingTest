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
    QString layouts = factory::readFile(":/layouts.json");// \todo : create multiple json files for multiples locales
    QJsonDocument doc = QJsonDocument::fromJson(layouts.toUtf8());
    if(doc.isNull()){
        qDebug() << "File not found or not valid json";
        return;// \todo : less brutal end (Azarias)
    }

    QJsonObject jsonLays = doc.object();
    findAvailableLangs(jsonLays["layouts"]);//Get all the keys !

    QString firstLang = availableLangs_[0];//take first. \todo : qt will take the good file to parse for us ! (Azarias)

    if (firstLang.isEmpty()) {
        layoutLines_ = new QList<QStringList>;
        qDebug() << "No correct config found";
    } else {
        // \todo : check to avoid parsing twice the same file
        lettersList_ = QStringList(); // reset the lettersList
        TLayouts::allAvailableLetters_ = "";
        layoutLines_ = decomposeLayout(jsonLays["layouts"].toObject()[firstLang].toObject());
    }
}

void TLayouts::findAvailableLangs(const QJsonValue& doc){
    QStringList langs;
    if(doc.isNull() || !doc.isObject() )
    {
        qDebug() << "Json not well configured";
    }else
    {
        QJsonObject obj = doc.toObject();
        for(auto it = obj.begin();it != obj.end(); ++it){
            langs << it.key();
        }
    }
    setAvailableLangs(langs);
}

QList<QStringList> *TLayouts::decomposeLayout(const QJsonObject &layout) {
    QJsonArray arr = layout["rows"].toArray();

    if (arr.size() != 4) {
        qDebug() << "Incorrect config, the keyboard must have 4 lines of config";
        return new QList<QStringList>();
    } else {
        QRegExp isLetter("[a-z]");
        QList<QStringList> *parts = new QList<QStringList>;
        for (auto elem : arr) {
            QJsonArray theArr = elem.toArray();
            //Add the whole splitted line to the main lines
            QStringList splitedLine;
            QString total = "";
            for(auto keyInfo : theArr){
                QJsonObject keyObj = keyInfo.toObject();
                QString main = keyObj["main"].toString();
                if(isLetter.exactMatch(main)){
                    main += main.toUpper();
                }
                main += keyObj["shift"].toString() + keyObj["altgr"].toString();
                total += main;
                splitedLine << QString::number(keyObj["finger"].toInt()) + main;
            }
            //Remove the first number of each string of the list (since it's not a char of the keyboard)
            //but an indication to tell the corresponding finger
            //And join all the rest
            parts->append(splitedLine);
            TLayouts::allAvailableLetters_ += total;
        }
        return parts;
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
                QString charLeft = curLine[elem[1]];
                QString charRight = curLine[elem[2]];
                charLeft = j < charLeft.size() ? QString(charLeft[j]) : "";
                charRight = j < charRight.size() ? QString(charRight[j]) : "";
                if (!(charLeft + charRight).isEmpty()) {
                    lettersList_ << charLeft + charRight;
                }
            }
        }
    }
    return lettersList_;
}

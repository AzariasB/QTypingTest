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


void TLayouts::initLetters() {
    //Reads the file depending on the user's computers locale
    QString layouts = factory::readFile(":/layouts.json");
    QJsonDocument doc = QJsonDocument::fromJson(layouts.toUtf8());
    if(doc.isNull()){
        qDebug() << "File not found or not valid json";
        return;// \todo : less brutal end, and explain the exact error (Azarias)
    }

    QJsonObject jsonLays = doc.object();

    lettersList_ = QStringList(); // reset the lettersList
    TLayouts::allAvailableLetters_ = "";
    layoutLines_ = decomposeLayout(jsonLays["rows"]);
}

QList<QStringList> *TLayouts::decomposeLayout(const QJsonValue &rows) {
    QJsonArray arr = rows.toArray();

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

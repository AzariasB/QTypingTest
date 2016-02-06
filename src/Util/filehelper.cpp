/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */

/* 
 * File:   filehelper.cpp
 * Author: boutina
 * 
 * Created on 29 décembre 2015, 12:25
 */

#include "filehelper.h"

const QString WORDS_PATH = "words";
const QString IMAGES_PATH = "images";
const QString TEXT_PATH = "texts";
const QString WORDS_EXT = ".txt";
const QString STYLE_EXT = ".qss";
const QString ETC_PATH = "etc";

QString file::getWordsPath(QString lang) {
    return ETC_PATH + "/" + WORDS_PATH + "/" + lang + WORDS_EXT;
}

QString file::getPadlockIcon(bool open) {
    return ETC_PATH + "/" + "padlock_" + (open ? "open" : "closed") + ".png";
}

QString file::getStylesheet(QString stylesheetname) {
    return ETC_PATH + "/" + stylesheetname + STYLE_EXT;
}

QString file::getImagePath(QString imageName){
    return ETC_PATH + "/" + IMAGES_PATH + "/" + imageName;
}

QString file::getTextPath(QString lang) {
    return ETC_PATH + "/" + TEXT_PATH + "/" + lang + WORDS_EXT;
}

QString file::readFile(QString fileName) {
    QFile model(fileName);
    if (model.exists() && model.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QString res(model.readAll());
        return res;
    } else {//File not found
        if (!model.exists())
            qDebug() << "File does not exists : " + fileName + " \n Please, be sure to run the programm from its root folder";
        else
            qDebug() << "Could not open file";
        return QString("");
    }
}
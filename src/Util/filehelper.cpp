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
const QString WORDS_EXT = ".txt";
const QString ETC_PATH = "etc";

QString file::getWordsPath(QString lang){
    return ETC_PATH + "/" + WORDS_PATH + "/" + lang + WORDS_EXT;
}

QString file::getPadlockIcon(bool open){
    return ETC_PATH + "/" + "padlock_" + (open ? "open" : "closed") + ".png";
}

QString file::getStylesheet(QString stylesheetname){
    return ETC_PATH + "/" + stylesheetname + ".qss";
}
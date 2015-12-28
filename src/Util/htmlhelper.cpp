/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */

/* 
 * File:   HTMLHelper.cpp
 * Author: boutina
 * 
 * Created on 28 décembre 2015, 17:33
 */

#include "htmlhelper.h"

QString html::addTagToChars(QString strtToTag, QString tag) {
    QString replaced = QString("<%1>\\1</%1>").arg(tag);
    strtToTag.replace(QRegExp("(.)"), replaced);

    return strtToTag;
}

QString html::removeTag(QString strToClean, QString tag) {
    QString reg = QString("<\\/?%1>").arg(tag);
    return strToClean.replace(QRegExp(reg), "");
}

QString html::addTagAt(QString strToTag, QString tagName, int position) {
    QString regex;

    if (position == 0)
        regex = "(^.)";
    else if (position == strToTag.length() - 1)
        regex = "(.$)";
    else
        regex = QString("(.)(?=.{%1}$)").arg(strToTag.size() - 1 - position);

    QString replace = QString("<%1>\\1</%1>").arg(tagName);
    return strToTag.replace(QRegExp(regex), replace);
}

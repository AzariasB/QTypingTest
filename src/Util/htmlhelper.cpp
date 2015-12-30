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

QString surroundOfTags(QStringList tags){
    if(tags.size() == 1){
        return QString("<%1>\\1</%1>").arg(tags[0]);
    }else{
        return QString("<%1>%2</%1>")
                .arg(tags.takeFirst())
                .arg(surroundOfTags(tags.mid(1)));
    }
}

QString html::addTagToChars(QString strtToTag, QString tag) {
    QString replaced = QString("<%1>\\1</%1>").arg(tag);
    strtToTag.replace(QRegExp("(.)"), replaced);

    return strtToTag;
}

QString html::removeTag(QString strToClean, QString tag) {
    QString reg = QString("<\\/?%1>").arg(tag);
    return strToClean.replace(QRegExp(reg), "");
}

QString html::addTagsAt(QString strToTag, QString tags, int position) {
    QStringList splited = tags.split(",",QString::SkipEmptyParts);

    QString res = surroundOfTags(splited);
        
    QString regex;

    if (position == 0)
        regex = "(^.)";
    else if (position == strToTag.length() - 1)
        regex = "(.$)";
    else
        regex = QString("(.)(?=.{%1}$)").arg(strToTag.size() - 1 - position);

    return strToTag.replace(QRegExp(regex), res);
}

QString html::addTagAndClass(QString toTag, QString tag, QString theClass){
    return QString("<%1 class='%3'>%2</%1>").arg(tag).arg(toTag).arg(theClass);
}
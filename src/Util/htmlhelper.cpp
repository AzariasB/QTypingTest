/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */

/* 
 * File:   HTMLHelper.cpp
 * Author: boutina
 * 
 * Created on 28 décembre 2015, 17:33
 */

#include "htmlhelper.h"

/**
 * Little helper to create tags into tags and return a regex-ready string to add the text needed in the center
 * 
 * @param tags the list of tag to add around a char
 * @return a regex-ready string to add the needed text in the center of the tags
 */
QString surroundOfTags(QStringList tags, QString attributes) {
    if (tags.size() == 1) {
        if (!attributes.isEmpty()) {
            return QString("<%1 %2>\\1</%1>").arg(tags[0]).arg(attributes);
        } else {
            return QString("<%1>\\1</%1>").arg(tags[0]);
        }
    } else {
        return QString("<%1>%2</%1>")
                .arg(tags.takeFirst())
                .arg(surroundOfTags(tags.mid(1), attributes));
    }
}

int html::getAbsoluteCharPosition(QString string, int relativePos) {
    int i = 0;
    for (int c = 0; c < string.size(); c++) {
        if (string[c] == '<') {
            while (string[c] != '>' && c < string.size()) c++;
            continue;
        }
        if (i == relativePos) return c;
        i++;
    }
    //relativePos too far
    return -1;
}

QString html::addTagToChars(QString strtToTag, QString tag, QString attributes) {
    QString replaced;
    if (attributes.isEmpty()) {
        replaced = QString("<%1>\\1</%1>").arg(tag);
    } else {
        replaced = QString("<%1 %2>\\1</%1>").arg(tag).arg(attributes);
    }

    strtToTag.replace(QRegExp("(.)"), replaced);

    return strtToTag;
}

QString html::removeTag(QString &strToClean, QString tag) {
    QString reg = QString("<\\/?%1>").arg(tag);
    return strToClean.replace(QRegExp(reg), "");
}

QString html::addTags(QString &strToTag, QString tags, QString attributes) {
    QStringList splited = tags.split(",", QString::SkipEmptyParts);

    QString res = surroundOfTags(splited, attributes);
    int position = getAbsoluteCharPosition(strToTag, 0);

    QString regex;

    if (position == 0)
        regex = "(^.)";
    else if (position == strToTag.length() - 1)
        regex = "(.$)";
    else
        regex = QString("(.)(?=.{%1}$)").arg(strToTag.size() - 1 - position);

    strToTag = strToTag.replace(QRegExp(regex), res);
    return strToTag;
}
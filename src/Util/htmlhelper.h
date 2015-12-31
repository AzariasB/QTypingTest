/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */

/* 
 * File:   HTMLHelper.h
 * Author: boutina
 *
 * Created on 28 décembre 2015, 17:33
 */

#ifndef HTMLHELPER_H
#define HTMLHELPER_H

#include <QStringList>
#include <QRegExp>
#include <QDebug>


namespace html {
    /**
     * Add a tag around ALL the characters of a QString
     * 
     * @param strToTag the str where to add suround every char by a tag
     * @param tag the tag to surround with
     * @return the QString with all the chars surrounded by the tag
     */
    QString addTagToChars(QString strtToTag, QString tag);

    /**
     * Remove every tag in the QString.
     * If no tag is specified, all will be removed, else, only the tag passed in parameter.
     * 
     * @param strToClean the QString to clean
     * @param tag the tag to remove. If empty, all tags found will be removed
     * @return the cleaned QString
     */
    QString removeTag(QString &strToClean, QString tag = "([^>]*)");


    /**
     * Surround the QChar at position given in parameter by all the tags given
     * in parameter.
     * The tags mus be separated by a comma. For example "b,u" will add the tags "b" then "u".
     * It is possible to add some attributes into the FIRST surrounding tag
     * The function will also change the string passed in parameter
     * 
     * @param strToTag the QString to be tagged
     * @param tags the tags comma-separated to add to the character (e.g. "b,u")
     * @param attributes some optional attributes to add to arround the string
     * @return the String with the char tagged
     */
    QString addTags(QString &strToTag, QString tags,QString attributes = "");


    /**
     * Helper to get the exact position of a char, without taking in consideration
     * the HTML tags that makes the relative position falsy
     * For example int the string "<p>p</p>atrick"
     * the position of the first char is 3 (p) and not 0 (\<>)
     * 
     * @param string the string with some eventual html tags
     * @param relativePos the position of the searched char
     * @return the absolute position of the researched char, return -1 if the pos was not found (relativePos too big)
     */
    int getAbsoluteCharPosition(QString string, int relativePos);

}



#endif /* HTMLHELPER_H */


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
    QString removeTag(QString strToClean, QString tag = "([^>]*)");
    
    
    /**
     * Surround the QChar at position given in parameter by all the tags given
     * in parameter.
     * The tags mus be separated by a comma. For example "b,u" will add the tags "b" then "u".
     * 
     * @param strToTag the QString to be tagged
     * @param tags the tags comma-separated to add to the character (e.g. "b,u")
     * @param position the position of the char to tag
     * @return the String with the char tagged
     */
    QString addTagsAt(QString strToTag,QString tags,int position);

    /**
     * Return an HTML-element like with a tag and a class.
     * For exemple, if you pass "patrick", with tag= "p" and class="red"
     * it will return `\< p class="red">patrick\</\p>`
     * 
     * TODO: implement a larger choice of attributes, others than class (if needed)
     * 
     * @param toTag the String to be tagged
     * @param tag the tag to surround the string with
     * @param theClass the class to add to the qstring
     * @return the tagged and "classed" string
     */
    QString addTagAndClass(QString toTag,QString tag, QString theClass);
}



#endif /* HTMLHELPER_H */


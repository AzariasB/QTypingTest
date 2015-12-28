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
     * Surrond the Qchar at position(starting at 0) given in paramter by the tag also
     * given in parameter 
     * Precondition : The QString must contain one single line (no \n)
     * 
     * @param strToTag the QString to be tagged
     * @param tagName the name of the tag to add around the character (e.g. "a")
     * @param position the position of the character to tag
     * @return 
     */
    QString addTagAt(QString strToTag, QString tagName, int position);
}



#endif /* HTMLHELPER_H */


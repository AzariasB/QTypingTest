/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */

/* 
 * File:   filehelper.h
 * Author: boutina
 *
 * Created on 29 décembre 2015, 12:25
 */

#ifndef FILEHELPER_H
#define FILEHELPER_H


#include <QString>

extern const QString ETC_PATH;
extern const QString WORDS_PATH;
extern const QString WORDS_EXT;

namespace file{
    
    /**
     * Helper to find the most common word of a given langage
     * 
     * @param language the language of the file where the words are stored
     * @return the RELATIVE path to the file containing the most common words of the given langage
     */
    QString getWordsPath(QString lang);
}

#endif /* FILEHELPER_H */


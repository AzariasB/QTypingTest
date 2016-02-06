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
#include <QFile>
#include <QTextStream>
#include <QDebug>

extern const QString ETC_PATH;
extern const QString WORDS_PATH;
extern const QString WORDS_EXT;
extern const QString TEXT_PATH;
extern const QString STYLE_EXT;

namespace file{
    
    /**
     * Helper to easily have the path
     * to an image
     * 
     * @param imageName the name of the image
     * @return the relative path (from the project root) to the image
     */
    QString getImagePath(QString imageName);
    /**
     * Open and read all the content of a file
     * returns an empty string if the file could not be
     * open
     * 
     * @param fileName
     * @return the content of the file (empty if nothing found)
     */
    QString readFile(QString fileName);
    /**
     * Helper to find the most common word of a given langage
     * 
     * @param language the language of the file where the words are stored
     * @return the RELATIVE path to the file containing the most common words of the given langage
     */
    QString getWordsPath(QString lang);
    
    /**
     * Helper to find the file containing all the text
     * of a given language
     * 
     * @param lang The language of the file to find
     * @return the path of the file containg the texts
     */
    QString getTextPath(QString lang);
    
    /**
     * Helper to get the icons of the padlocks
     * 
     * @param open if the padlock is open or not !
     * @return the relative path to the image of the corresponding padlock
     */
    QString getPadlockIcon(bool open);
    
    /**
     * Return the path of the style file
     * 
     * @param stylesheetname the name of the file with the styl
     * @return the relative path to the .qss file containing the style
     */
    QString getStylesheet(QString stylesheetname);
}

#endif /* FILEHELPER_H */


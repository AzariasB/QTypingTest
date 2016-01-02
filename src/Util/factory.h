/*
 * QTypingTest by Pierre and Azarias
 * Licence : GPL2
 */

/* 
 * File:   TestCreator.h
 * Author: boutina
 *
 * Created on 14 décembre 2015, 20:41
 */

#ifndef FACTORY_H
#define FACTORY_H

#include <QStringList>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <algorithm>

#include "filehelper.h"



namespace factory {
    /**
     * This function generate the practice exercice from the given letters.
     * The result is devided into three parts :
     * <ul>
     *  <li>The first part is the letters that the user must learn, and only these</li>
     *  <li>The second part contains all the letters the user learned before so that he can train on all the letters</li>
     *  <li>The thirs parts contains the words that can be created with the letters the user learned before </li>
     * </ul>
     * NOTE : if no words can be made with the available letters, it will be replaced by a set of random letters
     * 
     * @param mainLetter the letter that the user is going to learn
     * @param allLetters all the available letters for the exercice
     * @return a random-generated list of words
     */
    QStringList generateLearning(QStringList mainLetter, QStringList allLetters);



    /**
     * Generate some random words with the available letters given in the list
     * 
     * @param letterList a list of 'authorized' letters
     * @param length length of the result string
     * @return a string with random words proposed in the given string list in parameter
     */
    QString generateFromLetters(QStringList letterList, int length = 50);
    
    /**
     * Generate existing words with the available letters
     * TODO : add a language parameter
     * 
     * @param authorizedLetters all the available chars to build a word
     * @param language the language of the file to find
     * @param mainLetters an optional QString. If existing, all the words must contain at least one letter of this string
     * @return a string with `numberOfWord` words separated by space.
     */
    QString generateWords(QString authorizedLetters, QString language, QString mainLetters = "");
    
    /**
     * Will look into a file (depending on the chosen langage)
     * and will find all the words that can be created with the given letters
     * 
     * @param authorizedLetters the letters that can compose the words 
     * @param fileName the path to the file containing all the words
     * @param mustContain a Qstring of letters that MUST be in the word
     * @return a list of word that can be created with the given letters
     */
    QStringList findExistingWords(QString authorizedLetters,QString filename,QString mustContain="");

    /**
     * Select one random element in the availables elements of the list
     * Helper to create exercices
     * 
     * @param listString a list of elements
     * @return a random-selected element in the list
     */
    QString selectRandomElement(QStringList listString);

}



#endif /* TESTCREATOR_H */


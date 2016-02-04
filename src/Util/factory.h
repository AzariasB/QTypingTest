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
#include <algorithm>

#include "filehelper.h"

namespace factory {
    
    
    /**
     * 
     * TODO : instead of passing lang in argument, get the 
     * language from the user's computer (Azarias)
     * 
     * This function will read the texts files of the project
     * corresponding to the language.
     * And will keep a random part of the text by keeping 
     * only the asked number of words
     * 
     * @param numbersOfWords the number of words for the text
     * @param lang the language of the text to generate
     * @return a part of a text containing n words, choosen from the file corresponding
     * to the given language. If the file does not exists, english is chosen by default
     */
    QString generateText(int numbersOfWords,QString lang = "en");
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
    QString generateLearning(QString mainLetter, QString allLetters);


    /**
     * Generates random words from the given list of letters
     * The string generated is a single big text of words
     * If onlyrealwords is true, the text will contains only `real` words so 
     * the user can train on existing words
     * otherwise, it will also contains some random-generated words
     * The size of the produced string is made to be contained in only ONE page
     * of an exercice.
     * 
     * TODO : add a parameter to choose the size of the text ? (Azarias)
     * 
     * @param letters the available letters
     * @param onlyRealWords if it must generates only words existing in a language, or if it can generate random words
     * @return the generated text
     */
    QString generatePractice(QString letters,bool onlyRealWords = true);
    
    
    /**
     * Generate some random words with the available letters given in the list
     * 
     * @param letterList a list of 'authorized' letters
     * @param length length of the result string
     * @return a string with random words proposed in the given string list in parameter
     */
    QString generateFromLetters(QString letterList, int length = 50);
    
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
     * Select one random char in the availables elements of the String
     * Helper to create exercices
     * 
     * @param string
     * @return a random-selected char (casted to a QString) in the string
     */
    QString selectRandomChar(QString listString);
    
    /**
     * Select a random element in the list of String
     * 
     * 
     * @param strings the list of strings
     * @return a element selected randomyl in the list
     */
    QString selectRandomString(QStringList strings);
    
    /**
     * Helper to find the closest space in a list of string to
     * the be able to break the list at a space, instead
     * of breaking in the midlle of a string
     * 
     * @param search the list of string containing spaces
     * @param indexStart the index where to start the reserach
     * @return the index of the closest space in the list from indexStart
     */
    int findClosestSpace(const QString &search, int indexStart);
    
    /**
     * Will split the text into differents parts to be able to display the 
     * given original string into differents line with aproximately the same length
     * The split is made at the closes space found, to avoid beaking a word and split
     * at a space instead
     * 
     * @param text the text to split
     * @param the number of string to put in the list
     * @return the text splitted
     */
    QStringList splitText(QString toSplit,int numberOfSplit);

}



#endif /* FACTORY_H */


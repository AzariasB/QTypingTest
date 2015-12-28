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

#ifndef TESTCREATOR_H
#define TESTCREATOR_H



#include <QStringList>
#include <QDebug>


class TestCreator {
public:

    TestCreator() {
    };

    /**
     * 
     * @param mainLetter the letter that the user is going to learn
     * @param allLetters all the available letters for the exercice
     * @return a random-generated list of words
     */
    static QStringList generateLearning(QStringList mainLetter, QStringList allLetters);

    /**
     * A generator to create simple exercices
     * 
     * @return random words (existing and non-existing)
     */
    static QStringList generatePractice();
    
    virtual ~TestCreator() {
    };

private:
    static QString selectRandomLetter(QStringList lettersList);
    
    static QString generateFromLetters(QStringList letterList,int length = 50);
    
    /**
     Find valid numbers for space chances
     */
    static inline int randomNextSpace(){
        return rand() %9 + 2;
    }
};

#endif /* TESTCREATOR_H */


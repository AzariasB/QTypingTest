/*
 * QTypingTest by Pierre and Azarias
 * Licence : GPL2
 */
/* 
 * File:   TestCreator.cpp
 * Author: boutina
 * 
 * Created on 14 décembre 2015, 20:41
 */

#include "exercicecreator.h"

QStringList TestCreator::generateLearning(QStringList mainLetter, QStringList allLetters) {

    QString res;

    if (!mainLetter.isEmpty())
        res += generateFromLetters(mainLetter);

    if (!allLetters.isEmpty())
        res += generateFromLetters(allLetters);
    else
        qDebug() << "Warning : empty all letters";

    return res.split("");
}

QStringList TestCreator::generatePractice() {
    QString res;
    while (res.size() < 20) {
        res += "a";
        //TODO : create a REAL generator
        if (res.size() % 5 == 0) {
            res += " ";
        }
    }

    return res.split("");
}

QString TestCreator::generateFromLetters(QStringList letterList, int length) {
    int nextSpace = randomNextSpace();
    QString res;
    for (int i = 0; i < length; i++, nextSpace--) {
        res += selectRandomLetter(letterList);
        if (nextSpace == 0) {
            res += " ";
            nextSpace = randomNextSpace();
        }
    }
    return res;
}

QString TestCreator::selectRandomLetter(QStringList lettersList) {
    return lettersList[rand() % lettersList.size()];
}


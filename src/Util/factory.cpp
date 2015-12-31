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

#include <qt5/QtCore/qstringlist.h>

#include "factory.h"

/**
 * A little helper to generate random position of space in text
 * 
 * @return A random number between 2 and 9 (the next position of the space)
 */
int randomNextSpace() {
    return rand() % 9 + 2;
}

QStringList readFile(QString fileName) {
    QFile model(fileName);
    QStringList words = QStringList();
    if (model.exists() && model.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&model);
        while (!in.atEnd()) {
            words << in.readLine();
        }
        return words;
    } else {//File not found
        if (!model.exists())
            qDebug() << "File does not exists : " + fileName + " \n Please, be sure to run the programm from its root folder";
        else
            qDebug() << "Could not open file";
        return QStringList();
    }
}

bool isValidWord(QString word, QString availableLetters) {
    for (auto it = availableLetters.begin();
            !word.isEmpty() && it != availableLetters.end();
            ++it)
        word.replace(*it, "");
    return word.isEmpty();
}

QStringList factory::generateLearning(QStringList mainLetter, QStringList allLetters) {

    QString res;

    if (!mainLetter.isEmpty())
        res += generateFromLetters(mainLetter);

    if (!allLetters.isEmpty()) {
        res += generateFromLetters(allLetters);
        res += generateWords(allLetters.join(""), "en");
    } else
        qDebug() << "Warning : empty all letters";

    return res.split("");
}

QString factory::generateFromLetters(QStringList letterList, int length) {
    int nextSpace = randomNextSpace();
    QString res;
    for (int i = 0; i < length; i++, nextSpace--) {
        res += selectRandomElement(letterList);
        if (nextSpace == 0) {
            res += " ";
            nextSpace = randomNextSpace();
        }
    }
    return res;
}

QStringList factory::findExistingWords(QString authorizedLetters, QString fileName) {
    QStringList words = readFile(fileName);
    QStringList res;

    foreach(QString word, words) {
        if (isValidWord(word, authorizedLetters)) {
            res << word;
        }
    }
    return res;
}

QString factory::generateWords(QString authorizedLetters, QString language, int numberOfWords) {
    QString res = "";
    QStringList words = factory::findExistingWords(authorizedLetters, file::getWordsPath(language));
    if (!words.isEmpty()) {
        for (int i = 0; i < numberOfWords; i++) {
            res += selectRandomElement(words);
            if (i != numberOfWords - 1) res += " ";
        }
    }
    return res;
}

QString factory::selectRandomElement(QStringList lettersList) {
    return lettersList[rand() % lettersList.size()];
}


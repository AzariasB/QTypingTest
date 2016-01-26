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

//#include <qt5/QtCore/qstringlist.h>
//#include <qt5/QtCore/qlogging.h>

#include "factory.h"

//The number of word that a single page can contain
const int numberOfWords = 40;

/**
 * A little helper to generate random position of space in text
 * 
 * @return A random number between 2 and 9 (the next position of the space)
 */
int randomNextSpace() {
    return rand() % 9 + 2;
}

/**
 * 
 * @param 
 * @param 
 * @return 
 */
int randInt(int min,int max){
    return (rand() % (max + 1 - min)) + min;
}

/**
 * Little helper to check if at least each chars of the contains QString
 * is contained in one of the words.
 * For example, with the words ("fly","my") and the string "ty", the function
 * will return false since "t" is contained in none of the words "fly" and "my"
 * If we had ("fly","my","try") the function would return true since t is in "try"
 * and "y" is in at least of of the three words
 * 
 * @param words the found words
 * @param contains the chars that must be in the words
 * @return if ALL the chars in the string contains are in the words
 */
bool wordsContains(QStringList words, QString contains) {
    QStringList letters = contains.split("", QString::SkipEmptyParts);
    for (auto it = words.begin(); it != words.end(); ++it) {
        QStringList copy = letters;
        for (auto letter = letters.begin(); letter != letters.end(); ++letter) {
            if ((*it).contains(*letter)) {
                copy.removeAll(*letter);
            }
        }
        if (copy.isEmpty()) {
            return true;
        }
        letters = copy;
    }

    return false;
}

QStringList readFile(QString fileName) {
    QFile model(fileName);
    if (model.exists() && model.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QString res(model.readAll());
        return res.split("\n");
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


QString factory::generateText(int numbersOfWords, QString lang){
    //TODO : change to have a list of available langs
    if(lang != "en"){
        return ""; //Nothing for now
    }else{
        QString fPath = file::getTextPath(lang);
        QStringList content = readFile(fPath);
        QStringList text = selectRandomElement(content).split(" ",QString::SkipEmptyParts);
        int start = randInt(0,text.size() - numbersOfWords);
        return QStringList(text.mid(start,numbersOfWords)).join(" ");
    }
}

QString factory::generateLearning(QStringList mainLetter, QStringList allLetters) {

    QString res;

    if (!mainLetter.isEmpty())
        res += generateFromLetters(mainLetter);

    //TODO : change here the language of the words to depend on the user configuration (Azarias)
    if (!allLetters.isEmpty()) {
        res += generateFromLetters(allLetters);
        QString wordsWMain = generateWords(allLetters.join(""), "en", mainLetter.join(""));

        //If no words can be generated
        if (wordsWMain.isEmpty()) {
            //Try without main letter
            QString randWords = generateWords(allLetters.join(""), "en");
            //
            if (randWords.isEmpty()) {//Generate random letters
                res += generateFromLetters(allLetters);
            } else {//Random generate words AND main letters and shuffle
                QString randLetter = generateFromLetters(mainLetter);
                QStringList available = randLetter.split(" ") + randWords.split(" ");
                std::random_shuffle(available.begin(), available.end());
                res += available.join(" ");
            }
        } else {
            res += wordsWMain;
        }
    } else
        qWarning() << "Warning : no letters available to generate the exercice";

    return res;
}

QString factory::generatePractice(QStringList letters, bool onlyRealWords){
    QString res;
    if(!onlyRealWords)
        res += generateFromLetters(letters);
    
    if(!letters.isEmpty()){
        res += generateWords(letters.join(""),"en");
        QStringList words = res.split(" ",QString::SkipEmptyParts);
        std::random_shuffle(words.begin(),words.end());
        res = words.join(" ");
    }else{
        qWarning() << "Warning : no letters available to generate the practice";
    }
    
    return res;
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

QStringList factory::findExistingWords(QString authorizedLetters, QString fileName, QString mustContain) {
    QStringList words = readFile(fileName);
    QStringList res;

    foreach(QString word, words) {
        if (isValidWord(word, authorizedLetters))
            res << word;
    }


    if (!mustContain.isEmpty() &&
            !res.isEmpty() &&
            !wordsContains(res, mustContain)) {
        return QStringList(); //Empty list
    }

    return res;
}

QString factory::generateWords(QString authorizedLetters, QString language, QString mainLetters) {
    QString res = "";
    QStringList words = factory::findExistingWords(authorizedLetters, file::getWordsPath(language), mainLetters);
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

int factory::findClosestSpace(const QString& search, int indexStart) {
    if (indexStart >= search.length() || search[indexStart] == ' ') return indexStart;
    int toDecr = indexStart;
    int toIncr = indexStart;
    for (; toDecr >= 0 && toIncr < search.size(); --toDecr, ++toIncr) {
        if (search[toDecr] == ' ') return toDecr;
        if (search[toIncr] == ' ') return toIncr;
    }

    return toIncr; //End of the string
}

QStringList factory::splitText(QString toSplit, int numberOfSplit) {
    int charPerPages = toSplit.size() / numberOfSplit;

    QStringList models;

    for (int i = 0; i < numberOfSplit; i++) {
        //Find the closest space to do not cut a word
        int indexlast = factory::findClosestSpace(toSplit, charPerPages);
        QString line =   toSplit.mid(0, indexlast);
        //Reduce the size of the original array
        toSplit = toSplit.mid(indexlast + 1);
        models << line;
    }
    return models;
}

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
#include "factory.h"
#include <QDebug>
#include <algorithm>
#include <QFile>


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
        QStringList copy(letters);
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



bool isValidWord(QString word, QString availableLetters) {
    if(word.isEmpty())
        return false;
    for (auto it = availableLetters.begin();
            !word.isEmpty() && it != availableLetters.end();
            ++it)
        word.replace(*it, "");
    return word.isEmpty();
}

int uId = 0;

int factory::nexUId()
{
    return uId++;
}

int factory::currentUId()
{
    return uId;
}

void factory::setUId(int nwId)
{
    uId = nwId;
}

QDomElement factory::getRandomText()
{
    QDomDocument doc = readXMLFile(":/texts.xml");
    QDomElement root = doc.documentElement();
    if(root.tagName() != "texts"){
        qWarning() << "XML not correctly formatted : should be 'texts' at the root, found :" << root.tagName();
        return QDomElement();
    }else{
        QDomNodeList choices = root.childNodes();
        int randomNode = randInt(0,choices.length()-1);
        return choices.item(randomNode).toElement();
    }
}

QString factory::generateLearning(const QString &mainLetter, const QString &allLetters) {

    QString res;

    if (!mainLetter.isEmpty())
        res += generateFromLetters(mainLetter);

    if (!allLetters.isEmpty()) {
        res += generateFromLetters(allLetters);
        QString wordsWMain = generateWords(allLetters,mainLetter);

        //If no words can be generated
        if (wordsWMain.isEmpty()) {
            //Try without main letter
            QString randWords = generateWords(allLetters);
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
    } else{
        qWarning() << "Warning : no letters available to generate the exercise";
    }
    return res;
}

QString factory::generatePractice(const QString &letters, bool realWordsOnly, int numberOfWords){
    QString res;
    if(!realWordsOnly)
        res += generateFromLetters(letters,numberOfWords/2);
    
    if(!letters.isEmpty()){
        res += generateWords(letters,"",numberOfWords/2);
        QStringList words = res.split(" ",QString::SkipEmptyParts);
        std::random_shuffle(words.begin(),words.end());
        res = words.join(" ");
    }else{
        qWarning() << "Warning : no letters available to generate the practice";
        //Generate with all the letters
        return generatePractice(QString("abcdefghijklmnopqrstuvwxyz"), realWordsOnly, numberOfWords);
    }
    
    return res;
}

QString factory::generateFromLetters(const QString &letters, int length) {
    int nextSpace = randomNextSpace();
    QString res;
    for (int i = 0; i < length; i++, nextSpace--) {
        res += selectRandomChar(letters);
        if (nextSpace == 0) {
            res += " ";
            nextSpace = randomNextSpace();
        }
    }
    return res;
}

QStringList factory::findExistingWords(const QString &authorizedLetters, const QString &mustContain) {
    QStringList words = readFile(":/words.txt").split("\n");
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

QString factory::generateWords(const QString &authorizedLetters, const QString &mainLetters, int numberOfWords) {
    QString res = "";
    QStringList words = factory::findExistingWords(authorizedLetters, mainLetters);
    if (!words.isEmpty()) {
        for (int i = 0; i < numberOfWords; i++) {
            res += selectRandomString(words);
            if (i != numberOfWords - 1) res += " ";
        }
    }
    return res;
}

QString factory::selectRandomChar(const QString &lettersList) {
    return QString(lettersList[rand() % lettersList.size()]);
}

QString factory::selectRandomString(const QStringList &strings){
    return strings[rand() % strings.size()];
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

QStringList factory::splitText(QString toSplit, int numberOfSplit)
{
    numberOfSplit = numberOfSplit <= 0 ? 1 : numberOfSplit;
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


QString factory::readFile(const QString &fileName)
{
    QFile model(fileName);
    if (model.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QString res(model.readAll());
        model.close();
        return res;
    } else {//File not found
        qWarning () << "Could not open file";
        return QString("");
    }
}


QDomDocument factory::readXMLFile(const QString &fileName)
{
    QFile f(fileName);
    QDomDocument doc("texts");
    if(!f.open(QIODevice::ReadOnly)){
        qWarning() << "Could not open xml file";
        return QDomDocument();
    }
    if(!doc.setContent(&f)){
        qWarning() << "Could not set content of domDocument";
        return QDomDocument();
    }
    f.close();
    return doc;
}


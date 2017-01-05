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



bool isValidWord(QString word, QString availableLetters) {
    for (auto it = availableLetters.begin();
            !word.isEmpty() && it != availableLetters.end();
            ++it)
        word.replace(*it, "");
    return word.isEmpty();
}


TText factory::generateText()
{
    QDomDocument doc = readXMLFile(":/texts/texts.xml");
    TText t;
    QDomElement root = doc.documentElement();
    if(root.tagName() != "texts"){
        qDebug() << "XML not correctly formatted : should be 'texts' at the root, found :" << root.tagName();
        return t;
    }else{
        QDomNodeList choices = root.childNodes();
        int randomNode = randInt(0,choices.length()-1);
        QDomNode node = choices.item(randomNode);
        if(node.isElement()){
            QDomElement chosen = node.toElement();
            if(chosen.hasAttribute("title")){
                QString title = chosen.attribute("title");
                qDebug() << "Found the title : " <<  title;
                t.setTitle(title);
            }
            if(chosen.hasAttribute("author")){
                QString author = chosen.attribute("author");
                qDebug() << "Found the author :  " << author;
                t.setAuthor(author);
            }
            t.setText(chosen.text().simplified());
            return t;
        }else{
            return t;
        }
    }
}

QString factory::selectTextChunk(QString wholeText, int minNumberOfWords,int maxNumberOfWords)
{
    int absoluteNumberOfWords = minNumberOfWords * 5;
    int maxAbs = maxNumberOfWords * 5;
    QString maxLength = wholeText.mid(0,wholeText.size() - absoluteNumberOfWords);
    int numberOfDots = maxLength.count('.');
    int randStartPos = randInt(0,numberOfDots);
    //Starting at the very begining of a sentence
    for(int i = 0 ; i < randStartPos;i++){
        wholeText = wholeText.mid(0,wholeText.indexOf('.'));
    }
    //Chunk that starts with at the end of a sentence.
    QString firstChunk = wholeText.mid(0,absoluteNumberOfWords);
    wholeText = wholeText.mid(absoluteNumberOfWords);
    //Chunk that ends with a '.' at the end
    QString secondChunk = wholeText.mid(0,wholeText.indexOf('.'));

    //If too much words, just end the current word
    if((firstChunk + secondChunk).size() > maxAbs )
        return firstChunk + secondChunk.mid(0,secondChunk.indexOf(' ')) ;
    return firstChunk + secondChunk;

}

QString factory::generateLearning(QString mainLetter, QString allLetters) {

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
    } else
        qWarning() << "Warning : no letters available to generate the exercice";

    return res;
}

QString factory::generatePractice(QString letters, bool realWordsOnly, int numberOfWords){
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

QString factory::generateFromLetters(QString letters, int length) {
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

QStringList factory::findExistingWords(QString authorizedLetters, QString fileName, QString mustContain) {
    QStringList words = readFile(fileName).split("\n");
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

QString factory::generateWords(QString authorizedLetters, QString mainLetters, int numberOfWords) {
    QString res = "";
    QStringList words = factory::findExistingWords(authorizedLetters, ":/words/words.txt", mainLetters);
    if (!words.isEmpty()) {
        for (int i = 0; i < numberOfWords; i++) {
            res += selectRandomString(words);
            if (i != numberOfWords - 1) res += " ";
        }
    }
    return res;
}

QString factory::selectRandomChar(QString lettersList) {
    return QString(lettersList[rand() % lettersList.size()]);
}

QString factory::selectRandomString(QStringList strings){
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


QString factory::readFile(QString fileName)
{
    QFile model(fileName);
    if (model.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QString res(model.readAll());
        return res;
    } else {//File not found
        qDebug() << "Could not open file";
        return QString("");
    }
}


QDomDocument factory::readXMLFile(QString fileName)
{
    QFile f(fileName);
    QDomDocument doc("texts");
    if(!f.open(QIODevice::ReadOnly)){
        qDebug() << "Could not open xml file";
        return QDomDocument();
    }
    if(!doc.setContent(&f)){
        qDebug() << "Could not set content of domDocument";
        return QDomDocument();
    }
    f.close();
    return doc;
}


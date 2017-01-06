/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */
/* 
 * File:   tlayouts.h
 * Author: boutina
 *
 * Created on 17 décembre 2015, 11:35
 */

/*
 * Finger explanation :
 *
 *   0 1 2 3 4    5 6 7 8 9
       _.-._        _.-._
     _| | | |      | | | |_
    | | | | |      | | | | |
    | | | | |      | | | | |
    | _.-'  | _  _ |  '-._ |
    ;_.-'.-'/`/  \`\`-.'-._;
    |   '    /    \    '   |
     \  '.  /      \  .`  /
      |    |        |    |

 The fingers are numbered from 0 to 9 when you look
 at the back of each hand
 *
 */

#ifndef TLAYOUTS_H
#define TLAYOUTS_H

#include <QStringList>
#include <QDebug>
#include <QList>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

#include "Util/factory.h"

/**
 * This class is here to have a way to create the exercices
 * on a certain order based on the keyboard layout
 */
class TLayout{
public:

    static TLayout&getInstance() {
        static TLayout instance;
        return instance;
    }

    QList<QStringList> getLayouLines() const {
        return *layoutLines_;
    }

    QStringList getLetterList();

    QString getLettersAt(int index) {
        return getLetterList()[index];
    }

    QString getAllLettersTo(int length) {
        return QStringList(getLetterList().mid(0, length)).join("");
    }

    QString getAllAvailableLetters() {
        return allAvailableLetters_;
    }

    QStringList getAvailablLayoutLangs(){
        return availableLangs_;
    }


    virtual ~TLayout() {
    }

private:

    QString allAvailableLetters_;

    QStringList availableLangs_;

    TLayout() {
        this->initLetters();
    }

    void setAvailableLangs(const QStringList &ori){
        TLayout:availableLangs_ =  ori;
    }

    /**
     * Init the list of letters, from the given
     * layout name and the country code
     * If the country code is empty, the first config found will
     * be chosen
     * 
     * @param layout layout of the keyboard
     * @param country the country code of the layout
     * (FR for France, SW for Sweden ...)
     */
    void initLetters();


    /**
     *
     * 
     * @param layout the layout data of a single keyboard type
     * @return al list contating a list of the key for each line
     */
    QList<QStringList> *decomposeLayout(const QJsonValue &rows);

    QStringList lettersList_;
    QList<QStringList> *layoutLines_;

    /**
      * @brief Ordre to learn the keyboard keys
      * @abstract The list contains 21 entry, for the 21 couple of key to learn,
      *             each entry contains three values :
      *                 - The Line index ( 0 = number line, 1 = upperline, 2 = baseline, 3 = lower line)
      *                 - The index on the line couple's left char
      *                 - The index of the lines couple's right char
      *
      */
    int listOrder_[21][3] = {
        {2, 3, 6},
        {2, 2, 7},
        {2, 1, 8},
        {2, 0, 9},
        {2, 4, 5}, //baseLine
        {1, 4, 5},
        {1, 3, 6},
        {1, 2, 7},
        {1, 1, 8},
        {1, 0, 9}, //upperline
        {3, 5, 6},
        {3, 4, 7},
        {3, 3, 8},
        {3, 2, 9},
        {3, 1, 10}, //lower line
        {0, 5, 6},
        {0, 4, 7},
        {0, 3, 8},
        {0, 2, 9},
        {0, 1, 10},
        {0, 0, 11}//numbers line
    };
};

#endif /* TLAYOUTS_H */

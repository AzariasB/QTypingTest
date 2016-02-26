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

#ifndef TLAYOUTS_H
#define TLAYOUTS_H

#include <QStringList>
#include <QDebug>
#include <QList>

#include "Util/filehelper.h"

/**
 * This class is here to have a way to create the exercices
 * on a certain order based on the keyboard layout
 */
class TLayouts {
public:

    static TLayouts &getInstance(QString layout , QString country = "") {
        static TLayouts instance(layout,country);
        if (instance.getCurrentLang() != layout || instance.getCurrentCountry() != country) {
            instance = TLayouts(layout,country);
        }
        return instance;
    }

    QString getCurrentLang() const {
        return currentLayout_;
    }

    QString getCurrentCountry() const{
        return currentCountry_;
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


    virtual ~TLayouts() {
    }

private:

    QString allAvailableLetters_;

    QStringList availableLangs_;

    TLayouts(QString layout,QString lang = "") {
        this->initLetters(layout,lang);
    }

    void setAvailableLangs(const QStringList &ori){
        TLayouts::availableLangs_ =  ori;
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
    void initLetters(QString layout, QString country = "");


    /**
     * Takes a single layout in parameter and split in
     * into a QList for each line of the keyboard.
     * This list contain a QStringlist containing the key
     * combination for each key of the line (e.g. "aA" for the key A)
     * 
     * @param layout the layout data of a single keyboard type
     * @return al list contating a list of the key for each line
     */
    QList<QStringList> *decomposeLayout(QString layout);


    /**
     * From the content of the file containg all the layouts,
     * it will find the layout configuration corresponding to
     * the given language code (e.g. "en" for english, "fr" for french ...)
     * 
     * @param config the content of the file containing the layouts
     * @param lang the langage of the layout
     * @return the layout of the given langage, empty String if not found
     */
    QString findCorrespondingLayout(QString config, QString lang, QString country = "");

    /**
     * @brief findAvailableLangs will find the available language in the layout file
     * @param fileContent the content of layouts.txt (or the file containg the layouts)
     */
    void findAvailableLangs(const QString &fileContent);

    QString currentLayout_;
    QString currentCountry_;

    QStringList lettersList_;
    QList<QStringList> *layoutLines_;

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


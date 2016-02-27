/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */
/* 
 * File:   TExercice.h
 * Author: boutina
 *
 * Created on 18 décembre 2015, 11:42
 */

#ifndef TEXERCICE_H
#define TEXERCICE_H

#include <QStringList>
#include <QDebug>
#include <QDataStream>

#include "tresult.h"
#include "Util/factory.h"
#include "Data/tlayouts.h"

/**
 * A model class to define the type of exercice the user is about to do
 * There are differents types of exercices and depending of these, differents parameters
 */
class TExercice {
public:

    enum EXERCICE_TYPE {
        LEARNING, PRACTICING, PRACTICING_RACE, PRACTICING_TEXT
    };

    TExercice();
    TExercice(EXERCICE_TYPE exType, QString mainLetter, QString availableLetters);
    TExercice(EXERCICE_TYPE exType, bool allLetters);
    TExercice(const TExercice& orig);

    QString buildExercice() const;

    virtual ~TExercice() {}

    QString learningLetters() const;

    bool getAllLetters() const {
        return allLetters_;
    }

    const QString &getLearningLetters() const {
        return learningLetters_;
    }

    const QString &getAvailableLetters() const {
        return availableLetters_;
    }

    const EXERCICE_TYPE& getExerciceType() const {
        return exerciceType_;
    }

    void setAllLetters(bool allLetters) {
        allLetters_ = allLetters;
    }

private:
    bool allLetters_ = false;
    QString learningLetters_;
    QString availableLetters_;
    EXERCICE_TYPE exerciceType_;
};

Q_DECLARE_METATYPE(TExercice)

QDataStream &operator>>(QDataStream &in, TExercice &ex);

QDataStream &operator<<(QDataStream &out, const TExercice &ex);

inline bool operator==(const TExercice& exo1, const TExercice& exo2) {
    return exo1.getAvailableLetters() == exo2.getAvailableLetters() &&
            exo1.getExerciceType() == exo2.getExerciceType() &&
            exo1.getLearningLetters() == exo2.getLearningLetters();
}

#endif /* TEXERCICE_H */


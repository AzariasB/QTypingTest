/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */


/* 
 * File:   TProgression.h
 * Author: boutina
 *
 * Created on 19 décembre 2015, 12:21
 */

#ifndef TPROGRESSION_H
#define TPROGRESSION_H

#include <QDebug>
#include <QDataStream>
#include "tjsonserializable.h"

/**
 * A class to define the progression of a user
 * to know what's the last letters he learned
 * the difficulty of the exercices
 * 
 */
class TProgression : public TJsonSerializable {

public:
    TProgression();
    TProgression(const TProgression& orig);
    virtual ~TProgression();

    int getLastExericeIndex() const {
        return lastExerciceIndex_;
    }

    void setLastExerciceIndex(int exIndex) {
        lastExerciceIndex_ = exIndex;
    }

    void avdvanceExIndex() {
        lastExerciceIndex_++;
    }

	void read(const QJsonObject &json) override;

	void write(QJsonObject &json) const override;


private:
    int lastExerciceIndex_;
};


bool operator==(const TProgression &prog1, const TProgression &prog2);

#endif /* TPROGRESSION_H */


/*
 * QTypingTest by Pierre and Azarias - //website//
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

/**
 * A class to define the progression of a user
 * to know what's the last letters he learned
 * the difficulty of the exercices
 * 
 *  \todo : add progression for the practice exerccices
 */
class TProgression : public QObject {

    Q_OBJECT

public:
    TProgression(QObject *parent = 0);
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

private:
    int lastExerciceIndex_;
    friend QDataStream &operator<<(QDataStream &out, const TProgression &prog){
        out << prog.lastExerciceIndex_;
        return out;
    }

    friend QDataStream &operator>>(QDataStream &in, TProgression &prog){
        in >> prog.lastExerciceIndex_;
        return in;
    }
};

Q_DECLARE_METATYPE(TProgression)

QDataStream &operator<<(QDataStream &out, const TProgression &prog);

QDataStream &operator>>(QDataStream &in, TProgression &prog);

bool operator==(const TProgression &prog1, const TProgression &prog2);

#endif /* TPROGRESSION_H */



/* 
 * File:   TProgression.h
 * Author: boutina
 *
 * Created on 19 décembre 2015, 12:21
 */

#ifndef TPROGRESSION_H
#define TPROGRESSION_H

/**
 * A class to define the progression of a user
 * to know what's the last letters he learned
 * the difficulty of the exercices
 * 
 * TODO : add progression for the practice exerccices
 */
class TProgression {
public:
    TProgression();
    TProgression(const TProgression& orig);
    virtual ~TProgression();
private:
    int lastExerciceIndex_;
};

QDataStream &operator<<(QDataStream &out,const TProgression &prog);

QDataStream &operator>>(QDataStream &in,TProgression &prog);

#endif /* TPROGRESSION_H */


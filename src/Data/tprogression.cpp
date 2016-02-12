/* 
 * File:   TProgression.cpp
 * Author: boutina
 * 
 * Created on 19 décembre 2015, 12:21
 */

#include "tprogression.h"

TProgression::TProgression(): lastExerciceIndex_(0) {
    
}

TProgression::TProgression(const TProgression& orig):
lastExerciceIndex_(orig.lastExerciceIndex_){
}

TProgression::~TProgression() {
}

QDataStream &operator<<(QDataStream &out,const TProgression &prog){
    qint16 lastExIndex = prog.getLastExericeIndex();
    out << lastExIndex;
    return out;
}

QDataStream &operator>>(QDataStream &in,TProgression &prog){
    qint16 lastExIndex;
    in >> lastExIndex;
    prog.setLastExerciceIndex(lastExIndex);
    return in;
}

bool operator==(const TProgression &prog1,const TProgression &prog2){
    return prog1.getLastExericeIndex() == prog2.getLastExericeIndex();
}
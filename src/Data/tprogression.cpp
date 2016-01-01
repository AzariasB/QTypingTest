/* 
 * File:   TProgression.cpp
 * Author: boutina
 * 
 * Created on 19 décembre 2015, 12:21
 */

#include "tprogression.h"

// CHANGE HERE TO SET THE PROGRESSION TO SOMEHTING ELSE
TProgression::TProgression(): lastExerciceIndex_(20) {
    
}

TProgression::TProgression(const TProgression& orig) {
    this->lastExerciceIndex_ = orig.getLastExericeIndex();
}

TProgression::~TProgression() {
}

QDataStream &operator<<(QDataStream &out,const TProgression &prog){
    return out;
}

QDataStream &operator>>(QDataStream &in,TProgression &prog){
    return in;
}
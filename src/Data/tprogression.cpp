/* 
 * File:   TProgression.cpp
 * Author: boutina
 * 
 * Created on 19 décembre 2015, 12:21
 */

#include "tprogression.h"

TProgression::TProgression(QObject *parent):
    QObject(parent),
    lastExerciceIndex_(0) {
    
}


TProgression::TProgression(const TProgression& orig):
    QObject(orig.parent()),
lastExerciceIndex_(orig.lastExerciceIndex_){
}

TProgression::~TProgression() {
}


bool operator==(const TProgression &prog1,const TProgression &prog2){
    return prog1.getLastExericeIndex() == prog2.getLastExericeIndex();
}

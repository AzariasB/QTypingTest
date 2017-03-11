/* 
 * File:   TProgression.cpp
 * Author: boutina
 * 
 * Created on 19 décembre 2015, 12:21
 */

#include "tprogression.h"

TProgression::TProgression() :
    lastExerciceIndex_(0) {
    
}


TProgression::TProgression(const TProgression& orig):
lastExerciceIndex_(orig.lastExerciceIndex_){
}

TProgression::~TProgression() {
}


void TProgression::read(const QJsonObject &json)
{
	lastExerciceIndex_ = json["lastExerciceIndex"].toInt();
}

void TProgression::write(QJsonObject &json) const
{
	json["lastExerciceIndex"] = lastExerciceIndex_;
}


bool operator==(const TProgression &prog1,const TProgression &prog2){
    return prog1.getLastExericeIndex() == prog2.getLastExericeIndex();
}

/* 
 * File:   TProgression.cpp
 * Author: boutina
 * 
 * Created on 19 décembre 2015, 12:21
 */

#include "tprogression.h"
#include <QJsonObject>

TProgression::TProgression() :
    lastExerciseIndex_(0) {
    
}


TProgression::TProgression(const TProgression& orig):
lastExerciseIndex_(orig.lastExerciseIndex_){
}

TProgression::~TProgression() {
}


void TProgression::read(const QJsonObject &json)
{
	lastExerciseIndex_ = json["lastExerciseIndex"].toInt();
}

void TProgression::write(QJsonObject &json) const
{
	json["lastExerciseIndex"] = lastExerciseIndex_;
}


bool operator==(const TProgression &prog1,const TProgression &prog2){
    return prog1.getLastExericeIndex() == prog2.getLastExericeIndex();
}

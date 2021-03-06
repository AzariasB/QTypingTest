/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */


/* 
 * File:   TStats.cpp
 * Author: boutina
 * 
 * Created on 1 janvier 2016, 14:51
 */

#include "tstats.h"
#include <QJsonObject>

TStats::TStats() :
QHash(){
}


void TStats::read(const QJsonObject &json)
{
	for(auto it = json.begin(); it != json.end(); ++it){
		//Test if int
		this->insert(it.key().at(0), it.value().toInt());
	}
}

void TStats::write(QJsonObject &json) const
{
    for(auto it = this->begin(); it != this->end(); ++it){
        json[it.key()] = it.value();
    }
}

TStats::~TStats() {
}

void TStats::add(const TStats& otherStat) {
    for(auto it = otherStat.begin(); it != otherStat.end(); ++it){
        if(contains(it.key())){
            (*this)[it.key()] += it.value();
        }else{
            insert(it.key(),it.value());
        }
    }
}


TStats* TStats::operator+(const TStats& otherStat) {
    TStats *res = new TStats(*this);
    res->add(otherStat);
    return res;
}

TStats& TStats::operator+=(const TStats& otherStat) {
    this->add(otherStat);
    return *this;
}

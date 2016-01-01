/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */


/* 
 * File:   TStats.cpp
 * Author: boutina
 * 
 * Created on 1 janvier 2016, 14:51
 */

#include "tstats.h"

TStats::TStats() :
QHash(){
}

TStats::TStats(const TStats& orig):
QHash(){
    for(auto it = orig.begin();it != orig.end();++it){
        insert(it.key(),it.value());
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

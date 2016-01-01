/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */

/* 
 * File:   TStats.h
 * Author: boutina
 *
 * Created on 1 janvier 2016, 14:51
 */

#ifndef TSTATS_H
#define TSTATS_H

#include <QHash>

class TStats : public QHash<QChar,int> {
public:
    TStats();
    TStats(const TStats& orig);
    virtual ~TStats();
    
    void add(const TStats &otherStat);
    
    TStats* operator+(const TStats &otherStat);

    TStats& operator+=(const TStats &otherStat);
private:

};



#endif /* TSTATS_H */


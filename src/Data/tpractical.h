/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */

/* 
 * File:   TPractical.h
 * Author: boutina
 *
 * Created on 24 décembre 2015, 13:25
 */

#ifndef TPRACTICAL_H
#define TPRACTICAL_H

#include <QString>

class TPractical {
public:
    TPractical();
    TPractical(const TPractical& orig);

    enum DIFFICULTY {
        BASIC,
        EASY,
        NORMAL,
        MEDIUM,
        HARD,
        CHUCK_NORRIS
    };

    virtual ~TPractical();
private:
    //Name of the file to get the text
    QString fileName_;
};

#endif /* TPRACTICAL_H */


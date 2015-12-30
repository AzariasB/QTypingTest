/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */

/* 
 * File:   TKeys.h
 * Author: boutina
 *
 * Created on 30 décembre 2015, 11:47
 */

#ifndef TKEYS_H
#define TKEYS_H

#include <qnamespace.h>
#include <QList>

using namespace Qt;

class TKeys {
public:
    TKeys();
    
    static QList<int> validLetters();
    static bool isValidLetter(int letterCode);

    virtual ~TKeys(){};
private:
    static QList<int> letters_;
};

#endif /* TKEYS_H */


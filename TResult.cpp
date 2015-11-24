/* 
 * File:   TResult.cpp
 * Author: boutina
 * 
 * Created on 24 novembre 2015, 11:27
 */

#include "TResult.h"

TResult::TResult() {}

int TResult::getTotalKeysStokres() const {
    return getCorrectKeysStrokes() + getWrongKeysStrokes();
}

int TResult::getWordsPerMinute() const {
    return getCorrectKeysStrokes() / 5;
}

int TResult::getTotalWords() const {
    return getCorrectWords() + getWrongWords();
}

TResult* TResult::operator+(const TResult& otherRes) {
    TResult *res = new TResult();
    res->setCorrectKeysStrokes(this->getCorrectWords() + otherRes.getCorrectKeysStrokes());
    res->setCorrectWords(this->getCorrectWords() + otherRes.getCorrectWords());
    res->setWrongKeysStrokes(this->getWrongKeysStrokes() + otherRes.getWrongKeysStrokes());
    res->setWrongWords(this->getWrongWords() + otherRes.getWrongWords());
    return res;
}



TResult::~TResult() {
}


/* 
 * File:   TResult.cpp
 * Author: boutina
 * 
 * Created on 24 novembre 2015, 11:27
 */

#include "TResult.h"

TResult::TResult() {
}

TResult::TResult(const TResult &base) {
    *this += base;
}

int TResult::getTotalKeysStokres() const {
    return getCorrectKeysStrokes() + getWrongKeysStrokes();
}

int TResult::updateWPM(float deltaTime ) {
    if (deltaTime > 0) {
        wordsPerMinute = (getCorrectKeysStrokes() / 5) / deltaTime;
    }
    return wordsPerMinute;
}

int TResult::getTotalWords() const {
    return getCorrectWords() + getWrongWords();
}

//Operator overloading

TResult& TResult::operator+=(const TResult& otherRes) {
    this->correctKeystrokes += otherRes.getCorrectKeysStrokes();
    this->correctWords += otherRes.getCorrectWords();
    this->wrongKeystrokes += otherRes.getWrongKeysStrokes();
    this->wrongWords += otherRes.getWrongWords();
    return *this;
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


/* 
 * File:   TResult.cpp
 * Author: boutina
 * 
 * Created on 24 novembre 2015, 11:27
 */

#include "tresult.h"

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
        wordsPerMinute_ = (getCorrectKeysStrokes() / 5) / deltaTime;
    }
    return wordsPerMinute_;
}

int TResult::getTotalWords() const {
    return getCorrectWords() + getWrongWords();
}

//Operator overloading

TResult& TResult::operator+=(const TResult& otherRes) {
    this->correctKeystrokes_ += otherRes.getCorrectKeysStrokes();
    this->correctWords_ += otherRes.getCorrectWords();
    this->wrongKeystrokes_ += otherRes.getWrongKeysStrokes();
    this->wrongWords_ += otherRes.getWrongWords();
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


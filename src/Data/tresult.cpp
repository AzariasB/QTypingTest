/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */

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
    qRegisterMetaType<TResult>("TResult");
    *this += base;
}

int TResult::getTotalKeysStokres() const {
    return getCorrectKeysStrokes() + getWrongKeysStrokes();
}

int TResult::updateWPM(float deltaTime) {
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

QString TResult::getResume() {
    QString wpm = QString::number(this->getWPM());
    QString corrects = QString::number(correctKeystrokes_);
    QString wrongs = QString::number(wrongKeystrokes_);
    QString tot = QString::number(getTotalKeysStokres());

    return QString("WPM : %1<br/>Correct keyStrokes : %2<br/>"
            "Wrong keystrokes : %3<br/>Total keystrokes : %4")
            .arg(html::addTagToChars(wpm, "b"))
            .arg(html::addTagToChars(corrects, "span", "stlye='color : green;'"))
            .arg(html::addTagToChars(wrongs, "span", "style='color :red;'"))
            .arg(tot);
}

TResult::~TResult() {
}

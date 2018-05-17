/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */

/* 
 * File:   TResult.cpp
 * Author: boutina
 * 
 * Created on 24 novembre 2015, 11:27
 */

#include "tresult.h"

#include "Util/htmlhelper.h"
#include <QJsonObject>


TResult::TResult() {
}

int TResult::getTotalKeysStrokes() const {
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

void TResult::read(const QJsonObject &json)
{
	correctKeystrokes_ = json["correctKeyStrokes"].toInt();
	wrongKeystrokes_ = json["wrongKeyStrokes"].toInt();
	correctWords_ = json["correctWords"].toInt();
	wrongWords_ = json["wrongWords"].toInt();
	wordsPerMinute_ = json["wordsPerMinute"].toInt();
}

void TResult::write(QJsonObject &json) const
{
	json["correctKeyStrokes"] = correctKeystrokes_;
	json["wrongKeyStrokes"] = wrongKeystrokes_;
	json["correctWords"] = correctWords_;
	json["wrongWords"] = wrongWords_;
	json["wordsPerMinute"] = wordsPerMinute_;
}

TResult* TResult::operator+(const TResult& otherRes) {
    TResult *res = new TResult();
    res->setCorrectKeysStrokes(this->getCorrectWords() + otherRes.getCorrectKeysStrokes());
    res->setCorrectWords(this->getCorrectWords() + otherRes.getCorrectWords());
    res->setWrongKeysStrokes(this->getWrongKeysStrokes() + otherRes.getWrongKeysStrokes());
    res->setWrongWords(this->getWrongWords() + otherRes.getWrongWords());
    return res;
}

bool TResult::operator <(const TResult &otherRes) const{
    return getWPM() < otherRes.getWPM();
}

bool TResult::operator >(const TResult &otherRes) const{
    return getWPM() > otherRes.getWPM();
}

QString TResult::getResume() {
    QString wpm = QString::number(this->getWPM());
    QString corrects = QString::number(correctKeystrokes_);
    QString wrongs = QString::number(wrongKeystrokes_);
    QString tot = QString::number(getTotalKeysStrokes());

    return QString("WPM : %1<br/>Correct keyStrokes : %2<br/>"
            "Wrong keystrokes : %3<br/>Total keystrokes : %4")
            .arg(html::addTagToChars(wpm, "b"))
			.arg(html::addTagToChars(corrects, "span", "stlye='color : green;'"))
			.arg(html::addTagToChars(wrongs, "span", "style='color :red;'"))
            .arg(tot);
}

TResult::~TResult() {
}

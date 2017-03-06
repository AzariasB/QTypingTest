/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */

/* 
 * File:   TResult.h
 * Author: boutina
 *
 * Created on 24 novembre 2015, 11:27
 */

#ifndef TRESULT_H
#define TRESULT_H

#include <qdatastream.h>

#include <QString>


/**
 * This class is here to calculate the results of an exercice
 * this must be used to calculate the speed, and the accuracy
 */
class TResult {
public:
    TResult();
    TResult(const TResult &base);
    virtual ~TResult();

    int getCorrectKeysStrokes() const {
        return this->correctKeystrokes_;
    }

    int getWrongKeysStrokes() const {
        return this->wrongKeystrokes_;
    }

    int getCorrectWords() const {
        return this->correctWords_;
    }

    int getWrongWords() const {
        return this->wrongWords_;
    }

    int getWPM() const {
        return wordsPerMinute_;
    }

    void setCorrectKeysStrokes(int correctKeysStrokes) {
        this->correctKeystrokes_ = correctKeysStrokes;
    }

    void setWrongKeysStrokes(int wrongKeysStrokes) {
        this->wrongKeystrokes_ = wrongKeysStrokes;
    }

    void setWPM(int nwWPM){
        wordsPerMinute_ = nwWPM;
    }
    
    void incrWrongKeyStrokes(int incrementation = 1) {
        this->wrongKeystrokes_ += incrementation;
    } 
   

    void incrCorrectKeystrokes(int incrementation = 1) {
        this->correctKeystrokes_ += incrementation;
    }

    /* modif code de base from private to public */
    void setCorrectWords(int correctWords) {
        this->correctWords_ = correctWords;
    }

    void setWrongWords(int wrongWords) {
        this->wrongWords_ = wrongWords;
    }
    /* ************* */

    /**
     * Return a QString with all the values of the object
     * Helper to show results at the end of an exercice
     * or when watching the history of exercices
     * 
     * @return the resume of all the data
     */
    QString getResume();

    int updateWPM(float deltaTime/*in minutes*/);
    int getTotalWords() const;
    int getTotalKeysStrokes() const;

    TResult* operator+(const TResult &otherRes);

    TResult& operator+=(const TResult &otherRes);

    bool operator<(const TResult &otherRes) const;

    bool operator>(const TResult &otherRes) const;

    operator QString() const {
        return QString("wpm : %1, keystrokes : %2, correct key strokes : %3, wrong key strokes : %4")
                        .arg(wordsPerMinute_)
                        .arg(getTotalKeysStrokes())
                        .arg(correctKeystrokes_)
                        .arg(wrongKeystrokes_);
    }

private:
    int correctKeystrokes_ = 0;
    int wrongKeystrokes_ = 0;
    int correctWords_ = 0;
    int wrongWords_ = 0;
    int wordsPerMinute_ = 0;

    void incrCorrectWords() {
        this->correctWords_++;
    }

    void incrWrongWords() {
        this->wrongWords_++;
    }

//    void setWrongWords(int wrongWords) {
//        this->wrongWords_ = wrongWords;
//    }

    friend QDataStream &operator>>(QDataStream &in, TResult &result){
        in >> result.correctKeystrokes_ >> result.wrongKeystrokes_ >> result.wordsPerMinute_;
        return in;
    }

    friend QDataStream &operator<<(QDataStream &out, const TResult &result){
        out << result.correctKeystrokes_ << result.wrongKeystrokes_ << result.wordsPerMinute_;
        return out;
    }

};

QDataStream &operator>>(QDataStream &in, TResult &result);

QDataStream &operator<<(QDataStream &out, const TResult &result);

#endif /* TRESULT_H */


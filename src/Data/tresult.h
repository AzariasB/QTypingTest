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

#include "Util/htmlhelper.h"
#include "tuser.h"

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
    };

    int getWrongKeysStrokes() const {
        return this->wrongKeystrokes_;
    };

    int getCorrectWords() const {
        return this->correctWords_;
    };

    int getWrongWords() const {
        return this->wrongWords_;
    };

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
    
    void incrWrongKeyStrokes(int incrementation) {
        this->wrongKeystrokes_ += incrementation;
    } 
   

    void incrCorrectKeystrokes(int incrementation) {
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
    int getTotalKeysStokres() const;

    TResult* operator+(const TResult &otherRes);

    TResult& operator+=(const TResult &otherRes);

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




};

QDataStream &operator>>(QDataStream &in, TResult &result);

QDataStream &operator<<(QDataStream &out, const TResult &result);

#endif /* TRESULT_H */


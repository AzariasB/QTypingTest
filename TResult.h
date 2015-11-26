/* 
 * File:   TResult.h
 * Author: boutina
 *
 * Created on 24 novembre 2015, 11:27
 */

#ifndef TRESULT_H
#define	TRESULT_H

class TResult {
public:
    TResult();
    TResult(const TResult &base);
    virtual ~TResult();

    int getCorrectKeysStrokes() const {
        return this->correctKeystrokes;
    };

    int getWrongKeysStrokes() const {
        return this->wrongKeystrokes;
    };

    int getCorrectWords() const {
        return this->correctWords;
    };

    int getWrongWords() const {
        return this->wrongWords;
    };

    void setCorrectKeysStrokes(int correctKeysStrokes) {
        this->correctKeystrokes = correctKeysStrokes;
    }

    void setWrongKeysStrokes(int wrongKeysStrokes) {
        this->wrongKeystrokes = wrongKeysStrokes;
    }

    void incrWrongKeyStrokes(int incrementation) {
        this->wrongKeystrokes += incrementation;
    }

    void incrCorrectKeystrokes(int incrementation) {
        this->correctKeystrokes += incrementation;
    }

    int getWPM(float deltaTime = 0.f/*in minutes*/);
    int getTotalWords() const;
    int getTotalKeysStokres() const;

    TResult* operator+(const TResult &otherRes);

    TResult& operator+=(const TResult &otherRes);

private:
    int correctKeystrokes = 0;
    int wrongKeystrokes = 0;
    int correctWords = 0;
    int wrongWords = 0;
    int wordsPerMinute = 0;

    void incrCorrectWords() {
        this->correctWords++;
    }

    void incrWrongWords() {
        this->wrongWords++;
    }

    void setCorrectWords(int correctWords) {
        this->correctWords = correctWords;
    }

    void setWrongWords(int wrongWords) {
        this->wrongWords = wrongWords;
    }
};

#endif	/* TRESULT_H */


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
    virtual ~TResult();

    int getCorrectKeysStrokes() const {
        return this->correctKeysStrokes;
    };

    int getWrongKeysStrokes() const {
        return this->wrongKeysStrokes;
    };

    int getCorrectWords() const {
        return this->correctWords;
    };

    int getWrongWords() const {
        return this->wrongWords;
    };
    int getWordsPerMinute() const;
    int getTotalWords() const;
    int getTotalKeysStokres() const;
    
    void setCorrectKeysStrokes(int correctKeysStrokes) {
        this->correctKeysStrokes = correctKeysStrokes;
    }

    void setCorrectWords(int correctWords) {
        this->correctWords = correctWords;
    }

    void setWrongKeysStrokes(int wrongKeysStrokes) {
        this->wrongKeysStrokes = wrongKeysStrokes;
    }

    void setWrongWords(int wrongWords) {
        this->wrongWords = wrongWords;
    }

    
    TResult* operator+(const TResult &otherRes);

private:
    int correctKeysStrokes;
    int wrongKeysStrokes;
    int correctWords;
    int wrongWords;

};

#endif	/* TRESULT_H */


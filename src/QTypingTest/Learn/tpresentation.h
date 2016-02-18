/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */

/* 
 * File:   TPresentation.h
 * Author: boutina
 *
 * Created on 31 janvier 2016, 15:38
 */

#ifndef TPRESENTATION_H
#define TPRESENTATION_H

#include <QWidget>
#include <QVBoxLayout>

#include "tfingerposition.h"
#include "tvirtualkeyboard.h"

class TPresentation : public QWidget {
    Q_OBJECT
public:

    TPresentation(QString lang, QWidget *parent = 0);

    TPresentation(QString lang, QString charsToCopy, QWidget *parent = 0);

    virtual ~TPresentation() {

    }

    TVirtualKeyboard* getKeyboard() const {
        return keyboard_;
    }

    TFingerPosition* getPositions() const {
        return positions_;
    }

signals:
    void allCopied();

protected:

    void keyPressEvent(QKeyEvent *ev);


    void keyReleaseEvent(QKeyEvent *ev);


private:
    TVirtualKeyboard *keyboard_;
    TFingerPosition *positions_;

    QString toPress_ = "";
    QChar currentExample_ = '\0';

    void nextCharToCopy();


    void setupWidgets();

};

#endif /* TPRESENTATION_H */


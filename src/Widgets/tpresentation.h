/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
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
#include <QQueue>

#include "tfingerposition.h"
#include "tvirtualkeyboard.h"

class TPresentation : public QWidget {
    Q_OBJECT
public:

    TPresentation(TLayout&layout, QWidget *parent = 0);

    TPresentation(TLayout&layout, const QString &charsToCopy, QWidget *parent = 0);

    virtual ~TPresentation() {
		delete keyboard_;
		delete positions_;
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

	QQueue<QChar> toPress_;

	bool modifierPressed_ = false;

    void nextCharToCopy();


    void setupWidgets();

};

#endif /* TPRESENTATION_H */


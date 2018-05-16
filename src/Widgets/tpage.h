/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */

/* 
 * File:   TestTUser.cpp
 * Author: boutina
 * 
 * Created on 18 décembre 2015, 20:00
 */


#ifndef TPAGE_H
#define TPAGE_H

#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QKeyEvent>
#include <QApplication>
#include <QValidator>
#include <QList>

#include "Data/tresult.h"
#include "Util/factory.h"
#include "Data/tusermanager.h"

#include "tlabel.h"

class TPage : public QWidget {
    Q_OBJECT
public:
    explicit TPage(QWidget *parent = 0);
    TPage(const QString &model, QWidget *parent = 0);

    /**
     * Called by the parent dialog/Window whenever a key is pressed to
     * update the view and show the user where he is in the answer
     * 
     * @param ev the key event that the user triggerred
     */
    void update(QKeyEvent* ev);

    void updateLine(const QString &answer);

    void updateAsFirst() {
        this->toCopy_[currentTLabel_]->setFirst();
    }

	TResult &getResult() {
        return lineRes_;
    }
    
    const QString &text(){
        return globalAnswer_;
    }

    ~TPage();

    //##############################
    //  Signals
    //##############################
signals:
    /**
     * A Signal trigerred when the user typed the first character of the line
     */
    void startedPage();

    /**
	 *  Signal trigerred when there is no more text to copy on the page
     */
	void endedPage(TResult);
    
    
    /**
     * Called whenever the user tries to erase
     * an answer but is at the start of the page
     */
    void eraseOverflow();

public slots:
    
    bool typingAnswer(const QString &answer);
    
    
    void eraseAnswer();

private:
    /**
     * Put the elements on the widget
     */
    void setupPage();

    /**
     * Function to determine if the keypress event is valid (usable)
     * if it produces whatever letter (and is not a special char such as '\n'
     * 
     * @return if the key event can be seen as a 'valid' key event 
     */
    bool isValidKey(QKeyEvent *ev);


    /**
     * Function to update the necessary models (staistics)
     * so that the user knows what's his worst key
     * 
     * If the previous key was wrong, the current key will not counted as mistype
     * since it can be because of the speed
     * 
     * @param userAnswer the character typed by the user wich is the wrong answer
     */
    void handleMistype(QChar userAnswer, bool previousWasRight = false);

    /**
     * 
     * @return the current label
     */
    TLabel *label() const{
        return toCopy_[currentTLabel_];
    }

    //Attributes
    QVBoxLayout *tLineLayout_;
    //        QLineEdit *edition_;

    QList<TLabel*> toCopy_;

    QString globalAnswer_;
    QString lastAnswer_;
	TResult lineRes_;

    bool started_ = false;

    //The number of lines/label
    const int numberOfLines_ = 4;

    int currentTLabel_ = 0;

    int cursorPosition_ = 0;
};

#endif // TPAGE_H

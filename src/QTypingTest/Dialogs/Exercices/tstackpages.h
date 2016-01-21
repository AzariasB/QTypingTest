/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */
/* 
 * File:   StackPages.h
 * Author: boutina
 *
 * Created on 20 janvier 2016, 09:58
 */

#ifndef TSTACKPAGES_H
#define TSTACKPAGES_H

#include <QWidget>
#include <QStackedWidget>
#include <QStringList>
#include <QList>
#include <QKeyEvent>

#include "Data/tresult.h"
#include "QTypingTest/Dialogs/Exercices/tpage.h"


class TStackPages : public QStackedWidget {
    Q_OBJECT
public:
    TStackPages(QWidget *parent = 0);
    TStackPages(const TStackPages& orig);
    TStackPages(const QString &text, int numberOfPages = 1, QWidget *parent = 0);

    QString getText() const {
        return toCopy_.join(" ");
    };

    int currentPageIndex() const {
        return currentPage_;
    }

    int numberOfPages() const {
        return numberOfPages_;
    }
    
    TPage *currentPage() const{
        return static_cast<TPage*> (this->currentWidget());
    }

    virtual ~TStackPages() {
    };

signals:
    /**
     * Called whenever the current page is terminated
     */
    void pageEnded(TResult *pageResult);


    /**
     * Triggerred whever all the given text at the beginning was copied
     */
    void textFinished();
    
    
    /**
     * Called when the user typed the first letter of the exercice
     * wether the letter is right
     */
    void exerciceStarted();

public slots:
    /**
     * To call whenever a page is finished and the next one must begin !
     * 
     * @param previousScore the score of the line that was finished
     */
    void nextPage(TResult *previousScore);

    /**
     * Called whenever the user typed the first char on his keyboard
     * This permits to launch a timer.
     * 
     */
    void beginExercice();
    
    /**
     * Called whenever the user type on the keybaord and 
     * the game is not paused
     * 
     * @param ev the key event triggered by the user
     */
    void keyPressed(QKeyEvent *ev);

private:

    void setupPages(QString wholeText);

    int currentPage_ = 0;
    int numberOfPages_ = 1;

    QStringList toCopy_;
};

#endif /* STACKPAGES_H */


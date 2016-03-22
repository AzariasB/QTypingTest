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
#include <QDebug>

#include "Data/tresult.h"
#include "QTypingTest/Dialogs/Exercices/tpage.h"

class TStackPages : public QStackedWidget {
    Q_OBJECT
public:
    TStackPages(QWidget *parent = 0);
    TStackPages(const TStackPages& orig);
    TStackPages(int numberOfPages, QWidget *parent = 0);
    TStackPages(const QString &text, int numberOfPages = 1, QWidget *parent = 0);

    QString getText() const {
        return toCopy_.join(" ");
    };

    int numberOfPages() const {
        return count();
    }

    TPage *currentPage() const {
        return static_cast<TPage*> (this->currentWidget());
    }

    void addPage(QString pageText, bool isFirst = false);

    // \todo : change the name of the function... to somthing more explicit (Azarias)
    bool setFollowingPage();

    virtual ~TStackPages() {
    }

    /**
     * allocate the givent text
     * on the different pages
     * 
     * @param wholeText the text to allocate to the pages
     */
    void setupPages(QString wholeText);
    
    /**
     * Setter
     * 
     * @param numberOfP change the current number of pages
     */
    void setNumberOfPages(int numberOfP){
        numberOfPages_ = numberOfP;
    }
    

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
    int numberOfPages_ = 1;

    QStringList toCopy_;
};

#endif /* STACKPAGES_H */


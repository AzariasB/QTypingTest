/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
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

#include <QStackedWidget>

class TPage;
class TResult;

class TStackPages : public QStackedWidget {
    Q_OBJECT
public:
    TStackPages(QWidget *parent = 0);
    TStackPages(const TStackPages& orig);
    TStackPages(int numberOfPages, QWidget *parent = 0);
    TStackPages(const QString &text, int numberOfPages = 1, QWidget *parent = 0);

    QString getText() const {
        return toCopy_.join(" ");
    }

    int numberOfPages() const {
        return count();
    }

    TPage *currentPage() const;

    void addPage(const QString &pageText, bool isFirst = false);

    bool nextPage();

    virtual ~TStackPages() {
    }

    /**
     * allocate the given text
     * on the different pages
     * 
     * @param wholeText the text to allocate to the pages
     */
    void setupPages(const QString &wholeText);
    
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
    void pageEnded(const TResult &pageResult);


    /**
     * Triggerred whever all the given text at the beginning was copied
     */
    void textFinished();


    /**
     * Called when the user typed the first letter of the exercise
     * wether the letter is right
     */
    void exerciseStarted();


public slots:
    /**
     * To call whenever a page is finished and the next one must begin !
     * 
     * @param previousScore the score of the line that was finished
     */
    void nextPage(const TResult &previousScore);

    /**
     * Called whenever the user typed the first char on his keyboard
     * This permits to launch a timer.
     * 
     */
    void beginExercise();

    /* Answer typed */
    bool answerTyped(const QString &answer);


private:
    int numberOfPages_ = 1;

    QStringList toCopy_;
};

#endif /* STACKPAGES_H */


/* 
 * File:   TWindowTest.h
 * Author: boutina
 *
 * Created on 10 novembre 2015, 12:03
 */

#ifndef TWINDOWTEST_H
#define TWINDOWTEST_H

#include <QDialog>
#include <QWidget>
#include <QTime>
#include <QShortcut>
#include <QKeySequence>
#include <QVBoxLayout>
#include <QKeyEvent>

#include "Exercices/tstackpages.h"
#include "Exercices/ttoolbar.h"
#include "Data/tresult.h"
#include "Data/texercice.h"
#include "Util/factory.h"

class TWindowTest : public QDialog {
    Q_OBJECT
public:
    TWindowTest(QWidget* parent = 0) :
    QDialog(parent),
    results_(QList<TResult*>()),
    timeStart_(QTime(0, 0)),
    updateTimer_(new QTimer()),
    topToolbar_(TToolbar()),
    pages_(TStackPages(this)) {
        setupWidget();
    }

    TWindowTest(QString text, QWidget *parent = 0) :
    QDialog(parent),
    results_(QList<TResult*>()),
    timeStart_(QTime()),
    updateTimer_(new QTimer()),
    topToolbar_(TToolbar()),
    pages_(TStackPages(text, 2, this)) {
        setupWidget();
    }

    TWindowTest(QString text, int numberOfPages, QWidget *parent = 0) :
    QDialog(parent),
    results_(QList<TResult*>()),
    timeStart_(QTime()),
    updateTimer_(new QTimer()),
    topToolbar_(TToolbar()),
    pages_(TStackPages(text, numberOfPages, this)) {
        setupWidget();
    }

    virtual ~TWindowTest();

public slots:
    /**
     * To call whenever a line is finished and the next one must begin !
     * 
     * @param previousScore the score of the line that was finished
     */
    void saveResult(TResult *previousScore);

    void beginExercice();


    /**
     * Called whenever wa have the exerice is finished
     * 
     * @param a boolean to know if the user really ended the exercice
     * or if he exited
     */
    void exerciceFinished(bool forced = false);

    /**
     * Called whenever the user click on the pause/continue button
     * depending on the state, the button will react differently
     * if the exercice is paused, it will resume it
     * if the exercice is not paused, it will pause it
     */
    void pauseContinueExercice();
    
    
    /**
     * Called to update the clock of the toolbar
     */
    void updateClock();

signals:
    void endOfExercice(TResult *exeRes, QTime timeRealised);

    void closed();

protected:
    /**
     * Instead of having to focus on each of the lines
     * this function handle the keypress event for the whole dialog
     * 
     * @param ev the keyevent event
     */
    void keyPressEvent(QKeyEvent* ev);

    /**
     * Dialog keeps moving when changin the text of the label ...
     * 
     * @param the move event
     */
    void moveEvent(QMoveEvent *ev);

    /**
     * Create a signal when the dialog close
     * to warn the parent and reset the exercice
     * 
     * @param the close event
     */
    void closeEvent(QCloseEvent* ev);


    /**
     * Init function called as soon as the dialog is created
     * setup the options of the dialog and create the lines
     * depending on the given model
     * 
     */
    void setupWidget();
    
    /**
     * Setup the timer to update the
     * chronometer
     */
    void setupTimer();
    

    /**
     * Return the progression as a fraction
     * For example, if the user is at the first page and
     * the exercice is composed of two pages, it will return 
     * "1/2"
     * 
     * @return the page proression
     */
    QString getPageProgression() {
        return QString("%1/%2").arg(pages_.currentIndex() + 1).arg(pages_.numberOfPages());
    }

    /**
     * Because each resulst is stored in a list, at the end of the rush
     * the function needs to return a single result. 
     * This function sum up all the results
     * and return the total sum.
     * 
     * @return the sum of all the resulst of each lines
     */
    TResult *exerciceResult();

    /**
     * Initiate all the shorcuts of the dialogs
     * There are two type of shortucts
     *  - The 'hack' ones, that must be remove for the production
     *  - The normal ones, to help the user being more efficient
     */
    void setupShortcuts();

    /**
     * Set the timers of the exercice
     * and the values to update/calculate the time
     * realised by the user
     */
    void setTimers(int timeLimit);

private:
    QList<TResult*> results_;

    QTime timeStart_;

    QTimer *updateTimer_;

    /* The upper toolbar with play/pause button and indicators */
    TToolbar topToolbar_;

    /* The pages */
    TStackPages pages_;

    /* Save the ms elapsed if the user pause the exercice*/
    int elapsedMS_ = 0;


    /* The current state of the game */
    bool paused_ = false;

    /**
     * Connect all the events 
     * of the dialog
     */
    void connectEvents();
};

#endif /* TWINDOWTEST_H */


/* 
 * File:   TWindowTest.h
 * Author: boutina
 *
 * Created on 10 novembre 2015, 12:03
 */

#ifndef TWINDOWTEST_H
#define TWINDOWTEST_H

#include <QDialog>
#include <QList>
#include <QDebug>
#include <QTime>
#include <QTimer>
#include <QShortcut>
#include <QKeySequence>
#include <QVBoxLayout>
#include <QKeyEvent>
#include <QStackedWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLCDNumber>
#include <QSpacerItem>

#include "../TLine/tpage.h"
#include "../../Data/tresult.h"
#include "../../Data/texercice.h"
#include "../../Util/factory.h"

class TWindowTest : public QDialog {
    Q_OBJECT
public:
    TWindowTest(QString model, QWidget* parent);
    TWindowTest(TExercice *exercice, QWidget *parent);

    virtual ~TWindowTest();

public slots:
    /**
     * To call whenever a line is finished and the next one must begin !
     * 
     * @param previousScore the score of the line that was finished
     */
    void nextPage(TResult *previousScore);

    void beginExercice();

    /**
     * Update the LCD timer
     */
    void updateTimer();

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
    void keyPressEvent(QKeyEvent* ev) override;

    /**
     * Dialog keeps moving while changin the text of the label ...
     * 
     * @param the move event
     */
    void moveEvent(QMoveEvent *ev) override;

    /**
     * Create a signal when the dialog close
     * to warn the parent and reset the exercice
     * 
     * @param the close event
     */
    void closeEvent(QCloseEvent* ev) override;


private:
    /**
     * Init function called as soon as the dialog is created
     * setup the options of the dialog and create the lines
     * depending on the given model
     * 
     * @param textModel the string that the user will have to copy
     */
    void setupWidget(QString textModel);

    /**
     * Create the TLines and will :
     *  - Add them to the window via a layout
     *  - Connect all the events
     *  - Add the corresponding text into the Tline
     * 
     * @param model the model from where to create the lines
     * @return the lines created and event-connected
     */
    QList<tln::TPage*> createPages(QStringList model);

    /**
     * Create the top toolbar of the dialog
     * The toolbar contains :
     *  - A label to indicate his progression to the user
     *  - A pause/continue button 
     *  - A timer
     */
    void createToolBar();

    /**
     * Return the progression as a fraction
     * For example, if the user is at the first page and
     * the exercice is composed of two pages, it will return 
     * "1/2"
     * 
     * @return the page proression
     */
    QString getPageProgression() {
        return QString("%1/%2").arg(currentPage_ + 1).arg(numberOfPages_);
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


    QList<TResult*> results_;
    QTimer *timer_;

    int currentPage_ = 0;
    const int numberOfPages_ = 2;
    QTime timeStart_;
    QStackedWidget *stackWidget_;

    QVBoxLayout *centralLayout_;

    QPushButton *pauseButton_;
    QLCDNumber *LCDtimer_;
    QLabel *pageProgression_;

    /* Save the state of the dialog : in pause or in 'normal' mode*/
    bool isInPause = false;

    /* Save the ms elapsed if the user pause the exercice*/
    int elapsedMS_ = 0;

    /* Indicate how the time indicator must be updated */
    bool decrementTime_ = false;

    /* The time to do dot overpass
     * if the value is not negative, else it's 'unlimited' timer */
    int timeLimit_ = -1;
};

#endif /* TWINDOWTEST_H */


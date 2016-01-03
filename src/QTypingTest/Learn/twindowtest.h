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
#include <QShortcut>
#include <QKeySequence>
#include <QVBoxLayout>
#include <QKeyEvent>
#include <QStackedWidget>

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

signals:
    void endOfExercice(TResult *exeRes);

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
     * Because each resulst is stored in a list, at the end of the rush
     * the function needs to return a single result. 
     * This function sum up all the results
     * and return the total sum.
     * 
     * @return the sum of all the resulst of each lines
     */
    TResult *resultsSum();

    QList<TResult*> results_;
    int currentPage_ = 0;
    const int numberOfPages_ = 2;
    QTime timeStart_;
    QStackedWidget *stackWidget_;

};

#endif /* TWINDOWTEST_H */


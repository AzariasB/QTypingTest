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

#include "../TLine/tline.h"
#include "../../Data/tresult.h"
#include "../../Data/texercice.h"

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
    void nextLine(TResult *previousScore);
    
    /**
     * Called whenever a user erase at a line to come back on the previous line
     */
    void previousLine();
    void beginExercice();

signals:
    void endOfExercice(TResult *exeRes);

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
     * @param 
     */
    void moveEvent(QMoveEvent *ev) override;


private:
    /**
     * Init function called as soon as the dialog is created
     * setup the options of the dialog and create the lines
     * depending on the given model
     * 
     * @param textModel the string that the user will have to copy
     */
    void setupWidget(QStringList textModel);

    /**
     * Finding the closest space in sa list of single Qstrings
     * TODO : put this function int 'UTIL' 
     * 
     * @param search list of QStrings containing single char each.
     * @param indexStart index where to start the search
     * @return the index of the closes space in the list, strating from indexStart
     * if no space is found, the index of the last char is returned
     */
    int findClosestSpace(const QStringList* search, int indexStart);
    
    /**
     * Will split the text into differents parts to be able to display the 
     * given original string into differents line with aproximately the same length
     * 
     * 
     * @param text the text to split
     * @return the text splitted
     */
    QStringList splitText(QStringList text);
    
    /**
     * Create the TLines and will :
     *  - Add them to the window via a layout
     *  - Connect all the events
     *  - Add the corresponding text into the Tline
     * 
     * @param model the model from where to create the lines
     * @return the lines created and event-connected
     */
    QList<tln::TLine*> createLines(QStringList model);
    
    /**
     * Because each resulst is stored in a list, at the end of the rush
     * the function needs to return a single result. 
     * This function sum up all the results
     * and return the total sum.
     * 
     * @return the sum of all the resulst of each lines
     */
    TResult *resultsSum();

    QList<tln::TLine*> lines_;
    QList<TResult*> results_;
    int currentLine_ = 0;
    int numberOfLines_ = 4;
    QTime timeStart_;

};

#endif /* TWINDOWTEST_H */


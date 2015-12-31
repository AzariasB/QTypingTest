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
    void nextLine(TResult *previousScore);
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
    void createLines(QStringList textModel);

    /**
     * Finding the closest space in sa list of single Qstrings
     * TODO : put this function in namespaces instead of object
     * 
     * @param search list of QStrings containing single char each.
     * @param indexStart index where to start the search
     * @return the index of the closes space in the list, strating from indexStart
     * if no space is found, the index of the last char is returned
     */
    int findClosestSpace(const QStringList* search, int indexStart);

    QList<tln::TLine*> *lines_;
    TResult *totRes_ = new TResult();
    int currentLine_ = 0;
    int numberOfLines_ = 4;
    QTime timeStart_;

};

#endif /* TWINDOWTEST_H */


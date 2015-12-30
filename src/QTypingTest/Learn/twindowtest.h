/* 
 * File:   TWindowTest.h
 * Author: boutina
 *
 * Created on 10 novembre 2015, 12:03
 */

#ifndef TWINDOWTEST_H
#define	TWINDOWTEST_H

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
    TWindowTest(TExercice *exercice,QWidget *parent);

    virtual ~TWindowTest();

public slots:
    void nextLine(TResult *previousScore);
    void beginExercice();

signals:
    void endOfExercice(TResult *exeRes);



private:
    void createLines(QStringList textModel);
    int findClosestSpace(const QStringList* search, int indexStart);

    QList<tln::TLine*> *lines_;
    TResult *totRes_ = new TResult();
    int currentLine_ = 0;
    int numberOfLines_ = 4;
    QTime timeStart_;

};

#endif	/* TWINDOWTEST_H */


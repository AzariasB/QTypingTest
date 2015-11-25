/* 
 * File:   TWindowTest.h
 * Author: boutina
 *
 * Created on 10 novembre 2015, 12:03
 */

#ifndef TWINDOWTEST_H
#define	TWINDOWTEST_H

#include <QWidget>
#include <QList>
#include <QDebug>
#include <QTime>

#include "Tline.h"
#include "TResult.h"

class TWindowTest : public QWidget {
    Q_OBJECT
public:
    TWindowTest();
    TWindowTest(QString model, QWidget* parent);

    virtual ~TWindowTest();

public slots:
    void nextLine(TResult *previousScore);
    void beginExercice();

signals:
    void endOfExercice(TResult *exeRes);

private:
    void createLines(QString textModel);
    int findClosestSpace(const QStringList* search, int indexStart);

    QList<TLine*> *lines;
    TResult *totRes = new TResult();
    int currentLine = 0;
    int numberOfLines = 4;
    QTime timeStart;

};

#endif	/* TWINDOWTEST_H */


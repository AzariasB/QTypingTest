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
#include "Tline.h"

class TWindowTest : public QWidget {
    Q_OBJECT
public:
    TWindowTest();
    TWindowTest(QString model, QWidget* parent);

    virtual ~TWindowTest();

public slots:
    void nextLine();

signals:
    void endOfExercice();

private:
    void createLines(QString textModel);
    int findClosestSpace(const QStringList* search,int indexStart);

    QList<TLine*> *lines;
    int currentLine = 0;
    int numberOfLines = 4;

};

#endif	/* TWINDOWTEST_H */


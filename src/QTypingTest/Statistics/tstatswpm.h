#ifndef TSTATSWPM_H
#define TSTATSWPM_H

using namespace std;

#include <QWidget>
#include <QPainter>

#include <stdlib.h>
#include <time.h>
#include <iostream>

//#include "Data/texercice.h"
#include "Data/tuser.h"
#include "Data/tresult.h"


class TStatsWPM: public QWidget
{
public:
    TStatsWPM(TUser *user=0, QWidget *parent=0);

protected:
    void paintEvent(QPaintEvent *e);
    void createRandomXPoints();
    void createRandomYPoints();
    //void implementQHash(date_exercice_ date, TResult result);
//    resizeEvent();

private:
    TUser *user_;
    float mean_ = 0;

    QHash<date_exercice_*, TResult*> historyresults_; //a temporary array
    int xpoints_[]; //tmp array
    int ypoints_[]; // tmp array

    TResult myresult_; //for QHash
    //TExercice myexercice_; //for date_exercice
    int year = 2016;
    int month = 2;
    int day = 3;
    QDate date_;
    QDateTime mydatetime_; //for date_exercice
    date_exercice_ mydateexercice_;

    //date_exercice_ arraydate_[];
    //TResult arrayresult_[];
};

#endif // TSTATSWPM_H

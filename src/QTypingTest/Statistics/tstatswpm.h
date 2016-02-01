#ifndef TSTATSWPM_H
#define TSTATSWPM_H

using namespace std;

#include <QWidget>
#include <QPainter>

#include <stdlib.h>
#include <time.h>
#include <iostream>

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

private:
    TUser *user_;
    float mean_ = 0;

    QHash<date_exercice_*, TResult*> historyresults_; //a temporary array
    int xpoints_[]; //tmp array
    int ypoints_[]; // tmp array
    date_exercice_ arraydate_[];
    TResult arrayresult_[];
};

#endif // TSTATSWPM_H

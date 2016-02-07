#ifndef TSTATSWPM_H
#define TSTATSWPM_H

using namespace std;

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QEvent>
#include <QHash>

#include <stdlib.h>
#include <time.h>
#include <iostream>

#include "Data/tuser.h"
#include "Data/texercice.h"
#include "Data/tresult.h"


class TStatsWPM: public QWidget
{
public:
    TStatsWPM(TUser *user=0, QWidget *parent=0);

protected:
    void paintEvent(QPaintEvent *e);
    void createRandomYPoints();
    void mouseMoveEvent(QMouseEvent * e);
    void mousePressEvent(QMouseEvent *e);

private:
    TUser *user_;
    float mean_ = 0;

    QHash<date_exercice_*, TResult*> historyresults_; //a temporary array
    int ypoints_[]; // tmp array

    QHash<QPoint *,QRect> rectpoint_;
};

#endif // TSTATSWPM_H

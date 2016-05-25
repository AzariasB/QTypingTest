#ifndef TSTATSWPM_H
#define TSTATSWPM_H

using namespace std;

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QEvent>
#include <QHash>
#include <QDebug>
#include <QDate>

#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>

#include "Data/tuser.h"
#include "Data/texercice.h"
#include "Data/tresult.h"


class TStatsWPM: public QWidget
{
public:
    TStatsWPM(TUser *user=0, QWidget *parent=0);

protected:
    void initTestCase(){
        srand (time(NULL));
    }
    void drawGraph();
    void mouseMoveEvent(QMouseEvent * e);
    void paintEvent(QPaintEvent *ev);
    QRect getCurrRect(QMouseEvent * e);
    void calcMean();

    /* to delete later */
    int *createRandomPoints();
    void createRandomResult();
    void createFakeQHash();
    /* ***** */

private:
    TUser *user_;
    int mean_ = 0;
    float height_ = 0;
    float gapbetweeny_;
    QPoint currentpoint_;
    QRect currentrect_;
    QHash<date_exercice_,TResult> historyresults_;
    QHash<QPoint,QRect> rectpoint_;//If wa use the keys to draw the polygon, the point are disordonned

    /* to delete later */
    QList<QPoint> orderedPoints_; //Keep track of ther order of the points to draw
    QVector<TResult*> vectRes_;
    QVector<int> vectWPM;
    QDateTime *mydate_;
    /* ***** */

//    void initPoints();
    void createPointFromQHash();
    float getMaxWPM(QVector<int> vect);
    float getMinWPM(QVector<int> vect);
    void initValues();

};

//To be able to use QPoint as keys
inline uint qHash (const QPoint & key)
{
    return qHash (static_cast <qint64> (key.x () ) << 32 | key.y () );
}

#endif // TSTATSWPM_H

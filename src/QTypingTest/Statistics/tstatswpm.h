#ifndef TSTATSWPM_H
#define TSTATSWPM_H

using namespace std;

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QEvent>
#include <QHash>
#include <QDebug>

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
    void initTestCase(){
        srand (time(NULL));
    }
    void drawGraph();
    void mouseMoveEvent(QMouseEvent * e);
    void paintEvent(QPaintEvent *ev);
    QRect getCurrRect(QMouseEvent * e);
    void calcMean();
    //Temporaly => To be replaced wit points of user
    int *createRandomPoints();

private:
    TUser *user_;
    int mean_ = 0;
    QPoint currentpoint_;
    QRect currentrect_;

    //Keep track of ther order of the points to draw
    QList<QPoint> orderedPoints_;
    
    //If wa use the keys to draw the polygon, the point are disordonned
    QHash<QPoint,QRect> rectpoint_;

    void initPoints();
    void createRandomYPoints();

};

//To be able to use QPoint as keys
inline uint qHash (const QPoint & key)
{
    return qHash (static_cast <qint64> (key.x () ) << 32 | key.y () );
}

#endif // TSTATSWPM_H

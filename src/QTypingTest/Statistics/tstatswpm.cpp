#include "tstatswpm.h"

TStatsWPM::TStatsWPM(TUser *user, QWidget *parent):
    QWidget(parent),
    user_(user)
{

}

//todo getpoints

void TStatsWPM::paintEvent(QPaintEvent *e){
    QPainter p;
    QPen pen;
    p.begin(this);
    p.setBrush(Qt::cyan);
    p.setPen(Qt::NoPen);

    static const QPointF points[9] = {
        QPointF(0.0, 300.0),
        QPointF(0.0, 150.0),
        QPointF(50.0, 120.0),
        QPointF(100.0, 220.0),
        QPointF(150.0,70.0),
        QPointF(175.0,100.0),
        QPointF(220.0,20.0),
        QPointF(260.0,90.0),
        QPointF(260.0,300.0)
    };

    p.drawPolygon(points,9);

    pen.setBrush(Qt::white);
    pen.setWidth(6);
    p.setPen(pen);
    p.drawPoints(points,9);
    p.end();
}

#include "tstatswpm.h"

TStatsWPM::TStatsWPM(TUser *user, QWidget *parent):
    QWidget(parent),
    user_(user),
    orderedPoints_(QList<QPoint>()),
    rectpoint_(QHash<QPoint,QRect>())
{
    setFocus();
   // setMouseTracking(true);
    initPoints();
}

int *TStatsWPM::createRandomPoints(){

    int *val = (int*)malloc(sizeof(int)*20);
    val[0] = 300;

    int number;
    for(int i = 1; i<19; i++){
        number  = rand() % 300 + 1;
        val[i] = 300 - number;
    }

    val[19] = 300;
    return val;
}


void TStatsWPM::initPoints(){
    //create and display all polygone in a QPinater widget
    int *pointsY = createRandomPoints();
    orderedPoints_ << QPoint(0,300);
    for(int i=0;i<20;i++){
            QPoint point(i*50, pointsY[i]);
            QRect rect((i*50)-25,0,48,300);
            //rect.setCoords((i*50)-25,0,(i*50)+23,300);
            orderedPoints_ << point;
            rectpoint_[point] = rect;
    }
    orderedPoints_ << QPoint(20*50,300);
    delete pointsY;//Don't need it anymore
}

void TStatsWPM::paintEvent(QPaintEvent *ev){
    QPainter p;
    QPen pen;
    QVector<QPoint> points = orderedPoints_.toVector();
    p.begin(this);
    p.setBrush(Qt::cyan);
    p.setPen(Qt::NoPen);
    p.drawPolygon(QPolygon(points));
    pen.setBrush(Qt::white);
    pen.setWidth(6);
    p.setPen(pen);
    p.drawPoints(QPolygon(points));
    p.end();
}

void TStatsWPM::mouseMoveEvent(QMouseEvent *e){
    //cout << e->x() << "," << e->y() << endl;
}

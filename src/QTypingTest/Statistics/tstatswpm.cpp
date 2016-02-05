#include "tstatswpm.h"

TStatsWPM::TStatsWPM(TUser *user, QWidget *parent):
    QWidget(parent),
    user_(user),
    rectpoint_(QHash<QPoint *,QRect>())
{
    setFocus();
    setMouseTracking(true);
}

void TStatsWPM::createRandomYPoints(){

    int val;
    srand (time(NULL));
    this->ypoints_[0] = 300;

    for(int i = 1; i<19; i++){
        val  = rand() % 300 + 1;
        this->ypoints_[i] = 300 - val;
    }

    this->ypoints_[19] = 300;
}

void TStatsWPM::paintEvent(QPaintEvent *e){
    //create and display all polygone in a QPinater widget

    createRandomYPoints();

    QPainter p;
    QPen pen;
    p.begin(this);
    p.setBrush(Qt::cyan);
    p.setPen(Qt::NoPen);

    static QPoint *points = (QPoint*)malloc(sizeof(QPoint)*20);
    points[0] = QPoint(0,300);
    for(int i=1;i<19;i++){
        if(i==1){
            cout << "i = " << i << endl;
            QPoint *point = new QPoint(0, ypoints_[i]);
            points[i] = *point;
            QRect rect;//(0,0,24,300);
            rect.setCoords(0,0,24,300);
            rectpoint_.insert(point,rect);
        }else{
            cout << "i = " << i << endl;
            QPoint *point = new QPoint(i*50, ypoints_[i]);
            points[i] = *point;
            QRect rect((i*50)-25,0,48,300);
           // rect.setCoords((i*50)-25,0,(i*50)+23,300);
            rectpoint_.insert(point,rect);
        }
    }
    points[19] = QPoint(18*50,300);

    p.drawPolygon(points,20);

    pen.setBrush(Qt::white);
    pen.setWidth(6);
    p.setPen(pen);
    p.drawPoints(points,20);
    p.end();
}

void TStatsWPM::mouseMoveEvent(QMouseEvent *e){
    cout << e->x() << "," << e->y() << endl;
}

void TStatsWPM::mousePressEvent(QMouseEvent *e){
    cout << "click" << endl;
}

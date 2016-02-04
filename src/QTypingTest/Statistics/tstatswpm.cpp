#include "tstatswpm.h"

TStatsWPM::TStatsWPM(TUser *user, QWidget *parent):
    QWidget(parent),
    user_(user)
{
    //    float mean = 0;
    //    this->historyresults_ = user->getPracticeHistory();

    //    this->arraydate_ = historyresults_.keys(); //get all keys in an arbitrary order
    //    this->arrayresult_ = historyresults_.values(); //get all values in an arbitrary order

    //    int val = historyresults_.size();
    //    for (int var = 0; var < val; ++var) {
    //        mean += arrayresult_[var].getWPM();
    //    }

    //    this->mean_ = mean;

    //// Code for TEST ////
//    int year = 2016;
//    int month = 2;
//    int day = 3;

//    this->date_.setDate(year,month,day);
//    this->mydatetime_.setDate(date_);

//    this->myexercice_.buildExercice();

//    this->mydateexercice_.dateResult = mydatetime_ ;
//    this->mydateexercice_.exercice = myexercice_;

    //// End code for TEST ////

}

//todo getpoints

void TStatsWPM::createRandomXPoints(){

//    this->xpoints_[0] = 0; // first point always start on x = 0
//    //cout << "xpoints_[0] = " << xpoints_[0] << endl;
//    this->xpoints_[1] = 0; //second one also
//    //cout << "xpoints_[1] = " << xpoints_[1] << endl;

//    for(int i = 2;i<20;i++){
//        this->xpoints_[i] = this->xpoints_[i-1] + 25;
//        //cout << "xpoints_[" << i << "] = " << xpoints_[i] << endl;
//    }
}

void TStatsWPM::createRandomYPoints(){

    int val;

    srand (time(NULL));

    this->ypoints_[0] = 300; //last y is at 300

    for(int i = 1; i<19; i++){
        val  = rand() % 300 + 1;
        this->ypoints_[i] = 300 - val; //because the graph is reverse
        //cout << "The random n°" << i << "] = " << ypoints_[i] << endl;
    }

    this->ypoints_[19] = 300; //last y is at 300
    //cout << "ypoints_[19] = " << ypoints_[19] << endl;
}

//void TStatsWPM::implementQHash(){

//}

void TStatsWPM::paintEvent(QPaintEvent *e){
    //create and display all polygone in a QPinater widget

//    cout << "mydateexercice_.dateResult = " << this->mydateexercice_.dateResult << endl;
//    cout << "mydateexercice_.exercice = " << this->mydateexercice_.exercice << endl;

    //createRandomXPoints();
    createRandomYPoints();

    QPainter p;
    QPen pen;
    p.begin(this);
    p.setBrush(Qt::cyan);
    p.setPen(Qt::NoPen);

    static const QPoint points[20] = {
        QPoint(0,300), //origin, left bot corner
        QPoint(0, ypoints_[1]),
        QPoint(25, ypoints_[2]),
        QPoint(50, ypoints_[3]),
        QPoint(75,ypoints_[4]),
        QPoint(100,ypoints_[5]),
        QPoint(125,ypoints_[6]),
        QPoint(150,ypoints_[7]),
        QPoint(175,ypoints_[8]),
        QPoint(200,ypoints_[9]),
        QPoint(225,ypoints_[10]),
        QPoint(250,ypoints_[11]),
        QPoint(275,ypoints_[12]),
        QPoint(300,ypoints_[13]),
        QPoint(325,ypoints_[14]),
        QPoint(350,ypoints_[15]),
        QPoint(375,ypoints_[16]),
        QPoint(400,ypoints_[17]),
        QPoint(425,ypoints_[18]),
        QPoint(425,300)
    };

    for(int i =0; i<20;i++){
        cout << "Points["<<i<<"] = ("<<points[i].x()<<","<<points[i].y()<<")" << endl;
    }

    p.drawPolygon(points,20);

    pen.setBrush(Qt::white);
    pen.setWidth(6);
    p.setPen(pen);
    p.drawPoints(points,20);
    p.end();
}

#include "tstatswpm.h"

TStatsWPM::TStatsWPM(TUser *user, QWidget *parent):
    QWidget(parent),
    user_(user),
    orderedPoints_(QList<QPoint>()),
    currentpoint_(QPoint()),
    currentrect_(QRect()),
    mean_(int()),
    historyresults_(QHash<date_exercice_,TResult>()),
    rectpoint_(QHash<QPoint,QRect>())
{
    setFocus();
    setMouseTracking(true);

    /* temp functions */
    initPoints();
    createRandomResult();
    createFakeQHash();
}

/******* Temporary function to be delete later *******/
int *TStatsWPM::createRandomPoints(){

    int *val = (int*)malloc(sizeof(int)*20);
    val[0] = 300;

    int number;
    for(int i = 1; i<19; i++){
        number  = rand() % 300 + 1;
        val[i] = 300 - number;
    }
    return val;
}

void TStatsWPM::createRandomResult(){
    for(int i=0;i<20;i++){
       int number = rand()%(300-200)+200;
       vectRes_[i]->setCorrectKeysStrokes(number);
       cout << "correct key["<<i<<"] = "<<vectRes_[i]->getCorrectKeysStrokes()<<endl;
       int wrong = rand()%(30-10)+10;
       vectRes_[i]->setWrongKeysStrokes(wrong);
       cout << "wrong key["<<i<<"] = "<<vectRes_[i]->getWrongKeysStrokes()<<endl;
       vectRes_[i]->setCorrectWords(number/5);
       cout << "correct words["<<i<<"] = "<<vectRes_[i]->getCorrectWords()<<endl;
       vectRes_[i]->setWrongWords(wrong/5);
       cout << "wrong words["<<i<<"] = "<<vectRes_[i]->getWrongWords()<<endl;
       listWPM[i] = vectRes_[i]->updateWPM(2.0);
       cout << "WPM["<<i<<"] = "<<vectRes_[i]->getWPM()<<endl;
       cout << "WPM["<<i<<"] = "<<listWPM[i]<<endl;
    }
}

void TStatsWPM::createFakeQHash(){
    TExercice *exTyp = new TExercice(TExercice::LEARNING,QString("a"),QString("a"));
    date_exercice_ key;
    key.dateResult = QDateTime::currentDateTime();
    key.exercice = *exTyp;

    for(int i=0;i<20;i++){
       historyresults_[key] = *vectRes_[i];
    }
}

void TStatsWPM::initPoints(){
    int *pointsY = createRandomPoints();
    orderedPoints_ << QPoint(0,300);
    for(int i=0;i<19;i++){
        QPoint point(i*50, pointsY[i]);
        QRect rect((i*50)-25,0,48,300);
        orderedPoints_ << point;
        rectpoint_[point] = rect;
    }
    orderedPoints_ << QPoint(20*50,300);
    calcMean();

    delete pointsY;//Don't need it anymore
}
/******* End temporary functions *******/

QRect TStatsWPM::getCurrRect(QMouseEvent *e){
    QRect curr = currentrect_;

    QList <QRect> listrect = rectpoint_.values();

    if(e->x() > curr.left() && e->x()<curr.right()){
        return curr;
    }else{
        for(int i=0;i<rectpoint_.size();i++){
            if(e->x() > listrect[i].left() && e->x()<listrect[i].right()){
                curr = listrect[i];
                currentrect_ = curr;
                return curr;
            }
        }
    }
}

void TStatsWPM::calcMean(){
    int val = 0;
    for(int i=0;i<20;i++){
        val += orderedPoints_[i].y();
    }
    mean_ = val/20;
    cout << "mean = " << mean_ << endl;
}

void TStatsWPM::paintEvent(QPaintEvent *ev){
    QPainter p;
    this->setFixedWidth(20 * 50);
    this->setFixedHeight(300);
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

    pen.setBrush(Qt::red);
    p.setPen(pen);
    p.drawPoint(currentpoint_);

    pen.setBrush(Qt::black);
    pen.setWidth(1);
    p.setPen(pen);
    p.drawLine(QPoint(0,mean_),QPoint(1000,mean_));
    p.end();
}

void TStatsWPM::mouseMoveEvent(QMouseEvent *e){
    QRect rect = getCurrRect(e);
    QPoint pt = rectpoint_.key(rect);
    if(pt != currentpoint_){
        update();
        currentpoint_ = pt;
    }
}

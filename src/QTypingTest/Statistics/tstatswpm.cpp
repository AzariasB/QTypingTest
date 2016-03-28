#include "tstatswpm.h"

TStatsWPM::TStatsWPM(TUser *user, QWidget *parent):
    QWidget(parent),
    user_(user),
    orderedPoints_(QList<QPoint>()),
    currentpoint_(QPoint()),
    currentrect_(QRect()),
    mean_(int()),
    height_(int()),
    gapbetweeny_(int()),
    historyresults_(QHash<date_exercice_,TResult>()),
    rectpoint_(QHash<QPoint,QRect>()),
    vectRes_(QVector<TResult*>()),
    vectWPM(QVector<int>())
{
    setFocus();
    setMouseTracking(true);

    /* temp functions */
    //initPoints();
    createRandomResult();
    createFakeQHash();

    /* ****** */

    initValues();

    createPointFromQHash(); // to delete
}

/******* Temporary function to be delete later *******/
//int *TStatsWPM::createRandomPoints(){

//    int *val = (int*)malloc(sizeof(int)*20);
//    val[0] = 150;

//    int number;
//    for(int i = 1; i<19; i++){
//        number  = rand() % 150 + 1;
//        val[i] = 150 - number;
//    }
//    return val;
//}

void TStatsWPM::createRandomResult(){
    int val = 0;
    for(int i=0;i<40;i++){
        TResult *res = new TResult();
        int number = rand()%(1500-500)+200;
        int wrong = rand()%(50-10)+10;
        res->setCorrectKeysStrokes(number);
        res->setWrongKeysStrokes(wrong);
        res->setCorrectWords(number/5);
        res->setWrongWords(wrong/5);
        vectWPM << res->updateWPM(2.0);
        vectRes_ << res;
        val += vectWPM[i];
        qDebug() << "WPM at "<<i<<" = "<<vectWPM[i];
    }
    mean_ = val/40;
}

void TStatsWPM::createFakeQHash(){
    TExercice *exTyp = new TExercice(TExercice::LEARNING,QString("a"),QString("a"));
    date_exercice_ key;
    key.dateResult = QDateTime::currentDateTime();
    key.exercice = *exTyp;

    for(int i=0;i<40;i++){
        historyresults_[key] = *vectRes_[i];
    }
}

void TStatsWPM::createPointFromQHash(){

    // todo : récupérer QHash du user
    // todo : récupérer les TResult du QHash dans un vector ou list
    // todo : créer les points ainsi que les rectangles équivalents (comme pour initPoints avant)

//    orderedPoints_ << QPoint(0,(150));
//    for(int i=0;i<vectWPM.size()-1;i++){
//        QPoint point(i*25, (150-vectWPM[i]));
//        QRect rect((i*25)-12,0,24,(150));
//        orderedPoints_ << point;
//        rectpoint_[point] = rect;
//    }
//    orderedPoints_ << QPoint(38*25,(150));

    orderedPoints_ << QPoint(0,(height_));
    for(int i=0;i<vectWPM.size()-1;i++){
        QPoint point(i*25, (height_-vectWPM[i]));
        QRect rect((i*25)-12,0,24,(height_));
        orderedPoints_ << point;
        rectpoint_[point] = rect;
    }
    orderedPoints_ << QPoint(38*25,(height_));
}

//void TStatsWPM::initPoints(){
//    int *pointsY = createRandomPoints();
//    orderedPoints_ << QPoint(0,150);
//    for(int i=0;i<19;i++){
//        QPoint point(i*50, pointsY[i]);
//        QRect rect((i*50)-25,0,48,150);
//        orderedPoints_ << point;
//        rectpoint_[point] = rect;
//    }
//    orderedPoints_ << QPoint(20*50,150);

//    delete pointsY;//Don't need it anymore
//}
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

float TStatsWPM::getMaxWPM(QVector<int> vect){
    int max = -1;
    for(auto it:vect){
        if(it>max){
            max = it;
        }
    }
    return (float)max;
}

float TStatsWPM::getMinWPM(QVector<int> vect){
    int min = 1000;
    for(auto it:vect){
        if(it<min){
            min = it;
        }
    }
    return (float)min;
}

void TStatsWPM::initValues(){
    float max = getMaxWPM(vectWPM);
    float min = getMinWPM(vectWPM);
    float delta = max - min;
    qDebug() << "Delta: "<<delta;
    float gap = delta/8; // gap between eatch Y
    gapbetweeny_ = gap;
    qDebug()<< "GapBetweenY: "<<gapbetweeny_;
    height_ = max+logf(delta);
    qDebug()<<"Height :"<<height_;
}

void TStatsWPM::paintEvent(QPaintEvent *ev){
    QPainter p;
    this->setFixedWidth(20 * 50);
    QPen pen;
    QColor color;
    QVector<QPoint> points = orderedPoints_.toVector();
    p.begin(this);
    p.scale(5,5);

    //draw echelle y
    pen.setStyle(Qt::DashLine);
    pen.setWidth(1);
    p.setPen(pen);
    int i = gapbetweeny_;
    while (i<=height_) {
        pen.setBrush(Qt::white);
        p.setPen(pen);
        QString str = QString::number((int)height_-i);
        p.drawText(QPoint(1,i-2),str);
        pen.setBrush(Qt::gray);
        p.setPen(pen);
        p.drawLine(QPoint(0,i),QPoint(38*25,i));
        i+=gapbetweeny_;
    }

    //draw polygon
    color.setRgb(0,171,255);
    p.setBrush(color);
    p.setPen(Qt::NoPen);
    p.drawPolygon(QPolygon(points));

    //draw points
    pen.setBrush(Qt::white);
    pen.setWidth(6);
    p.setPen(pen);
    p.drawPoints(QPolygon(points));

    //current point
    pen.setBrush(Qt::red);
    p.setPen(pen);
    p.drawPoint(currentpoint_);

    //draw mean
    pen.setBrush(Qt::white);
    pen.setStyle(Qt::DashDotDotLine);
    pen.setWidth(2);
    p.setPen(pen);
    p.drawLine(QPoint(0,mean_),QPoint(38*25,mean_));

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

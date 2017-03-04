#include "tstatistics.h"


#include "Data/tuser.h"
#include "Data/tusermanager.h"



TStatistics::TStatistics(TUser *user, QWidget *parent):QWidget(parent),
    user_(user)
{
    init();
}

void TStatistics::init()
{
    if(user_){
        userResults_ = user_->getPracticeHistory()->values();
    }else if(TUserManager::getInstance().getCurrentUser()){
        user_ = TUserManager::getInstance().getCurrentUser();
        auto hash = user_->getPracticeHistory();
        if(hash){
            userResults_ = hash->values();
        }
    }
    if(user_){
        connect(user_ ,SIGNAL(statsChanged(TUser*)),this, SLOT(updateStats(TUser*)) );
    }

    connect(&TUserManager::getInstance(), SIGNAL(userChanged(TUser*)), this, SLOT(userChanged(TUser*)) );
    setMouseTracking(true);
}

void TStatistics::userChanged(TUser *nwUser)
{
    user_ = nwUser;
    if(user_){
        updateStats(user_);
        connect(user_ ,SIGNAL(statsChanged(TUser*)),this, SLOT(updateStats(TUser*)) );
    }
}

void TStatistics::updateStats(TUser *user)
{
    if(user){
        userResults_ = user->getPracticeHistory()->values();
        update();
    }
}

void TStatistics::paintEvent(QPaintEvent *ev)
{
    if(userResults_.size() > 0){
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        drawMainPolygon(painter);
        drawResult(painter);
        QWidget::paintEvent(ev);
    }else{
        qWarning() << "Not enought stats : " << userResults_.size();
    }
}

void TStatistics::drawMainPolygon(QPainter &painter)
{
    QList<point_result> graph = resultToPoint(userResults_);
    higlights_ = higlightsFromPoints(graph);
    graph.insert(0,{QPoint(0,height()), TResult() });
    graph.append({QPoint(graph.back().point.x(),height()), TResult()  });
    QPainterPath tmpPath;
    tmpPath.addPolygon(polyFromPointResult(graph));
    painter.fillPath(tmpPath, QBrush(Qt::gray));
    painter.drawEllipse(rectAroundPoint(currentHilight_.second.point));
}

void TStatistics::drawResult(QPainter &painter)
{
    QString res = QString("WPM : <b>%1</b> <br/> Correct keystrokes : <b color=\"red\" >%2</b> <br/> Wrong keystrokes : <b>%3</b>")
            .arg(currentHilight_.second.res.getWPM())
            .arg(currentHilight_.second.res.getCorrectKeysStrokes())
            .arg(currentHilight_.second.res.getWrongKeysStrokes());
    QRect border(10,10,200,45);
    painter.drawRect(border);
    painter.drawStaticText(10, 10 , QStaticText(res));
}

QPolygon TStatistics::polyFromPointResult(const QList<point_result> &points)
{
    QPolygon poly;
    for(point_result pr : points){
        poly << pr.point;
    }
    return poly;
}

void TStatistics::mouseMoveEvent(QMouseEvent *ev)
{
    if(!currentHilight_.first.contains(ev->pos()) ){
        currentHilight_ = findContainer(ev->pos());
        update();
    }
}

QPair<QRect, point_result> TStatistics::findContainer(const QPoint &point)
{
    QHashIterator<QRect, point_result> i(higlights_);
    while(i.hasNext()){
        i.next();
        if(i.key().contains(point)){
            return QPair<QRect, point_result>(i.key(), i.value());
        }
    }
    // Not found :/
    return QPair<QRect, point_result>();
}

QHash<QRect, point_result> TStatistics::higlightsFromPoints(const QList<point_result> &points)
{
    QHash<QRect, point_result> higlights;
    int step = width();
    if(points.size() > 1){
        step = points[1].point.x() - points[0].point.x();
    }
    for(auto it = points.begin(); it != points.end(); ++it){
        int left = (*it).point.x() - (step >> 1);
        QRect rect(left,0,step, height());
        higlights[rect] = *it;
    }
    return higlights;
}

QList<point_result> TStatistics::resultToPoint(const QList<TResult> &results)
{
    minWPM_ = getMinWPM(results);
    maxWPM_ = getMaxWPM(results);
    step_ = width() / results.size();
    QList<point_result> points;
    int currentX = step_;
    for(auto it = results.cbegin(); it != results.cend(); ++it){
        QPoint p = translate(*it);
        p.setX(currentX);
        currentX += step_;
        point_result pr = {p,*it};
        points <<  pr;
    }
    return points;
}

QRect TStatistics::rectAroundPoint(const QPoint &point)
{
    int rectSide = 10;
    int top = point.y() - (rectSide>>1);
    int left = point.x() - (rectSide>>1);
    return QRect(left,top, rectSide, rectSide);
}

QPoint TStatistics::translate(const TResult &res)
{
    QPoint p;
    int maxH = height() - (height()*0.1);
    int divisor = qMax(1, maxWPM_ - minWPM_);
    int a = -maxH/divisor;
    int b = maxH + (maxH*minWPM_)/divisor;
    p.setY(a*res.getWPM() + b);
    return p;
}

QPoint* TStatistics::listToPointArray(const QList<QPoint> &points)
{
    QPoint* arr = new QPoint[points.size()];
    std::copy(points.cbegin(), points.cend(),arr);
    return arr;
}

int TStatistics::getMaxWPM(const QList<TResult> &results)
{
    TResult max = *std::max_element(results.begin(), results.end());
    return max.getWPM();
}

int TStatistics::getMinWPM(const QList<TResult> &results)
{
    TResult min = *std::min_element(results.begin(), results.end());
    return min.getWPM();
}

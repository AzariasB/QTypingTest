#include "tstatistics.h"

TStatistics::TStatistics(QWidget *parent) : QWidget(parent),
user_(nullptr)
{
    init();
}

TStatistics::TStatistics(TUser *user, QWidget *parent):QWidget(parent),
    user_(user)
{
    init();
}

void TStatistics::init()
{
    if(user_){
        userResults_ = user_->getPracticeHistory().values();
    }
    setMouseTracking(true);
}

void TStatistics::paintEvent(QPaintEvent *ev)
{
    if(user_){
        QPainter painter(this);
        QList<QPoint> graph = resultToPoint(userResults_);
        higlights_ = higlightsFromPoints(graph);
        graph.insert(0,QPoint(0,height()));
        graph.append(QPoint(graph.back().x(),height()));
        QPainterPath tmpPath;
        tmpPath.addPolygon(QPolygon(graph.toVector()));
        painter.fillPath(tmpPath, QBrush(Qt::gray));
        painter.drawEllipse(rectAroundPoint(currentHilight_.second));
        QWidget::paintEvent(ev);
    }
}

void TStatistics::mouseMoveEvent(QMouseEvent *ev)
{
    if(!currentHilight_.first.contains(ev->pos()) ){
        currentHilight_ = findContainer(ev->pos());
        update();
    }
}

QPair<QRect, QPoint> TStatistics::findContainer(const QPoint &point)
{
    QHashIterator<QRect, QPoint> i(higlights_);
    while(i.hasNext()){
        i.next();
        if(i.key().contains(point)){
            return QPair<QRect, QPoint>(i.key(), i.value());
        }
    }
    // Not found :/
    return QPair<QRect, QPoint>();
}

QHash<QRect, QPoint> TStatistics::higlightsFromPoints(const QList<QPoint> &points)
{
    QHash<QRect, QPoint> higlights;
    int step = width();
    if(points.size() > 1){
        step = points[1].x() - points[0].x();
    }
    qDebug() << points;
    for(auto it = points.begin(); it != points.end(); ++it){
        int left = (*it).x() - (step >> 1);
        QRect rect(left,0,step, height());
        qDebug() << rect;
        higlights[rect] = *it;
    }
    return higlights;
}

QList<QPoint> TStatistics::resultToPoint(const QList<TResult> &results)
{
    minWPM_ = getMinWPM(results);
    maxWPM_ = getMaxWPM(results);
    step_ = width() / results.size();
    QList<QPoint> points;
    int currentX = 0;
    for(auto it = results.cbegin(); it != results.cend(); ++it){
        QPoint p = translate(*it);
        p.setX(currentX);
        currentX += step_;
        points <<  p;
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
    int divisor = qMax(1, maxWPM_ - minWPM_);
    int a = -height()/divisor;
    int b = height() + (height()*minWPM_)/divisor;
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

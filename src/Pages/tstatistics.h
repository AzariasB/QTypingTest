/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */

#ifndef TSTATISTICS_H
#define TSTATISTICS_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QStaticText>
#include <QTextDocument>
#include <stdlib.h>

#include "Data/tresult.h"

class TUser;
class TUserManager;
class TResult;

struct point_result {
	QPoint point;
	TResult res;
};

class TStatistics : public QWidget
{
    Q_OBJECT


public:
    explicit TStatistics(TUser *user = 0, QWidget *parent = 0);


protected:
    void paintEvent(QPaintEvent *ev);

    void mouseMoveEvent(QMouseEvent *ev);

signals:

public slots:
    void updateStats(TUser *user);

    void userChanged(TUser *nwUser);

private:

    //Methods

    void init();

    void drawMainPolygon(QPainter &painter);

    void drawResult(QPainter &painter);

    QList<point_result> resultToPoint(const QList<TResult> &results);

    int getMinWPM(const QList<TResult> &results);

    int getMaxWPM(const QList<TResult> &results);

    QPoint translate(const TResult& res);

    QPoint *listToPointArray(const QList<QPoint> &points);

	QRect rectAroundPoint(const QPoint &point);

    QPair<QRect, point_result> findContainer(const QPoint &point);

    QHash<QRect, point_result> higlightsFromPoints(const QList<point_result> &points);

    QPolygon polyFromPointResult(const QList<point_result> &points);

    //attributes
    int maxWPM_;
    int minWPM_;
    int step_;

    /* The base user for statistics */
    TUser *user_;

    /* Save the user's result to avoir research them everytime */
    QList<TResult> userResults_;

    /* Positions where the mouse has to be to higlith a point */
    QHash<QRect, point_result> higlights_;

    /* Save the current pos of mouse to avoir expensive calculations */
    QPair<QRect,point_result> currentHilight_;
};

inline uint qHash(const QRect & key) {
    return qHash(QString("%1,%2,%3,%4").arg(key.x())
                 .arg(key.y())
                 .arg(key.width())
                 .arg(key.height()));
}

#endif // TSTATISTICS_H

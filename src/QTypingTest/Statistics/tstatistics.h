#ifndef TSTATISTICS_H
#define TSTATISTICS_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>

#include "Data/tuser.h"
#include "Data/tusermanager.h"
#include <stdlib.h>

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

    QList<QPoint> resultToPoint(const QList<TResult> &results);

    int getMinWPM(const QList<TResult> &results);

    int getMaxWPM(const QList<TResult> &results);

    QPoint translate(const TResult& res);

    QPoint *listToPointArray(const QList<QPoint> &points);

    QRect rectAroundPoint(const QPoint &point);

    QPair<QRect, QPoint> findContainer(const QPoint &point);

    QHash<QRect, QPoint> higlightsFromPoints(const QList<QPoint> &points);

    //attributes
    int maxWPM_;
    int minWPM_;
    int step_;

    /* The base user for statistics */
    TUser *user_;

    /* Save the user's result to avoir research them everytime */
    QList<TResult> userResults_;

    /* Positions where the mouse has to be to higlith a point */
    QHash<QRect, QPoint> higlights_;

    /* Save the current pos of mouse to avoir expensive calculations */
    QPair<QRect, QPoint> currentHilight_;
};

inline uint qHash(const QRect & key) {
    return qHash(QString("%1,%2,%3,%4").arg(key.x())
                 .arg(key.y())
                 .arg(key.width())
                 .arg(key.height()));
}

#endif // TSTATISTICS_H

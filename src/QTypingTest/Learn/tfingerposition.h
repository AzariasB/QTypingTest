/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */

/* 
 * File:   TFingerPosition.h
 * Author: boutina
 *
 * Created on 30 janvier 2016, 14:33
 */

#ifndef TFINGERPOSITION_H
#define TFINGERPOSITION_H

#include <QWidget>
#include <QPainter>
#include <QPainterPath>
#include <QBrush>
#include <QList>
#include <QVector>
#include <QPolygon>
#include <QDebug>
#include <QPaintEvent>
#include <QKeyEvent>

#include "Util/filehelper.h"

class TFingerPosition : public QWidget {
    Q_OBJECT
public:
    TFingerPosition(QWidget *parent = 0);

    virtual ~TFingerPosition() {
    }

    enum FINGER {
        LEFT_PINKY, LEFT_RING, LEFT_MIDDLE, LEFT_INDEX, 
        RIGHT_INDEX, RIGHT_MIDDLE, RIGHT_RING, RIGHT_PINKY,
        NO_FINGER , TOTAL_FINGERS
    };

public slots:
    void enableFinger(FINGER id);
    
    void disableFinger(FINGER id);

protected:

    void paintEvent(QPaintEvent *ev);

private:
    /**
     A list of list of point :
     * list of point for each point of a single finger
     * list of list for each fingers
     * 
     */
    QList< QVector<QPoint> > fingersPoints_ =
    {
        {QPoint(44,251),QPoint(86,205),QPoint(18,102),QPoint(0,102),QPoint(0,158)},//44,251 86,205 18,102 0,102 0,158
        {QPoint(93,201),QPoint(151,190),QPoint(92,31),QPoint(44,37)},//93,201 151,190 92,31 44,37
        {QPoint(161,174),QPoint(222,174),QPoint(222,0),QPoint(161,0)},//161,174 222,174 222,0 161,0
        {QPoint(222,185),QPoint(284,207),QPoint(322,50),QPoint(260,24)}//222,185 284,207 322,50 260,24
    };

    QList<int> activeFingers_;
    
    void initPoints();


    /**
     * Creates the points of the right hand
     * by doing the symmetric of the left hand
     * initLeftHand must be called before this function
     */
    void initRightHand();

    /**
     * Create a new point and set this point's
     * x to the same as the origin, and the y
     * to the symmetric of the origin
     * 
     * @param origin the original point
     * @return the symmetric of thie point based on the middle axis of the image
     */
    QPoint getSymmetric(const QPoint& origin) const;
};

#endif /* TFINGERPOSITION_H */


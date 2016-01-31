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
        LEFT_PINKY, LEFT_RING, LEFT_MIDDLE, LEFT_INDEX, RIGHT_INDEX, RIGHT_MIDDLE_RIGHT_RING, RIGHT_PINKY
    };

public slots:
    void enableFinger(FINGER id);
    
    void disableFinger(FINGER id);

protected:

    void paintEvent(QPaintEvent *ev);


    void keyPressEvent(QKeyEvent *ev);


    void keyReleaseEvent(QKeyEvent *ev);


private:
    /**
     A list of list of point :
     * list of point for each point of a single finger
     * list of list for each fingers
     * 
     */
    QList< QVector<QPoint>* > fingersPoints_;

    QList<int> activeFingers_;
    

    void initPoints();

    /**
     * Create a list of list of point from 
     * the given string lsit.
     * Each string must be written as follow :
     * (\d+,\d+)\s*
     * The first number is the X coordinate of the point
     * The second number is the Y coordinate of the point
     * 
     * @param fingers the string of points for each finger
     */
    void initLeftHand(QStringList fingers);

    /**
     * Creates the points of the right hand
     * by doing the symmetric of the left hand
     * initLeftHand must be called before this function
     */
    void initRightHand();

    /**
     * create a point with the given string
     * the string must be as follow :
     * \d+,\d+
     * where the first number if the x coordinate
     * and the second number if the y coordinate
     * 
     * @param coordinates the coordinates of the point
     */
    QPoint createPoint(const QString& coordinates) const;

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


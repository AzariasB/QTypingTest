/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */


/* 
 * File:   TFingerPosition.cpp
 * Author: boutina
 * 
 * Created on 30 janvier 2016, 14:33
 */

#include <qt5/QtCore/qlogging.h>
#include <qt5/QtCore/qstring.h>
#include <qt5/QtGui/qevent.h>

#include "tfingerposition.h"

TFingerPosition::TFingerPosition(QWidget* parent) :
QWidget(parent),
fingersPoints_(QList< QVector<QPoint>* >()),
activeFingers_(QList<int>()) {
    setFixedSize(400,200);
    initPoints();
}

void TFingerPosition::initPoints() {
    QString points = file::readFile("etc/fingers.txt");
    QStringList fingers = points.split("\n", QString::SkipEmptyParts);
    initLeftHand(fingers);
    initRightHand();
}

void TFingerPosition::initLeftHand(QStringList fingers) {

    for (int i = 0; i < fingers.size(); i++) {
        QStringList pointsPosition = fingers[i].split(" ", QString::SkipEmptyParts);
        QVector<QPoint> *points = new QVector<QPoint>();
        for (int j = 0; j < pointsPosition.size(); j++) {
            points->append(createPoint(pointsPosition[j]));
        }
        fingersPoints_.append(points);
    }
}

void TFingerPosition::initRightHand() {
    //Size of image/2 = 800/2 = 400
    int size = fingersPoints_.size();
    for (int i = size - 1; i >= 0; i--) {
        QVector<QPoint> *origin = fingersPoints_[i];
        QVector<QPoint> *points = new QVector<QPoint>();
        for (int j = 0; j < origin->size(); j++) {
            points->append(getSymmetric(origin->at(j)));
        }
        fingersPoints_.append(points);
    }
}

QPoint TFingerPosition::getSymmetric(const QPoint& origin) const {
    int middleImage = 400;
    QPoint point;
    point.setX(origin.x() + ((middleImage - origin.x()) << 1));
    point.setY(origin.y());
    return point;
}

QPoint TFingerPosition::createPoint(const QString& coordinates) const {
    QPoint point;
    QStringList xAndY = coordinates.split(",");
    point.setX(xAndY.at(0).toInt());
    point.setY(xAndY.at(1).toInt());
    return point;
}

void TFingerPosition::disableFinger(FINGER id) {
    if (activeFingers_.contains(id) && id < NO_FINGER ) {
        activeFingers_.removeAll(id);
    }
    update();
}

void TFingerPosition::enableFinger(FINGER id) {
    if (!activeFingers_.contains(id) && id < NO_FINGER ) {
        activeFingers_.append(id);
    }
    update();
}

void TFingerPosition::paintEvent(QPaintEvent* ev) {
    QPainter painter(this);
    painter.scale(0.5, 0.5);

    QPainterPath tmpPath;
    for (auto elem : activeFingers_) {
        QVector<QPoint> *pol = fingersPoints_[elem];
        QPolygon p(*pol);
        tmpPath.addPolygon(p);
    }
    painter.fillPath(tmpPath, QBrush(Qt::blue));

    QImage image("./etc/images/hands.png");
    painter.drawImage(image.rect(), image);
}

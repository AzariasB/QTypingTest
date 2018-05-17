/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */


/* 
 * File:   TFingerPosition.cpp
 * Author: boutina
 * 
 * Created on 30 janvier 2016, 14:33
 */

#include "tfingerposition.h"
#include <QPainter>
#include <QPainterPath>
#include <QBrush>
#include <QList>
#include <QVector>
#include <QPolygon>
#include <QDebug>
#include <QPaintEvent>


TFingerPosition::TFingerPosition(QWidget* parent) :
	QWidget(parent),
	activeFingers_(QList<int>()) {
		setFixedSize(400,200);
		initPoints();
	}

void TFingerPosition::initPoints() {
	initRightHand();
}

bool TFingerPosition::isLeftHand(FINGER id){
	return id >= LEFT_PINKY && id <= LEFT_INCH;
}

bool TFingerPosition::isRightHand(FINGER id){
	return id >= RIGHT_INCH && id <= RIGHT_PINKY;
}

void TFingerPosition::initRightHand() {
	//Size of image/2 = 800/2 = 400
	int size = fingersPoints_.size();
	for (int i = size - 1; i >= 0; i--) {
		QVector<QPoint> origin = fingersPoints_[i];
		QVector<QPoint> points;
		for (int j = 0; j < origin.size(); j++) {
			points.append(getSymmetric(origin[j]));
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

void TFingerPosition::reset(){
	activeFingers_.clear();
}

void TFingerPosition::paintEvent(QPaintEvent*) {
	QPainter painter(this);
	painter.scale(0.5, 0.5);

	QPainterPath tmpPath;
	for (auto elem : activeFingers_) {
		QVector<QPoint> pol = fingersPoints_[elem];
		QPolygon p(pol);
		tmpPath.addPolygon(p);
	}
	painter.fillPath(tmpPath, QBrush(Qt::blue));

	QImage image(":/images/hands.png");
	painter.drawImage(image.rect(), image);
}

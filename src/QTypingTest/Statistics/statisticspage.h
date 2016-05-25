/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */

/*
 * File:   TStatisticspage.h
 * Author: thubep
 *
 * Created on 27 janvier 2016, 12:43
 */

#ifndef TSTATISTICSPAGE_H
#define TSTATISTICSPAGE_H

#include <QWidget>
#include <QDebug>
#include <QPainter>
#include <QPointF>
#include <QFont>

#include "Data/tresult.h"
#include "Data/tuser.h"

class TStatisticspage : public QWidget {
    Q_OBJECT
public:

    TStatisticspage(QWidget *parent=0);

    virtual ~TStatisticspage(){}
};

#endif /* TSTATISTICSPAGE_H */


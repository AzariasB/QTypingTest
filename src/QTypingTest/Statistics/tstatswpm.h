#ifndef TSTATSWPM_H
#define TSTATSWPM_H

#include <QWidget>
#include <QPainter>

#include "Data/tuser.h"
#include "Data/tresult.h"

class TStatsWPM: public QWidget
{
public:
    TStatsWPM(TUser *user=0, QWidget *parent=0);

protected:
    void paintEvent(QPaintEvent *e);

private:
    TUser *user_;
    float mean_;
};

#endif // TSTATSWPM_H

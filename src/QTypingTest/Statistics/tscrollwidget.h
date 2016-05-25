#ifndef TSCROLLWIDGET_H
#define TSCROLLWIDGET_H

using namespace std;

#include <QWidget>
#include <QScrollArea>
#include <QLayout>
#include <QTextEdit>

#include "tlayoutwidget.h"
#include "tstatswpm.h"

class TScrollWidget: public QWidget
{
public:
    TScrollWidget(QWidget *parent=0);

private:
    QScrollArea *area_;
    QHBoxLayout *layout_;
    TStatsWPM *twpm_;
    TLayoutWidget *lw_;
};


#endif // TSCROLLWIDGET_H


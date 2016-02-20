#include "tscrollwidget.h"

TScrollWidget::TScrollWidget(QWidget *parent):
    QWidget(parent)
{
    area_ = new QScrollArea(); //will contain the graph (twpm_)
    layout_ = new QHBoxLayout(this); //will contain the scrollArea and the layout where informations will be display

    lw_ = new TLayoutWidget(); //for informations
    twpm_ = new TStatsWPM(); //graph

    lw_->setMinimumWidth(100);

    twpm_->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    twpm_->setMinimumSize(area_->size());

    area_->setWidget(twpm_); //add twpm_ into the scrollArea

    layout_->addWidget(lw_); //add the tlayoutwidget into the main widget
    layout_->addWidget(area_); // add the scrollarea into the main widget
}

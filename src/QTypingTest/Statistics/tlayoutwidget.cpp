#include "tlayoutwidget.h"

TLayoutWidget::TLayoutWidget(QWidget *parent):
    QWidget(parent)
{
    vboxlayout_ = new QVBoxLayout(this);

    label1 = new QLabel(tr("Label 1"));
    label2 = new QLabel("Label 2");
    label3 = new QLabel("Label 3");
    label4 = new QLabel("Label 4");
    label5 = new QLabel("Label 5");

    vboxlayout_->addWidget(label1);
    vboxlayout_->addWidget(label2);
    vboxlayout_->addWidget(label3);
    vboxlayout_->addWidget(label4);
    vboxlayout_->addWidget(label5);
}

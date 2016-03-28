#include "tlayoutwidget.h"

TLayoutWidget::TLayoutWidget(QWidget *parent):
    QWidget(parent)
{
    vboxlayout_ = new QVBoxLayout(this);

    label1 = new QLabel(tr("Lowest WPM : "));
    label2 = new QLabel("Average WPM : ");
    label3 = new QLabel("Highest WPM : ");
    label4 = new QLabel("Label 4");
    label5 = new QLabel("Label 5");

    vboxlayout_->addWidget(label1);
    vboxlayout_->addWidget(label2);
    vboxlayout_->addWidget(label3);
    vboxlayout_->addWidget(label4);
    vboxlayout_->addWidget(label5);
}

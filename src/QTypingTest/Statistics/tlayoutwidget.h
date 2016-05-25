#ifndef TLAYOUTWIDGET_H
#define TLAYOUTWIDGET_H

using namespace std;

#include <QWidget>
#include <QTextEdit>
#include <QScrollArea>
#include <QLabel>
#include <QVBoxLayout>

class TLayoutWidget: public QWidget
{
public:
    TLayoutWidget(QWidget *parent=0);

private:
    QVBoxLayout *vboxlayout_;
    QLabel* label1;
    QLabel* label2;
    QLabel* label3;
    QLabel* label4;
    QLabel* label5;
};

#endif // TLAYOUTWIDGET_H

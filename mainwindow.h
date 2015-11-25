#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QApplication>
#include <QVector>
#include <QFile>
#include <QDebug>
#include <QMessageBox>

#include "TWindowTest.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void showEndMessage(TResult *finalRes);

};

#endif // MAINWINDOW_H

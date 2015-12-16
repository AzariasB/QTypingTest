#include "QTypingTest/mainwindow.h"
#include "QTypingTest/THomePage.h"
#include <QApplication>
#include <qt5/QtCore/qlogging.h>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    //    MainWindow w;
    //    w.show();
    THomePage hp;
    hp.show();


    return a.exec();
}

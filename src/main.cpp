//#include "QTypingTest/THomePage.h"

#include <QApplication>
#include <QFile>
#include <QDebug>

#include "QTypingTest/THomePage.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    THomePage hp;
    hp.show();

    return a.exec();
}

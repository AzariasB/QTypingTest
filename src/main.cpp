#include <QApplication>
#include <QFile>
#include <QDebug>

#include "QTypingTest/thomepage.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    THomePage hp;
    hp.show();

    return a.exec();
}

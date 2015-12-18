#include "QTypingTest/THomePage.h"
#include <QApplication>
#include <qt5/QtWidgets/qapplication.h>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    THomePage hp;
    hp.show();


    return a.exec();
}

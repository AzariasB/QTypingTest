

#include <QApplication>
#include <QDebug>
#include <QDir>
#include <time.h>
#include <QFile>

#include "QTypingTest/thomepage.h"


int main(int argc, char *argv[]) {    
    
    srand(time(NULL)); //Random number generation
    QApplication a(argc, argv);
    qDebug() << "Running from " << QDir::currentPath();

    //Set style
    THomePage hp;


    QFile file(file::getStylesheet("style"));
    if (file.exists()) {
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Could not open file, please check the permissions";
        } else {
            hp.setStyleSheet(QLatin1String(file.readAll()));
        }
        file.close();
    } else {
        qDebug() << "Could not load stylesheet";
    }

    hp.show();

    return a.exec();
}

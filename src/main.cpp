

#include <QApplication>
#include <QDebug>
#include <time.h>

#include "QTypingTest/thomepage.h"

int main(int argc, char *argv[]) {
    srand(time(NULL));//Random number generation
    QApplication a(argc, argv);
    
    
    THomePage hp;
    hp.show();

    return a.exec();
}

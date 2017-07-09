

#include <QApplication>
#include <QDebug>
#include <QDir>
#include <time.h>
#include <QFile>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include <QDesktopWidget>

#include "Pages/thomepage.h"
#include "Data/tuser.h"

void init(){
    srand(time(NULL)); //Random number generation

    //Set translator
    QString locale = QLocale::system().name().section('_',0,0);
    QTranslator translator;
    translator.load(QString("qt_") + locale,QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    QApplication::installTranslator(&translator);
}


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    init();   //Register the type to be able to create QVariant from them

    THomePage hp;


    //Set style
    QFile file(":/style.qss");
	file.open(QIODevice::ReadOnly | QIODevice::Text);
	hp.setStyleSheet(QLatin1String(file.readAll()));
	file.close();

    hp.show();

    return a.exec();
}

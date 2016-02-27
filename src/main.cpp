

#include <QApplication>
#include <QDebug>
#include <QDir>
#include <time.h>
#include <QFile>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>

#include "QTypingTest/thomepage.h"

void registerTypes(){
    qRegisterMetaTypeStreamOperators<TUser>         ("TUser"         );
    qRegisterMetaTypeStreamOperators<TResult>       ("TResult"       );
    qRegisterMetaTypeStreamOperators<TExercice>     ("TExercice"     );
    qRegisterMetaTypeStreamOperators<TProgression>  ("TProgression"  );
    qRegisterMetaTypeStreamOperators<date_exercice_>("date_exercice_");
}


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    srand(time(NULL)); //Random number generation
    registerTypes();   //Register the type to be able to create QVariant from them

    THomePage hp;


    //Set style
    QFile file(":/style.qss");
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

    //Set translator
    QString locale = QLocale::system().name().section('_',0,0);
    QTranslator translator;
    translator.load(QString("qt_") + locale,QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    a.installTranslator(&translator);

    hp.show();

    return a.exec();
}



#include <QApplication>
#include <QDebug>
#include <QDir>
#include <time.h>
#include <QFile>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>

#include "QTypingTest/thomepage.h"

const QStringList availableLanguages = {
    QLocale(QLocale::French,QLocale::France).nativeLanguageName(),
    QLocale(QLocale::English).nativeLanguageName(),
    QLocale(QLocale::Swedish,QLocale::Sweden).nativeLanguageName()
};

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    qDebug() << "Running from " << QDir::currentPath();

    srand(time(NULL)); //Random number generation

    THomePage hp;

    //Set style
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

    //Set translator
    QString locale = QLocale::system().name().section('_',0,0);
    QTranslator translator;
    translator.load(QString("qt_") + locale,QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    a.installTranslator(&translator);

    hp.show();

    return a.exec();
}

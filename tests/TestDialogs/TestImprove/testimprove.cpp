/* 
 * File:   TestTUser.cpp
 * Author: boutina
 * 
 * Created on 18 décembre 2015, 20:00
 */


#include <QtTest/QtTest>
#include <QApplication>
#include <time.h>
#include <QHash>
#include <qt5/QtCore/qchar.h>
#include <stdlib.h>

#include "QTypingTest/Dialogs/Exercices/timprove.h"

class TestImprove : public QObject {

    Q_OBJECT
private slots:
    void initTestCase() {
        srand(time(NULL));
    }
    void testOpen();
private:
    void generateRandomChars(TStats &chars);
};

void TestImprove::testOpen() {
    TUser *timmy = new TUser("Timmy");
    TStats stats = timmy->getStatistics();
    generateRandomChars(stats);
    timmy->setStatistics(stats);
    TUserManager::getInstance().setCurrentUser(timmy);
    
    TImprove improve;
    improve.show();
    connect(&improve, &TImprove::endOfExercice, this, [&improve, this](TResult *res, QTime time) {
        qDebug() << "End of the exerice";
        qDebug() << res->getResume();
                improve.close();
    });
    QApplication::exec();
}

void TestImprove::generateRandomChars(TStats &chars) {
    int numbersOfRandomChars = rand() % 26;
    for(int i = 0; i < numbersOfRandomChars;i++){
        QChar theRand((rand()%57) + 65);
        chars[theRand] += (rand()%10) + 1;
    }
}


QTEST_MAIN(TestImprove)
#include "testimprove.moc"

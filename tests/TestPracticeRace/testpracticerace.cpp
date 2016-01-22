/* 
 * File:   TestTUser.cpp
 * Author: boutina
 * 
 * Created on 18 décembre 2015, 20:00
 */


#include "QTypingTest/Dialogs/Exercices/tpracticerace.h"


#include <QtTest/QtTest>
#include <QApplication>
#include <time.h>

class TestPracticeRace : public QObject {
    Q_OBJECT
private slots:
    void testWithoutExercice();
};

void TestPracticeRace::testWithoutExercice() {
    //Test if the dialogs shows up with text
    srand(time(NULL)); //Random number generation

    TPracticeRace race;
    race.show();
    QApplication::exec();
}



QTEST_MAIN(TestPracticeRace)
#include "testpracticerace.moc"

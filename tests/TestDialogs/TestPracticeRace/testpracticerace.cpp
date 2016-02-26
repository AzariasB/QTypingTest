/*
 * QTypingTest by Pierre and Azarias - //website//
 * License : GNU - GPL 2
 */

/* 
 * File:   TestTUser.cpp
 * Author: boutina
 * 
 * Created on 18 décembre 2015, 20:00
 */


#include "QTypingTest/Dialogs/Exercices/tpracticerace.h"
#include "Data/tresult.h"

#include <QtTest/QtTest>
#include <QApplication>
#include <QTime>
#include <QMessageBox>
#include <time.h>

class TestPracticeRace : public QObject {
    Q_OBJECT
private slots:
    void initTestCase(){
        srand(time(NULL));//Random number generation
    }
    
    void testWithoutExercice();
};

void TestPracticeRace::testWithoutExercice() {
    //Test if the dialogs shows up with text

    TPracticeRace race(10);
    connect(&race,&TPracticeRace::endOfExercice,this,[&race,this](TResult* res,QTime time){
        QMessageBox::information(&race,"Exercice finished",res->getResume());
        race.close();
    });
    race.show();
    QApplication::exec();
}



QTEST_MAIN(TestPracticeRace)
#include "testpracticerace.moc"

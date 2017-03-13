/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */

/* 
 * File:   TestTUser.cpp
 * Author: boutina
 * 
 * Created on 18 décembre 2015, 20:00
 */


#include <QtTest/QtTest>
#include <QApplication>
#include <QTime>
#include <QMessageBox>
#include <time.h>

#include "Dialogs/tpracticerace.h"
#include "Data/tresult.h"

class TestPracticeRace : public QObject {
    Q_OBJECT
private slots:
    void initTestCase(){
        srand(time(NULL));//Random number generation
    }
    
    void testWithoutExercise();
};

void TestPracticeRace::testWithoutExercise() {
    //Test if the dialogs shows up with text

    TPracticeRace race(10);
	connect(&race,&TPracticeRace::endOfExercise,this,[&race,this](TResult &res,QTime){
		QMessageBox::information(&race,"Exercise finished",res.getResume());
        race.close();
    });
    race.show();
    QApplication::exec();
}



QTEST_MAIN(TestPracticeRace)
#include "testpracticerace.moc"

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

#include "Dialogs/tpracticebase.h"
#include "Data/tresult.h"


class TestPracticeBase : public QObject {
    Q_OBJECT
private slots:
    void initTestCase(){
        srand(time(NULL));//Random number generation
    }
    
    void testWithoutExercise();
};

void TestPracticeBase::testWithoutExercise() {
    //Test if the dialogs shows up with text

    TPracticeBase pract;
	connect(&pract,&TPracticeBase::endOfExercise,this,[&pract,this](TResult res,QTime){
		QMessageBox::information(&pract,"Exercise finished",res.getResume());
        pract.close();
    });
    pract.show();
    QApplication::exec();
}



QTEST_MAIN(TestPracticeBase)
#include "testpracticebase.moc"

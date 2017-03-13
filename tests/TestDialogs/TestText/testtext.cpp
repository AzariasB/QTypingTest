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

#include "Dialogs/tpracticetext.h"
#include "Data/tresult.h"

class TestText : public QObject {
    Q_OBJECT
private slots:
    void initTestCase(){
        srand(time(NULL));//Random number generation
    }
    
    void testWithoutExercise();
};

void TestText::testWithoutExercise() {
    //Test if the dialogs shows up with text
    TPracticeText text;
	connect(&text,&TPracticeText::endOfExercise,this,[&text,this](TResult res,QTime){
		QMessageBox::information(&text,"Exercise finished",res.getResume());
        text.close();
    });
    text.show();
    QApplication::exec();
}



QTEST_MAIN(TestText)
#include "testtext.moc"

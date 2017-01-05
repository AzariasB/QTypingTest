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


#include "QTypingTest/Dialogs/Exercices/tpracticetext.h"
#include "Data/tresult.h"

#include <QtTest/QtTest>
#include <QApplication>
#include <QTime>
#include <QMessageBox>
#include <time.h>

class TestText : public QObject {
    Q_OBJECT
private slots:
    void initTestCase(){
        srand(time(NULL));//Random number generation
    }
    
    void testWithoutExercice();
};

void TestText::testWithoutExercice() {
    //Test if the dialogs shows up with text

    TPracticeText text;
    connect(&text,&TPracticeText::endOfExercice,this,[&text,this](TResult* res,QTime time){
        QMessageBox::information(&text,"Exercice finished",res->getResume());
        text.close();
    });
    text.show();
    QApplication::exec();
}



QTEST_MAIN(TestText)
#include "testtext.moc"

/* 
 * File:   TestTUser.cpp
 * Author: boutina
 * 
 * Created on 18 décembre 2015, 20:00
 */


#include "QTypingTest/Dialogs/Exercices/twindowlearn.h"


#include <QtTest/QtTest>

class TestLearnDialog : public QObject {
    Q_OBJECT
private slots:
    void testOpen();
    void testExit();
};

void TestLearnDialog::testOpen(){
    TWindowLearn learn("");
    learn.show();
}

void TestLearnDialog::testExit() {
    TWindowLearn learn("Copie moi");
    learn.show();
    //Do exercice;
}


QTEST_MAIN(TestLearnDialog)
#include "testlearndialog.moc"

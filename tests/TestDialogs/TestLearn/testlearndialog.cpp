/* 
 * File:   TestTUser.cpp
 * Author: boutina
 * 
 * Created on 18 décembre 2015, 20:00
 */


#include "QTypingTest/Dialogs/Exercices/twindowlearn.h"


#include <QtTest/QtTest>
#include <QApplication>
#include <time.h>

class TestLearnDialog : public QObject {
    Q_OBJECT
private slots:
    void initTestCase(){
        srand(time(NULL));
    }
    void testOpen();
};

void TestLearnDialog::testOpen() {
    //Test if the dialogs shows up with text
    QWidget *w = new QWidget();
    TWindowLearn learn("Now you have to type this little text which is a test",1,w);
    learn.show();
    connect(&learn,&TWindowLearn::endOfExercice,this, [&learn,this](TResult *res, QTime time){
        qDebug() << "End of the exerice";
        qDebug() << res->getResume();
        learn.close();
    });
    QApplication::exec();
}



QTEST_MAIN(TestLearnDialog)
#include "testlearndialog.moc"

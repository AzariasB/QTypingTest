/* 
 * File:   TestTUser.cpp
 * Author: boutina
 * 
 * Created on 18 décembre 2015, 20:00
 */




#include <QtTest/QtTest>
#include <QApplication>
#include <time.h>

#include "QTypingTest/Dialogs/Exercices/twindowlearn.h"
#include "Data/texercice.h"
#include "Data/tlayouts.h"


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
    TLayouts lay = TLayouts::getInstance("fr");
    TExercice *ex = new TExercice(TExercice::LEARNING,lay.getLettersAt(10),lay.getAllLettersTo(10));
    TWindowLearn learn(ex,w);
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

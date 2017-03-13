/* 
 * File:   TestTUser.cpp
 * Author: boutina
 * 
 * Created on 18 décembre 2015, 20:00
 */

#include <QtTest/QtTest>
#include <QApplication>
#include <time.h>

#include "Dialogs/twindowlearn.h"
#include "Data/tlayout.h"


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
    TLayout frLayout = TLayout::getInstance();
	TExercise ex = TExercise::generateExercise(TExercise::LEARNING,"fj", "fj");
    
    TWindowLearn learn(ex,w);
    learn.show();
	connect(&learn,&TWindowLearn::endOfExercise,this, [&learn,this](TResult res, QTime time){
        qDebug() << "End of the exercise";
		qDebug() << res.getResume();
        learn.close();
    });
    QApplication::exec();
}



QTEST_MAIN(TestLearnDialog)
#include "testlearndialog.moc"

/* 
 * File:   TestTUser.cpp
 * Author: boutina
 * 
 * Created on 18 décembre 2015, 20:00
 */


#include "QTypingTest/Dialogs/Exercices/twindowlearn.h"


#include <QtTest/QtTest>
#include <QApplication>

class TestLearnDialog : public QObject {
    Q_OBJECT
private slots:
    void testOpen();
};

void TestLearnDialog::testOpen() {
    //Test if the dialogs shows up with text
    QWidget *w = new QWidget();
    TWindowLearn learn("Now you have to type this little text which is a test",1,w);
    learn.show();
    QApplication::exec();
}



QTEST_MAIN(TestLearnDialog)
#include "testlearndialog.moc"

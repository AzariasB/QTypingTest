/* 
 * File:   testvirtualkeyboard.cpp
 * Author: boutina
 * 
 * Created on 27 january
 */

#include <QtTest/QtTest>
#include <QDebug>
#include <QApplication>

#include "Pages/homepage.h"

class TestHomePage : public QObject {
    Q_OBJECT
private slots:
    void testHomePage();
};


void TestHomePage::testHomePage() {
    HomePage home;
    home.show();
    QApplication::exec();
}


QTEST_MAIN(TestHomePage)
#include "testhomepage.moc"

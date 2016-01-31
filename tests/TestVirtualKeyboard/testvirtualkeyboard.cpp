/* 
 * File:   testvirtualkeyboard.cpp
 * Author: boutina
 * 
 * Created on 27 january
 */

#include <QtTest/QtTest>
#include <QDebug>
#include <QApplication>
#include <QHBoxLayout>
#include <QString>

#include "QTypingTest/Learn/tfingerposition.h"

class TestVirtualKeyboard : public QObject {
    Q_OBJECT
private slots:
    void testKeyboard();
};


void TestVirtualKeyboard::testKeyboard() {
//    TVirtualKeyboard *kb = new TVirtualKeyboard("fr");
//    kb->show();
    TFingerPosition *fingers = new TFingerPosition();
    fingers->show();
    QApplication::exec();
}


QTEST_MAIN(TestVirtualKeyboard)
#include "testvirtualkeyboard.moc"

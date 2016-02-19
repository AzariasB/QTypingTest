/* 
 * File:   testvirtualkeyboard.cpp
 * Author: boutina
 * 
 * Created on 27 january
 */

#include <QtTest/QtTest>
#include <QDebug>
#include <QApplication>

#include "QTypingTest/Learn/tpresentation.h"

class TestVirtualKeyboard : public QObject {
    Q_OBJECT
private slots:
    void testKeyboard();
};


void TestVirtualKeyboard::testKeyboard() {
    TPresentation *pres = new TPresentation("fr");
    pres->show();
    QApplication::exec();
}


QTEST_MAIN(TestVirtualKeyboard)
#include "testvirtualkeyboard.moc"

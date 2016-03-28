/* 
 * File:   testvirtualkeyboard.cpp
 * Author: boutina
 * 
 * Created on 27 january
 */

#include <QtTest/QtTest>
#include <QDebug>
#include <QApplication>
#include <QLocale>
#include <QInputMethod>

#include "QTypingTest/Learn/tpresentation.h"

class TestVirtualKeyboard : public QObject {
    Q_OBJECT
private slots:
    void testKeyboard();
};


void TestVirtualKeyboard::testKeyboard()
{
    TLayouts layTest = TLayouts::getInstance("azerty");
    TPresentation *pres = new TPresentation(layTest);
    QInputMethod *meth =  QApplication::inputMethod();
    pres->show();
    QApplication::exec();
}


QTEST_MAIN(TestVirtualKeyboard)
#include "testvirtualkeyboard.moc"

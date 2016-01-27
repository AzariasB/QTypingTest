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

#include "QTypingTest/Learn/tvirtualkey.h"
#include "QTypingTest/Learn/tvirtualkeyboard.h"

class TestVirtualKeyboard : public QObject {
    Q_OBJECT
private slots:
    void testKey();
//    void testFactory();
};

void TestVirtualKeyboard::testKey(){
    QWidget *main = new QWidget();
    QHBoxLayout *lay = new QHBoxLayout();
    TVirtualKey *key = new TVirtualKey('a');
    TVirtualKey *shi = new TVirtualKey('a','A');
    QString e = "é";//For utf8 chars, cannot directly use special chars
    TVirtualKey *alt = new TVirtualKey(e.at(0),'2','~');
    
    lay->addWidget(key);
    lay->addWidget(shi);
    lay->addWidget(alt);
    
    main->setLayout(lay);
    main->show();
    QApplication::exec();
}

QTEST_MAIN(TestVirtualKeyboard)
#include "testvirtualkeyboard.moc"

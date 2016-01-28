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
//    void testKey();
    void testKeyboard();
};

//void TestVirtualKeyboard::testKey(){
//    QWidget *main = new QWidget();
//    QHBoxLayout *lay = new QHBoxLayout();
//    TVirtualKey *key = new TVirtualKey('a');
//    key->wrong();
//    TVirtualKey *shi = new TVirtualKey('a','A');
//    shi->right();
//    QString e = "é";//For utf8 chars, cannot directly use special chars
//    TVirtualKey *alt = new TVirtualKey(e.at(0),'2','~');
//    TVirtualKey *pon = new TVirtualKey(',','?');
//    
//    lay->addWidget(key);
//    lay->addWidget(shi);
//    lay->addWidget(alt);
//    lay->addWidget(pon);
//    
//    main->setLayout(lay);
//    main->show();
//    QApplication::exec();
//}

void TestVirtualKeyboard::testKeyboard() {
//    QWidget *main = new QWidget();
    TVirtualKeyboard *kb = new TVirtualKeyboard("fr");
//    main->setFixedSize(900,390);
//    main->adjustSize();
    kb->show();
    QApplication::exec();
}


QTEST_MAIN(TestVirtualKeyboard)
#include "testvirtualkeyboard.moc"

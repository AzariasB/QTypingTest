/* 
 * File:   TestTUser.cpp
 * Author: boutina
 * 
 * Created on 18 décembre 2015, 20:00
 */

#include <QtTest/QtTest>
#include <QFile>
#include "../../src/Data/tuser.h"

#include <QtTest/QtTest>

class TestTUser : public QObject {
    Q_OBJECT
private slots:
    void testConstructor();
    void testFileWriting();
    void testFileReading();

};


void TestTUser::testConstructor() {
    QString str = "Hello";
    TUser *t = new TUser(str);
    QCOMPARE(t->getPseudo(),str);
}

void TestTUser::testFileWriting() {
    QFile f("user.dat");
    QDataStream stream(&f);
    f.open(QIODevice::WriteOnly);

    TUser t("Quentin");

    stream << t;

    f.close();
}


void TestTUser::testFileReading() {
    QFile f("user.dat");
    QDataStream stream(&f);
    f.open(QIODevice::ReadOnly);

    TUser r("André");
    stream >> r;
    
    f.close();
}


QTEST_MAIN(TestTUser)
#include "testqstring.moc"

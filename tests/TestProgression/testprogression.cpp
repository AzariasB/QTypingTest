/* 
 * File:   TestTUser.cpp
 * Author: boutina
 * 
 * Created on 18 décembre 2015, 20:00
 */


#include <QFile>
#include <QDataStream>

#include "../../src/Data/tprogression.h"


#include <QtTest/QtTest>

class TestProgression : public QObject {
    Q_OBJECT
private slots:
    void testDataStream();
};

void TestProgression::testDataStream(){
	//test serialization
}

QTEST_MAIN(TestProgression)
#include "testprogression.moc"

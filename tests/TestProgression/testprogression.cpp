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
    QFile f("prog.dat");
    QDataStream stream(&f);
    
    if(!f.open(QFile::WriteOnly)){
        qDebug() << "could not open file";
        exit(1);
    }
    
    TProgression prog;
    
    stream << prog;
    f.close();
    if(!f.open(QFile::ReadOnly)){
        qDebug() << "could not open file";
        exit(1);
    }
    
    TProgression other;
    stream >> other;
    QCOMPARE(prog,other);
}

QTEST_MAIN(TestProgression)
#include "testprogression.moc"

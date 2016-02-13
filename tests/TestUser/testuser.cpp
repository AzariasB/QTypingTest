/* 
 * File:   TestTUser.cpp
 * Author: boutina
 * 
 * Created on 18 décembre 2015, 20:00
 */

#include <QtTest/QtTest>
#include <QFile>
#include <QDebug>
#include <QVector>
#include <QDataStream>

#include "Data/tuser.h"
#include "Data/texercice.h"


class TestTUser : public QObject {
    Q_OBJECT
private slots:
    void testConstructor();
    void testDataStream();
    void testProgression();
    void testSignals();

private:
    QString randomName();
};

void TestTUser::testSignals() {
    bool signalEmited  = false;
    
    TUser timmy("timmy");
    
    connect(&timmy,&TUser::statsChanged,this,[this,&signalEmited](){
        signalEmited = true;
    });
    
    timmy.oneMoreMistake('o');
    
    QVERIFY(signalEmited);
}


QString TestTUser::randomName() {
    int nameLength = rand() % 10 + 1;
    QString s;
    for(int l = 0; l < nameLength; l++){
        s += '0' + l;
    }
    return s;
}


void TestTUser::testConstructor() {
    //Constructor with arguments
    QString str = "Hello";
    TUser *t = new TUser(str);
    QCOMPARE(t->getPseudo(), str);

    //Constructor without arguments
    TUser r;
    QCOMPARE(r.getPseudo(), QString(""));
}

void TestTUser::testDataStream() {
    qDebug() << "Writing a single user in file";

    QFile f("user.dat");
    QDataStream stream(&f);
    f.open(QIODevice::WriteOnly);

    TUser t("Quentin");

    stream << t;

    f.close();
    f.open(QIODevice::ReadOnly);

    TUser r;
    stream >> r;
    f.close();
    //Get back the same user
    QVERIFY(r.getPseudo() == t.getPseudo());

    qDebug() << "Write multiples users in file";
    
    QVector<TUser> v1;
    int numberOfUsers = 30;
    QFile f2("users.dat");
    QDataStream stream2(&f2);
    
    f2.open(QIODevice::WriteOnly);
    for (int i = 0; i < numberOfUsers; i++) {
        TUser u(randomName());
        v1.append(u);
        stream2 << u;
    }
    
    f2.close();
    f2.open(QIODevice::ReadOnly);
    QVector<TUser> v2;
    
    for(int i = 0; i < v1.size();i++){
        TUser u;
        stream2 >> u;
        v2.append(u);
    }
    f2.close();
    QVERIFY(v1 == v2);
}

void TestTUser::testProgression() {
    TExercice *ex = new TExercice(TExercice::LEARNING, "d", "d");
    TResult *res = new TResult();

    TUser t("Dupont");

    t.addResult(ex, res);
    QVERIFY(t.getPracticeHistory().size() >= 1);
}


QTEST_MAIN(TestTUser);
#include ".moc/testuser.moc"

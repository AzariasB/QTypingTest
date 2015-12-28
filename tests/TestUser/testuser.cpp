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
#include "../../src/Data/texercice.h"
#include "../../src/Data/tresult.h"
#include "../../src/Data/tuser.h"


#include <QtTest/QtTest>

class TestTUser : public QObject {
    Q_OBJECT
private slots:
    void testConstructor();
    void testDataStream();
    void testProgression();

private:
    QString randomName();
};

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
    QVector<TUser> v1(30);
    QFile f2("users.dat");
    
    
    f2.open(QIODevice::ReadOnly);
    for (int i = 0; i < v1.size(); i++) {
        TUser u(randomName());
        v1.append(u);
        stream << u;
    }
    f2.close();
    f2.open(QIODevice::WriteOnly);
    QVector<TUser> v2(v1.size());
    
    for(int i = 0; i < v2.size();i++){
        TUser u;
        stream >> u;
        v2.append(u);
    }
    f2.close();
    QVERIFY(v1 == v2);
}

void TestTUser::testProgression() {
    TExercice *ex = new TExercice(TExercice::LEARNING, QStringList("d"), QStringList("d"));
    TResult *res = new TResult();

    TUser t("Dupont");

    t.addResult(ex, res);
    QVERIFY(t.getPracticeHistory().size() >= 1);
}


QTEST_MAIN(TestTUser)
#include "testuser.moc"

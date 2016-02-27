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
#include <time.h>

#include "Data/tuser.h"
#include "Data/texercice.h"
#include "Data/tusermanager.h"


class TestTUser : public QObject {
    Q_OBJECT
private slots:
    void initTestCase(){
        qRegisterMetaTypeStreamOperators<TUser>("TUser");
        qRegisterMetaTypeStreamOperators<TStats>("TStats");
        qRegisterMetaTypeStreamOperators<TResult>("TResult");
        qRegisterMetaTypeStreamOperators<TExercice>("TExercice");
        qRegisterMetaTypeStreamOperators<TProgression>("TProgression");
        qRegisterMetaTypeStreamOperators<date_exercice_>("date_exercice_");
        srand(time(NULL));
    }

    void testSettings();
    void testMetaTypes();
    void testConstructor();
    void testProgression();
    void testSignals();
    void testUserManager();

private:
    QString randomName();
};

void TestTUser::testSettings()
{
    TUserManager::getInstance().removeAllUsers();
    QVERIFY(TUserManager::getInstance().users().size() == 0);
    for(int i = 0; i < 10;i++)
        TUserManager::getInstance() << new TUser(randomName());
    TUserManager::getInstance().saveUsers();
    qDebug() << TUserManager::getInstance().readUsers().size();
    QVERIFY(TUserManager::getInstance().readUsers().size() == 10);
}

void TestTUser::testMetaTypes()
{
    TProgression p;
    p.setLastExerciceIndex(200);
    QVariant v = QVariant::fromValue(p);
    QVERIFY(v.canConvert<TProgression>());
    {
        QSettings write("test");
        write.beginGroup("test");
        write.clear();
        write.setValue("progression",v);
        write.endGroup();
    }

    {
        QSettings read("test");
        read.beginGroup("test");
        QVariant rec =  read.value("progression");
        qDebug() << rec.value<TProgression>().getLastExericeIndex();
        read.endGroup();
        QVERIFY(rec.type() == QVariant::UserType);
        QVERIFY(rec.isValid());
    }


    date_exercice_ ex;
    v = QVariant::fromValue(ex);
    QVERIFY(v.canConvert<date_exercice_>());

    TExercice exo;
    v = QVariant::fromValue(exo);
    QVERIFY(v.canConvert<TExercice>());

    TStats stats;
    v = QVariant::fromValue(stats);
    QVERIFY(v.canConvert<TStats>());

    TResult res;
    v = QVariant::fromValue(res);
    QVERIFY(v.canConvert<TResult>());

    TUser u;
    v = QVariant::fromValue(u);
    QVERIFY(v.canConvert<TUser>());
}

void TestTUser::testUserManager()
{
    int numberOfChanges = 0;
    TUser *other = new TUser(randomName());
    connect(&TUserManager::getInstance(),&TUserManager::userChanged,this,[=,&numberOfChanges](){
        numberOfChanges++;
    });

    TUserManager::getInstance().removeAllUsers();

    for(int i = 0; i < 10;i++){
        TUser *u = new TUser(randomName());
        TUserManager::getInstance() << u;
    }


    //Operator testing
    QVERIFY(TUserManager::getInstance().users().size() == 10);
    TUserManager::getInstance() << other;
    QVERIFY(TUserManager::getInstance().users().size() == 11);
    TUserManager::getInstance() - other;
    QVERIFY(TUserManager::getInstance().users().size() == 10);
    QVERIFY(!TUserManager::getInstance().users().contains(other));

    //Signal testing
    for(int i = 0; i < 10;i++)
        TUserManager::getInstance().setCurrentUser(other);

    QVERIFY(numberOfChanges == 10);
}

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
    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
    const int randomStringLength = qrand()%20  + 4;
    QString randomString;
    for(int i=0; i<randomStringLength; ++i)
    {
        int index = qrand() % possibleCharacters.length();
        QChar nextChar = possibleCharacters.at(index);
        randomString.append(nextChar);
    }
    return randomString;
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

void TestTUser::testProgression() {
    TExercice *ex = new TExercice(TExercice::LEARNING, "d", "d");
    TResult *res = new TResult();

    TUser t("Dupont");

    t.addResult(ex, res);
    QVERIFY(t.getPracticeHistory().size() >= 1);
}


QTEST_MAIN(TestTUser)
#include ".moc/testuser.moc"

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
        beforeTesting = TUserManager::getInstance().readUsers();
        TUserManager::getInstance().removeAllUsers();
        srand(time(NULL));
    }

    void cleanup(){
        TUserManager::getInstance().removeAllUsers();
        for(TUser *u: beforeTesting){
            TUserManager::getInstance() << u;
        }
    }

    void testSettings();
    void testMetaTypes();
    void testConstructor();
    void testProgression();
    void testUserManager();

private:
    QString randomName();

    QList<TUser*> beforeTesting;
};

void TestTUser::testSettings()
{
    TUserManager::getInstance().removeAllUsers();
    QCOMPARE(TUserManager::getInstance().users().size(),0);
    QList<QString> pseudos;
    for(int i = 0; i < 10;i++){
        QString name = randomName();
        pseudos << name;
        qDebug() << "Assigning : " << name;
        TUserManager::getInstance() << new TUser(name);
    }

	TUserManager::getInstance().saveUsers();
    QList<TUser*> users = TUserManager::getInstance().readUsers();

    QCOMPARE(users.size(),10);
    foreach(TUser *u , users){
        QVERIFY(pseudos.contains(u->getPseudo()));
        bool removed = TUserManager::getInstance() - u;
        qDebug() << "Found :" << u->getPseudo() << " " << removed;
    }
}

void TestTUser::testMetaTypes()
{
    TUser t("pedro");
    QVariant v = QVariant::fromValue(t);
    QVERIFY(v.isValid());
    TUser tV = v.value<TUser>();
    QCOMPARE(tV,t);
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
    QCOMPARE(TUserManager::getInstance().users().size(),10);
    TUserManager::getInstance() << other;
    QCOMPARE(TUserManager::getInstance().users().size(),11);

    //Signal testing
    for(int i = 0; i < 10;i++)
        TUserManager::getInstance().setCurrentUser(other);

	qDebug() << numberOfChanges;
	QVERIFY(numberOfChanges == 10);

    TUserManager::getInstance() - other;
    QCOMPARE(TUserManager::getInstance().users().size(),10);
    QVERIFY(!TUserManager::getInstance().users().contains(other));
}


QString TestTUser::randomName() {
    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
    const int randomStringLength = qrand()%20  + 4;
    QString randomString;
    for(int i=0; i<randomStringLength; ++i)
    {
        int index = rand() % possibleCharacters.length();
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
    TExercice *ex = TExercice::generateExercice(TExercice::LEARNING,"d","d");
    TResult *res = new TResult();

    TUser t("Dupont");

    t.addResult(ex, res);
    QVERIFY(t.getPracticeHistory()->size() >= 1);
}


QTEST_MAIN(TestTUser)
#include ".moc/testuser.moc"

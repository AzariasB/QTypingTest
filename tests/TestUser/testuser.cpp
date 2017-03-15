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
#include <time.h>

#include "Data/tuser.h"
#include "Data/texercise.h"
#include "Data/tusermanager.h"


class TestTUser : public QObject {
    Q_OBJECT
public:
	TestTUser():userManager("save.json"){
	}

private slots:
    void initTestCase(){
		srand(time(NULL));
    }

    void testSettings();
	void testSerializable();
    void testConstructor();
    void testProgression();
    void testUserManager();

private:
    QString randomName();

	TUserManager userManager;
};

void TestTUser::testSettings()
{
	userManager.removeAllUsers();
	userManager.saveUsers();
	QCOMPARE(userManager.users().size(),0);
    QList<QString> pseudos;
    for(int i = 0; i < 10;i++){
        QString name = randomName();
        pseudos << name;
        qDebug() << "Assigning : " << name;
		TUser randUser(name);
		userManager << randUser;
    }

	//userManager.saveUsers(saveTarget);
	QList<TUser> &users = userManager.readUsers();
    QCOMPARE(users.size(),10);
	for(const TUser &u : users){
		QVERIFY(pseudos.contains(u.getPseudo()));
		bool removed = userManager.removeUser(u);
		qDebug() << "Found :" << u.getPseudo() << " " << removed;
	}
}

void TestTUser::testSerializable()
{
    TUser t("pedro");

	userManager.addUser(t);
	userManager.saveUsers();

	userManager.removeAllUsers();


	userManager.readUsers();
	QVERIFY(userManager.users().size() >= 1);
}

void TestTUser::testUserManager()
{
    int numberOfChanges = 0;
	TUser other(randomName());
	connect(&userManager,&TUserManager::userChanged,this,[=,&numberOfChanges](){
        numberOfChanges++;
    });

	userManager.removeAllUsers();

    for(int i = 0; i < 10;i++){
		TUser u(randomName());
		userManager << u;
    }


    //Operator testing
	QCOMPARE(userManager.users().size(),10);
	userManager << other;
	QCOMPARE(userManager.users().size(),11);

    //Signal testing
    for(int i = 0; i < 10;i++)
		QVERIFY(userManager.setCurrentUser(other));

	qDebug() << numberOfChanges;
	QVERIFY(numberOfChanges == 10);

	userManager.removeUser(other);
	QCOMPARE(userManager.users().size(),10);
	QVERIFY(!userManager.users().contains(other));
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
	TExercise ex = TExercise::generateExercise(TExercise::LEARNING,"d","d");
	TResult res;
	ex.completed(res);

    TUser t("Dupont");

	t.addResult(ex);
	QVERIFY(t.getPracticeHistory().size() >= 1);
}


QTEST_MAIN(TestTUser)
#include ".moc/testuser.moc"

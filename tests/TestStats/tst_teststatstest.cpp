#include <QString>
#include <QtTest>
#include <QCoreApplication>
#include <QEvent>
#include <QHash>

#include "time.h"
#include "Data/tuser.h"
#include "Data/texercice.h"
#include "Pages/tstatistics.h"
#include "Data/tusermanager.h"

class TestStatsTest : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase(){
        srand(time(NULL));
    }

    void testCase1();


private:
    void genHistory(TUser *user);
    TResult * genRandTResult();
    TExercice *genRandExercice();
    QDateTime genRandDate();
};


void TestStatsTest::testCase1()
{

    TUser *user = new TUser("Brian");
    genHistory(user);
    TUserManager::getInstance() << user;
    TUserManager::getInstance().setCurrentUser(user);
    TStatistics stats;

    stats.show();
    QApplication::exec();
}

void TestStatsTest::genHistory(TUser *user)
{
    int numberOfResults = 50;
    for(int i = 0; i < numberOfResults; i++){
        TResult *res = genRandTResult();
        TExercice *exo = genRandExercice();
        QDateTime time = genRandDate();
        user->addResult(exo, res, time);
    }
}

TResult *TestStatsTest::genRandTResult()
{
    TResult *res = new TResult();
    int randWpM = rand() % 80 + 10;
    res->setWPM(randWpM);
    res->setCorrectKeysStrokes(rand() % 200 + 100);
    res->setWrongKeysStrokes(rand() % 40 + 1);
    return res;
}

TExercice *TestStatsTest::genRandExercice()
{
    //Add randomness later
    TExercice *exo = TExercice::generateExercice(TExercice::PRACTICING);
    return exo;
}

QDateTime TestStatsTest::genRandDate()
{
    QDateTime time = QDateTime::currentDateTime();
    return time.addDays(rand() % 100);
}

QTEST_MAIN(TestStatsTest)

#include "tst_teststatstest.moc"

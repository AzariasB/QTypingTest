#include <QString>
#include <QtTest>
#include <QCoreApplication>
#include <QEvent>
#include <QHash>

#include <qlineedit.h>

#include "time.h"
#include "Data/tuser.h"
#include "Data/texercise.h"
#include "Pages/tstatistics.h"
#include "Data/tusermanager.h"
#include "tapplication.h"

class TestStatsTest : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase(){
        srand(time(NULL));
    }

    void testCase1();


private:
	void genHistory(TUser &user);
	TResult genRandTResult();
	TExercise genRandExercise();
};


void TestStatsTest::testCase1()
{
	TUser user("Brian");
	genHistory(user);
	tApp.getUserManager() << user;
	tApp.getUserManager().setCurrentUser(user);
	TStatistics stats;

	stats.show();
	QApplication::exec();
}

void TestStatsTest::genHistory(TUser &user)
{
    int numberOfResults = 50;
    for(int i = 0; i < numberOfResults; i++){
		TResult res = genRandTResult();
		TExercise exo = genRandExercise();
		exo.completed(res);
		user.addResult(exo);
    }
}

TResult TestStatsTest::genRandTResult()
{
	TResult res;
    int randWpM = rand() % 80 + 10;
	res.setWPM(randWpM);
	res.setCorrectKeysStrokes(rand() % 200 + 100);
	res.setWrongKeysStrokes(rand() % 40 + 1);
    return res;
}

TExercise TestStatsTest::genRandExercise()
{
    //Add randomness later
	return TExercise::generateExercise(TExercise::PRACTICING);
}
QTEST_MAIN(TestStatsTest)

#include "tst_teststatstest.moc"

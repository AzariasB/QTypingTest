#include <cstdlib>
#include <ctime>

#include <QString>
#include <QtTest>
#include <QCoreApplication>

#include "Games/Competition/competitionmain.h"

class TestGame : public QObject
{
	Q_OBJECT

public:
	TestGame();

private slots:
	void initTestCase();
	void cleanupTestCase();
	void testCase1();
};

TestGame::TestGame()
{

}

void TestGame::initTestCase()
{
	qsrand(time(NULL));
}

void TestGame::cleanupTestCase()
{
}

void TestGame::testCase1()
{
	CompetitionMain *cm = new CompetitionMain;
	cm->show();
	QApplication::exec();
}

QTEST_MAIN(TestGame)

#include "testgame.moc"

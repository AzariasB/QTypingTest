#include <cstdlib>
#include <ctime>

#include <QString>
#include <QtTest>
#include <QCoreApplication>

#include "Games/bouncemain.h"

class TestGame : public QObject
{
	Q_OBJECT

public:
	TestGame();

private Q_SLOTS:
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
	BounceMain *main = new BounceMain();
	main->show();
	QApplication::exec();
}

QTEST_MAIN(TestGame)

#include "testgame.moc"

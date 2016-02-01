#include <QString>
#include <QtTest>
#include <QCoreApplication>
#include "Data/tuser.h"
#include "QTypingTest/Statistics/tstatswpm.h"

class TestStatsTest : public QObject
{
    Q_OBJECT

private slots:
    void testCase1();
};


void TestStatsTest::testCase1()
{
    TUser user;
    TStatsWPM w;
    w.show();
    QApplication::exec();
}

QTEST_MAIN(TestStatsTest)

#include "tst_teststatstest.moc"

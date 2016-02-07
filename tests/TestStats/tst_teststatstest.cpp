#include <QString>
#include <QtTest>
#include <QCoreApplication>
#include <QEvent>
#include <QHash>

#include "Data/tuser.h"
#include "Data/texercice.h"
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
    w.setFixedHeight(300);
    w.show();
    QApplication::exec();
}

QTEST_MAIN(TestStatsTest)

#include "tst_teststatstest.moc"

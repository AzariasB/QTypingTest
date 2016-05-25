#include <QString>
#include <QtTest>
#include <QCoreApplication>
#include <QEvent>
#include <QHash>

#include "time.h"
#include "Data/tuser.h"
#include "Data/texercice.h"
#include "QTypingTest/Statistics/tstatswpm.h"
#include "QTypingTest/Statistics/tlayoutwidget.h"
#include "QTypingTest/Statistics/tscrollwidget.h"

class TestStatsTest : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase(){
        srand(time(NULL));
    }

    void testCase1();
};


void TestStatsTest::testCase1()
{
    TUser user;
    TScrollWidget sw;

    sw.show();
    QApplication::exec();
}

QTEST_MAIN(TestStatsTest)

#include "tst_teststatstest.moc"

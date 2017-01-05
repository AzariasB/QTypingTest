#include <QString>
#include <QtTest>
#include "renderarea.h"

class TestUserTest : public QObject
{
    Q_OBJECT

public:
    TestUserTest();

private Q_SLOTS:
    void testCase1();

private:
    RenderArea *renderArea;
};



TestUserTest::TestUserTest()
{
}

void TestUserTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(TestUserTest)

#include "tst_testusertest.moc"

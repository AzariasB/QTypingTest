#include <QString>
#include <QtTest/qtest.h>
#include <QCoreApplication>

#include "QTypingTest/toptiondialog.h"
#include "Data/tuser.h"
#include "Data/tusermanager.h"

class TestUserSettingsTest : public QObject
{
    Q_OBJECT

public:
    TestUserSettingsTest();

private Q_SLOTS:
    void testCase1();
};

TestUserSettingsTest::TestUserSettingsTest()
{
}

void TestUserSettingsTest::testCase1()
{
    TUser *user = new TUser("timmy");
    TUserManager::getInstance().setCurrentUser(user);
    TOptionDialog opt(*user);
    opt.show();

    connect(&opt,&QDialog::finished,[=, &opt](int res){
        if(res == 1){
            user->setSettings(opt.getCurrentSettings());
        }
    });

    QApplication::exec();
}

QTEST_MAIN(TestUserSettingsTest);

#include "tst_testusersettingstest.moc"

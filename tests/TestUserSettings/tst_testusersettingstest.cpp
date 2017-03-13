#include <QString>
#include <QtTest/qtest.h>
#include <QCoreApplication>

#include "Dialogs/toptiondialog.h"
#include "Data/tuser.h"
#include "Data/tusermanager.h"
#include "tapplication.h"


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
	TUser user("timmy");
	tApp.getUserManager() << user;
	tApp.getUserManager().setCurrentUser(user);
	TOptionDialog opt(user);
    opt.show();

	connect(&opt,&QDialog::finished,[&](int res){
        if(res == 1){
			user.setSettings(opt.getCurrentSettings());
        }
    });

    QApplication::exec();
}

QTEST_MAIN(TestUserSettingsTest)

#include "tst_testusersettingstest.moc"

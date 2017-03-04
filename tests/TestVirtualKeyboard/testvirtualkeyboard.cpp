/* 
 * File:   testvirtualkeyboard.cpp
 * Author: boutina
 * 
 * Created on 27 january
 */

#include <QtTest/QtTest>
#include <QDebug>
#include <QApplication>
#include <QLocale>
#include <QInputMethod>

#include "Widgets/tpresentation.h"

class TestVirtualKeyboard : public QObject {
    Q_OBJECT
private slots:
    void testKeyboard();
};


void TestVirtualKeyboard::testKeyboard()
{
    TLayout layTest = TLayout::getInstance();
    layTest.getLearningCouples();
	TPresentation *pres = new TPresentation(layTest,"{AP}(ap)");
	connect(pres, &TPresentation::allCopied, [pres](){
		qDebug() << "all copied";
		pres->close();
	});

    pres->show();
    QApplication::exec();
}


QTEST_MAIN(TestVirtualKeyboard)
#include "testvirtualkeyboard.moc"

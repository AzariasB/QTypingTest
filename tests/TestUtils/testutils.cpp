/* 
 * File:   TestTUser.cpp
 * Author: boutina
 * 
 * Created on 18 décembre 2015, 20:00
 */

#include <QtTest/QtTest>
#include <QDebug>
#include <QStringList>
#include <QDir>
#include "../../src/Util/htmlhelper.h"
#include "../../src/Util/factory.h"
#include "../../src/Util/filehelper.h"

class TestUtils : public QObject {
    Q_OBJECT
private slots:
    void testHTML();
    void testFactory();
private:
    //Functions to test Factory
    void testWordsFinding();

    //Functions to test HTML
    void testSurroundAll();
    void testSurroundAt();
    void testRemoveTags();
    void testAbsolutePosition();
};

void TestUtils::testAbsolutePosition() {
    QString joel_0 = "joel";
    QString joel_1 = "<p>j</p>oel";
    QString joel_2 = "jo<p>e</p>l";
    QString joel_3 = "joe<p>l</p>";
    QString joel_4 = "<p>j</p>o<b>e</b><u>l</u>";
    QString joel_5 = "<b><u>j</b></u>oel";

    qDebug() << "Get the absolute position of a char in a String";
    QCOMPARE(html::getAbsoluteCharPosition(joel_0, 0), 0);
    QCOMPARE(html::getAbsoluteCharPosition(joel_1, 0), 3);
    QCOMPARE(html::getAbsoluteCharPosition(joel_2, 2), 5);
    QCOMPARE(html::getAbsoluteCharPosition(joel_3, 3), 6);
    QCOMPARE(html::getAbsoluteCharPosition(joel_4, 3), 20);
    QCOMPARE(html::getAbsoluteCharPosition(joel_5, 1), 15);
}

void TestUtils::testWordsFinding() {
    QString letters = "fod";
    QStringList found = factory::findExistingWords(letters, file::getWordsPath("en"));
    qDebug() << found;
    QVERIFY(found.contains("food"));
    QVERIFY(found.contains("off"));

    letters = "be";
    found = factory::findExistingWords(letters, file::getWordsPath("en"));
    qDebug() << found;
    QVERIFY(found.contains("be"));

    letters = "betwn";
    found = factory::findExistingWords(letters, file::getWordsPath("en"));
    qDebug() << found;
    QVERIFY(found.contains("be"));
    QVERIFY(found.contains("between"));
    QVERIFY(found.contains("ten"));
    QVERIFY(found.contains("new"));
    QVERIFY(found.contains("been"));
    QVERIFY(found.contains("went"));
    QVERIFY(found.contains("we"));
}

void TestUtils::testHTML() {
    qDebug() << "Testing HTML";
    testSurroundAll();
    testSurroundAt();
    testRemoveTags();
    testAbsolutePosition();
}

void TestUtils::testFactory() {
    qDebug() << "Testing factory (non-random functions)";
    //Not any "non random-functions' at the moment
    testWordsFinding();
}

void TestUtils::testSurroundAll() {
    QString patrick = "patrick";
    QString suroundedPatrick = "<p>p</p>"
            "<p>a</p>"
            "<p>t</p>"
            "<p>r</p>"
            "<p>i</p>"
            "<p>c</p>"
            "<p>k</p>";
    QCOMPARE(html::addTagToChars(patrick, "p"), suroundedPatrick);
}

void TestUtils::testSurroundAt() {
    QString sPatrick_1 = "<p>p</p>"; //Simple one

    qDebug() << "Adding a single tag";
    QString pString = "p";
    QCOMPARE(html::addTags(pString, "p"), sPatrick_1);

    
    QString sPatrick_2 = "<b><u>a</u></b>";
    QString sPatrick_3 = "<t><p>b</p></t>";
    

    qDebug() << "Adding multiples tags";
    QString aString = "a";
    QString bString = "b";
    QCOMPARE(html::addTags(aString, "b,u"), sPatrick_2);
    QCOMPARE(html::addTags(bString,"t,p"),sPatrick_3);

    
    QString sPatrick_4 = "<p style='color : red;'>p</p>";//First one
    QString sPatrick_5 = "<u class='red'>k</u>";//Last one
    QString sPatrick_6 = "<span style='color : black;'>t</span>";
    
    qDebug() << "Adding attributes";
    QString pString2 = "p";
    QString kString = "k";
    QString tString = "t";
    QCOMPARE(html::addTags(pString2,"p","style='color : red;'"),sPatrick_4);
    QCOMPARE(html::addTags(kString,"u","class='red'"),sPatrick_5);
    QCOMPARE(html::addTags(tString,"span","style='color : black;'"),sPatrick_6);

}

void TestUtils::testRemoveTags() {
    QString patrick = "<p>p</p>"
            "<p>a</p>"
            "<p>t</p>"
            "<p>r</p>"
            "<p>i</p>"
            "<p>c</p>"
            "<p>k</p>";

    qDebug() << "Remove all the tags";
    QCOMPARE(html::removeTag(patrick, "p"), QString("patrick"));

    patrick = "<p>p</p><b>a</b>";
    qDebug() << "Remove only the asked tags";
    QCOMPARE(html::removeTag(patrick, "p"), QString("p<b>a</b>"));

    qDebug() << "Remove all the tags (no second arguments)";
    QCOMPARE(html::removeTag(patrick), QString("pa"));
}

QTEST_MAIN(TestUtils)
#include "testutils.moc"

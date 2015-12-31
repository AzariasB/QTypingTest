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
    void testAddClass();
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
    
    qDebug() <<"Get the absolute position of a char in a String";
    QCOMPARE(html::getAbsoluteCharPosition(joel_0,0),0);
    QCOMPARE(html::getAbsoluteCharPosition(joel_1,0),3);
    QCOMPARE(html::getAbsoluteCharPosition(joel_2,2),5);
    QCOMPARE(html::getAbsoluteCharPosition(joel_3,3),6);
    QCOMPARE(html::getAbsoluteCharPosition(joel_4,3),20);
    QCOMPARE(html::getAbsoluteCharPosition(joel_5,1),15);
}


void TestUtils::testAddClass() {
    QString patrick = "patrick";
    QString patrick_1 = "<p class='red'>patrick</p>";
    QString patrick_2 = "<b class='nope'>patrick</b>";
    
    qDebug() << "Adding a class and a tag to a QString";
    QCOMPARE(html::addTagAndClass(patrick,"p","red"),patrick_1);
    QCOMPARE(html::addTagAndClass(patrick,"b","nope"),patrick_2);
}


void TestUtils::testWordsFinding() {
    QString letters = "fod";
    QStringList found = factory::findExistingWords(letters,file::getWordsPath("en"));
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
    testAddClass();
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
    QString patrick = "patrick";
    QString sPatrick_1 = "<p>p</p>atrick"; //First one
    QString sPatrick_2 = "patric<p>k</p>"; //Last one
    QString sPatrick_3 = "pa<p>t</p>rick"; //Not last,not first
    
    QString sPatrick_4 = "<p><b>p</b></p>atrick";
    QString sPatrick_5 = "pa<u><b>t</b></u>rick";
    QString sPatrick_6 = "patric<i><p>k</p></i>";

    qDebug() << "Adding a single tag";
    QCOMPARE(html::addTagsAt(patrick, "p", 0), sPatrick_1);
    QCOMPARE(html::addTagsAt(patrick, "p", 6), sPatrick_2);
    QCOMPARE(html::addTagsAt(patrick, "p", 2), sPatrick_3);
    
    qDebug() << "Adding multiples tags";
    QCOMPARE(html::addTagsAt(patrick,"p,b",0),sPatrick_4);
    QCOMPARE(html::addTagsAt(patrick,"u,b",2),sPatrick_5);
    QCOMPARE(html::addTagsAt(patrick,"i,p",6),sPatrick_6);
    
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

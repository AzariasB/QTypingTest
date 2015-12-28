/* 
 * File:   TestTUser.cpp
 * Author: boutina
 * 
 * Created on 18 décembre 2015, 20:00
 */

#include <QtTest/QtTest>
#include <QDebug>
#include "../../src/Util/htmlhelper.h"

class TestUtils : public QObject {
    Q_OBJECT
private slots:
    void testSurroundAll();
    void testSurroundAt();
    void testRemoveTags();

};

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
    
    qDebug() << "Surrounding the first char";
    QCOMPARE(html::addTagAt(patrick, "p", 0), sPatrick_1);
    
    qDebug() << "Surrounding the last char";
    QCOMPARE(html::addTagAt(patrick, "p", 6), sPatrick_2);
    
    qDebug() << "Surrounding the 3rd char";
    QCOMPARE(html::addTagAt(patrick, "p", 2), sPatrick_3);
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
    QCOMPARE(html::removeTag(patrick,"p"),QString("patrick"));
    
    patrick = "<p>p</p><b>a</b>";
    qDebug() << "Remove only the asked tags";
    QCOMPARE(html::removeTag(patrick,"p"),QString("p<b>a</b>"));
    
    qDebug() << "Remove all the tags (no second arguments)";
    QCOMPARE(html::removeTag(patrick),QString("pa"));
}

QTEST_MAIN(TestUtils)
#include "testutils.moc"

/*
  Name: Annie Wong
  Date: 9/5/2013
  PID: aywong
  */

#include <QtTest/QtTest>
#include "profFunc.h"

class TestProfFunc: public QObject
{
    Q_OBJECT

private slots:
    void proFunc_data();
    void proFunc();
};

void TestProfFunc::proFunc_data()
{
    QTest::addColumn<int>("srcLen");
    QTest::addColumn<QString>("src");
    QTest::addColumn<int>("destLen");
    QTest::addColumn<QString>("dest");
    QTest::addColumn<int>("result");

    QTest::newRow("src small") << 3 << "bye" << 5 << "hello" << 3;
    QTest::newRow("dest small") << 3 << "yes" << 2 << "no" << 2;
}

void TestProfFunc::proFunc()
{
    QFETCH(int, srcLen);
    QFETCH(QString, src);
    QFETCH(int, destLen);
    QFETCH(QString, dest);
    QFETCH(int, result);

    QVERIFY(srcLen > 0);
    QVERIFY(destLen > 0);

    const char *source = src.toStdString().c_str();
    Q_CHECK_PTR(source);
    char *destination = dest.toLocal8Bit().data();
    Q_CHECK_PTR(destination);

    QCOMPARE(profFunc(srcLen, source, destLen, destination), result);

    for(int i = 0; i < result; i++)
    {
        QCOMPARE(*destination, *source);
        destination++;
        source++;
    }

}

QTEST_MAIN(TestProfFunc)
#include "testproffunc.moc"

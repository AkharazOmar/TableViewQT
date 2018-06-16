#include "testsuite.h"

#include <QtTest/QtTest>


int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    int failedSuitesCount = 0;

    QVector<QObject *>::const_iterator iter;
    for (iter = TestSuite::suites_.constBegin();
         iter != TestSuite::suites_.constEnd();
         ++iter) {
        const int result = QTest::qExec(*iter);
        if (result != 0) {
            failedSuitesCount++;
        }
    }
    return failedSuitesCount;
}

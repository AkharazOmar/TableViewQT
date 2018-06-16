#include "testsuite.h"


QVector<QObject *> TestSuite::suites_;

TestSuite::TestSuite(QObject *parent) : QObject(parent)
{
    suites_.push_back(this);
}

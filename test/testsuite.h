#ifndef TESTSUITE_H
#define TESTSUITE_H

#include <QObject>
#include <QVector>

class TestSuite : public QObject
{
    Q_OBJECT
public:
    explicit TestSuite(QObject *parent = nullptr);

    static QVector<QObject *> suites_;
};

#endif // TESTSUITE_H

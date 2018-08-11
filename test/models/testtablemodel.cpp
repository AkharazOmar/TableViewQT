#include "testtablemodel.h"

#include <QTest>

namespace tests {
void TestTableModel::initTestCase()
{
    testModel = std::make_unique<eventManager::model::TableModel>();
}

// testData
void TestTableModel::testData()
{
    QCOMPARE(testModel->rowCount(testModel->index(0, 0)), 0);
    testModel->createEvent();
    QCOMPARE(testModel->rowCount(testModel->index(0, 0)), 1);
    QCOMPARE(testModel->data(testModel->index(0,0)).toString(), QStringLiteral("1"));
    QCOMPARE(testModel->data(testModel->index(0,1)).toString(), QStringLiteral("2"));
    QCOMPARE(testModel->data(testModel->index(0,2)).toString(), QStringLiteral("3"));

}

// testColumnCount
void TestTableModel::testColumnCount()
{
    QCOMPARE(testModel->columnCount(testModel->index(0, 0)), 3);
}

void TestTableModel::testEvents()
{

}

void TestTableModel::testCreateEvent()
{

}

// Clean the context of test
void TestTableModel::cleanupTestCase()
{
    // TODO: nothing at this time
}

static TestTableModel testModel;
}

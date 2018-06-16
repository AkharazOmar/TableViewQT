#include "testtablemodel.h"

#include <QTest>

namespace tests {
void TestTableModel::initTestCase()
{
    testModel.reset(new eventManager::model::TableModel);
}

// testData
void TestTableModel::testData()
{

}

// testColumnCount
void TestTableModel::testColumnCount()
{
    QCOMPARE(testModel.get()->columnCount(testModel.get()->index(0, 0)), 3);
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

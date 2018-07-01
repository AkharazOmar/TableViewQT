#ifndef TESTTABLEMODEL_H
#define TESTTABLEMODEL_H


#include "models/tablemodel.h"
#include "test/testsuite.h"
#include <memory>

namespace tests {
class TestTableModel: public TestSuite
{
    Q_OBJECT

private slots:
    // set context of test
    void initTestCase();

    // testData
    void testData();

    // testColumnCount
    void testColumnCount();

    void testEvents();

    void testCreateEvent();

    // Clean the context of test
    void cleanupTestCase();

private:
    std::unique_ptr<eventManager::model::TableModel> testModel;
};
}
#endif // TESTTABLEMODEL_H

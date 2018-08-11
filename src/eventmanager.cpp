#include "eventmanager.h"
#include "ui_eventmanager.h"
#include <QDebug>
#include <memory>

namespace eventManager {


EventManager::EventManager(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EventManager)
{
    ui->setupUi(this);

    _theProxyModel = std::make_unique<eventManager::controller::ProxyModel>();

    _myModel = std::make_unique<eventManager::model::TableModel>();
    _theProxyModel->setSourceModel(_myModel.get());

    _theProxyModel->moveToThread(&modelThread);
    modelThread.start();
    ui->tableView->setModel(_theProxyModel.get());

    connect(ui->pushButton, &QPushButton::clicked, _myModel.get(), &model::TableModel::createEvent);

    connect(ui->tableView, &QTableView::clicked, this, &EventManager::onClicked);
}

void EventManager::onClicked(const QModelIndex &index)
{
    qDebug() << "FIXME: EventManager::onClicked " << index;
}

EventManager::~EventManager() noexcept
{
    try {
        delete ui;
    } catch (std::exception &ex) {
        qCritical() << "Exception raise in destructor of EventManager";
        qCritical() << ex.what();
    }
}

}  // namespace eventManager

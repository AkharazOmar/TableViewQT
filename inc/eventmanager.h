#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "controler/proxymodel.h"
#include "models/tablemodel.h"

#include <QMainWindow>
#include <QThread>
#include <memory>

namespace Ui {

class EventManager;
}

namespace eventManager {

/**
 * @todo write docs
 */
class EventManager : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * Default constructor
     */
    explicit EventManager(QWidget *parent = Q_NULLPTR);

    /**
     * Destructor
     */
    ~EventManager() noexcept final;

private Q_SLOTS:
    //! slot call when click in tableView
    void onClicked(const QModelIndex &index);

private:
    /// user interface qt
    Ui::EventManager *ui;

    /// Thread for model
    QThread modelThread;

    /// Proxy model
    std::unique_ptr<eventManager::controller::ProxyModel> _theProxyModel;

    /// Model
    std::unique_ptr<eventManager::model::TableModel> _myModel;
};

}  // namespace eventManager
#endif // EVENTMANAGER_H

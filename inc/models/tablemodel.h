#include <QAbstractTableModel>

#include "models/event.h"
#ifndef TABLEMODEL_H
#define TABLEMODEL_H

namespace eventManager  {
namespace model {

/**
 * @todo write docs
 */
class TableModel final: public QAbstractTableModel
{
    Q_OBJECT
public:

    /// Contructor
    explicit TableModel(QObject * parent=Q_NULLPTR);
    /**
     * @todo write docs
     *
     * @param index TODO
     * @param role TODO
     * @return TODO
     */
    QVariant data ( const QModelIndex& index, int role=Qt::DisplayRole ) const override;

    /**
     * @todo write docs
     *
     * @param parent TODO
     * @return TODO
     */
    int columnCount ( const QModelIndex& parent ) const  override;

    /**
     * @todo write docs
     *
     * @param parent TODO
     * @return TODO
     */
    int rowCount ( const QModelIndex& parent ) const  override;

    /**
     * @return the _events
     */
    const QList<Event>& events() const;

public Q_SLOTS:
     void createEvent();
private:
    QList<Event> m__events;
};
}  // namespace model
}  // namespace eventManager
#endif // TABLEMODEL_H

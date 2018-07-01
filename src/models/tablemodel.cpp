#include "models/tablemodel.h"

#include <QDebug>

namespace eventManager  {
namespace model {

/// Contructor
TableModel::TableModel(QObject * parent):
    QAbstractTableModel(parent)
{

}

QVariant TableModel::data ( const QModelIndex& index, int role ) const
{

    if (!index.isValid()) {
        return QVariant();
    }
    QVariant result;
    switch(role) {
        case Qt::DisplayRole:
            {
                const auto &event = m__events.at(index.row());
                qDebug() << "event: " << event.standardAttribute("first");
                if (index.column() < Event::STANDARD_ATTRIBUTE.size()) {
                    result = event.standardAttribute(Event::STANDARD_ATTRIBUTE.at(index.column()));
                }
            }
            break;
        case Qt::UserRole:
            result.setValue<Event>(m__events.at(index.row()));
            break;
        default:
            break;
    }
    return result;
}

int TableModel::columnCount ( const QModelIndex& parent ) const
{
    Q_UNUSED(parent);
    // TODO:
    return 3;
}

int TableModel::rowCount ( const QModelIndex& parent ) const
{
    Q_UNUSED(parent);
    return  m__events.size();
}

const QList<Event>& TableModel::events() const
{
    return m__events;
}

void TableModel::createEvent()
{
    Event ev;

    ev.setStandardAttribute("first", "1");
    ev.setStandardAttribute("second", "2");
    ev.setStandardAttribute("tree", "3");

    beginInsertRows(QModelIndex(), events().size(), events().size());
    m__events.append(ev);
    endInsertRows();

}
}
}

#include "mymodel.h"

MyModel::MyModel(QStringList stringList, QObject *parent)
    : QAbstractListModel {parent}, _stringList {std::move(stringList)}
{
}

int MyModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return _stringList.count();
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= _stringList.count()) {
        return QVariant();
    }
    if (role == Qt::DisplayRole) {
        return _stringList.at(index.row());
    }
    return QVariant();
}

QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole) {
        return QVariant();
    }
    if (orientation == Qt::Horizontal) {
        return QStringLiteral("Column %1").arg(section);
    }
    return QStringLiteral("Row %1").arg(section);
}

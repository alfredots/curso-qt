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
    if (role == Qt::DisplayRole || role == Qt::EditRole) {
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

bool MyModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        _stringList.replace(index.row(), value.toString());
        Q_EMIT dataChanged(index, index, {role});
        return true;
    }
    return false;
}

Qt::ItemFlags MyModel::flags(const QModelIndex &index) const
{
    if (!index.isValid()) {
        return Qt::ItemIsEnabled;
    }
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool MyModel::insertRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(parent)
    beginInsertRows(QModelIndex(), row, row+count-1);

    for (int i = 0; i < count; ++i) {
        _stringList.insert(row, QLatin1String(""));  // clazy:exclude=qt6-qlatin1stringchar-to-u
    }

    endInsertRows();
    return true;
}

bool MyModel::removeRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(parent)
    beginRemoveRows(QModelIndex(), row, row+count-1);

    for (int i = 0; i < count; ++i) {
        _stringList.removeAt(row);
    }

    endRemoveRows();
    return true;
}

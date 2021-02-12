#ifndef MYMODEL_H
#define MYMODEL_H

#include <QAbstractListModel>

class MyModel : public QAbstractListModel
{
    Q_OBJECT

public:
    MyModel(QStringList stringList, QObject *parent = nullptr);

    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    virtual Qt::ItemFlags flags(const QModelIndex &index) const override;
    virtual bool insertRows(int row, int count, const QModelIndex &parent) override;
    virtual bool removeRows(int row, int count, const QModelIndex &parent) override;

private:
    QStringList _stringList;    
};

#endif // MYMODEL_H

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

private:
    QStringList _stringList;
};

#endif // MYMODEL_H

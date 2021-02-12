#include "rssfeedmodel.h"
#include "QNetworkReply"

#include <QXmlQuery>

RssFeedModel::RssFeedModel(const QString &feedUrl, QObject *parent)
    : QAbstractListModel(parent)
{
    auto *reply = _nam.get(QNetworkRequest{ QUrl{feedUrl} });
    connect(reply, &QNetworkReply::finished, this, [=](){
        QString feedXml = reply->readAll();
        reply->deleteLater();
//        qDebug() << feedXml;
        QXmlQuery query;
        query.setFocus(feedXml);
        query.setQuery(QStringLiteral("//rss/channel/item/title/string()"));
        query.evaluateTo(&_postTitles);
//        qDebug() << _postTitles;
        Q_EMIT dataChanged(index(0), index(_postTitles.count()-1));
    });
    // o codigo que vc vai colocar é absurdamento grande? use slot
    // até  dez linhas? use um lambda
}

int RssFeedModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return _postTitles.count();
}

QVariant RssFeedModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= _postTitles.count()) {
        return {};
    }
    if(role == Qt::DisplayRole) {
        return _postTitles.at(index.row());
    }
    return {};
}

QVariant RssFeedModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole) {
        return {};
    }
    if (orientation == Qt::Horizontal) {
        return "Title";
    }
    return QString::number(section);
}

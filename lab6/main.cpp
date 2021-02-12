#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QSqlDatabase>

void connect() {
    qDebug() << "Available drivers: " << QSqlDatabase::drivers();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("teste.db");
    qDebug() << db.open();
    qDebug() << db;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connect();
    MainWindow w;
    w.show();
    return a.exec();
}

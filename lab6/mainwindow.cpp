#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>
#include <QFileSystemModel>
#include <QtSql/QSqlTableModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto *model = new QFileSystemModel{this};
    model->setRootPath(QDir::homePath());
    ui->treeView->setModel(model);
    ui->treeView->setRootIndex(model->index(QDir::homePath()));

    QSqlTableModel *dbModel = new QSqlTableModel;
    dbModel->setTable("produtos");
    qDebug() << dbModel->select();
    dbModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    dbModel->setHeaderData(0, Qt::Horizontal, tr("Nome"));
    dbModel->setHeaderData(1, Qt::Horizontal, tr("Categoria"));
    dbModel->setHeaderData(2, Qt::Horizontal, tr("Valor"));

    ui->tableView->setModel(dbModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}


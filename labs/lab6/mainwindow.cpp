#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFileSystemModel>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create file system model and adjust its root path
    auto *model = new QFileSystemModel {this};
    model->setRootPath(QDir::homePath());

    // Use this model in treeview
    ui->treeView->setModel(model);

    // Adjust view root index
    ui->treeView->setRootIndex(model->index(model->rootPath()));

    // Stretch view's last section
    ui->treeView->header()->setStretchLastSection(true);

    // Ensure folder/file names are always fully visible
    connect(model, &QFileSystemModel::directoryLoaded, this, [this]() { ui->treeView->resizeColumnToContents(0); });
}

MainWindow::~MainWindow()
{
    delete ui;
}

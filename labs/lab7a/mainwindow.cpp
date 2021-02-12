#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <utility>

#include "mymodel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow {parent}
    , ui {new Ui::MainWindow}
{
    ui->setupUi(this);
    auto *model = new MyModel {{"Hello ...", "Pulse!"}, this};
    ui->listView->setModel(model);
    ui->listView->selectionModel()->setCurrentIndex(model->index(0, 0), QItemSelectionModel::Select);
}

MainWindow::~MainWindow()
{
    delete ui;
}


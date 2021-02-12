#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QKeyEvent>
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
    ui->listView->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->listView) {
        if (event->type() == QEvent::KeyPress) {
            auto *keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Delete) {
                int row = ui->listView->selectionModel()->currentIndex().row();
                ui->listView->model()->removeRow(row);
                return true;
            }
        }
        return QMainWindow::eventFilter(watched, event);
    }
    return QMainWindow::eventFilter(watched, event);
}

void MainWindow::on_psbAdd_clicked()
{
    auto *model = ui->listView->model();
    int count = model->rowCount();
    model->insertRow(count);
    auto index = model->index(count, 0);
    ui->listView->selectionModel()->setCurrentIndex(index, QItemSelectionModel::Clear | QItemSelectionModel::Select);
    ui->listView->edit(index);
}

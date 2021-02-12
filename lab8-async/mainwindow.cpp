#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPromise>
#include <QtConcurrent/QtConcurrent>
#include <QFutureWatcher>

void aFunction (QPromise<void> &promise) {
    qDebug() << "aFunction";
    promise.setProgressRange(0, 100);
    for(int i = 0; i < 100; ++i) {
        promise.suspendIfRequested();
        if (promise.isCanceled())
            return ;
        promise.setProgressValue(i);
        QThread::sleep(1);
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&_watcher, &QFutureWatcher<void>::progressValueChanged, ui->progressBar, &QProgressBar::setValue);

    _watcher.setFuture(QtConcurrent::run(aFunction));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_toggleButton_clicked()
{
    qDebug() << ui->toggleButton->isChecked();
    if(ui->toggleButton->isChecked()) {
        _watcher.future().suspend();
        ui->toggleButton->setText("Resume");
    } else {
        _watcher.future().resume();
        ui->toggleButton->setText("Suspend");
    }
}

void MainWindow::on_cancelButton_clicked()
{
    _watcher.future().cancel();
}

void MainWindow::on_pushButton_clicked()
{
    _watcher.setFuture(QtConcurrent::run(aFunction));
}

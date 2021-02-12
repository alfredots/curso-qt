#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QtConcurrent/QtConcurrentRun>
#include <QPromise>

void process(QPromise<int> &promise)
{
    promise.setProgressRange(0, 99);
    for (int i = 0; i < 100; ++i) {
        promise.suspendIfRequested();
        if (promise.isCanceled()) {
            return;
        }
        promise.addResult(i);
        promise.setProgressValue(i);
        QThread::sleep(1);
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _watcher.setFuture(QtConcurrent::run(process));
    connect(&_watcher, &QFutureWatcher<int>::progressValueChanged, ui->progressBar, &QProgressBar::setValue);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_psbPauseResume_clicked()
{
    if (ui->psbPauseResume->isChecked()) {
        _watcher.future().suspend();
        ui->psbPauseResume->setText(tr("&Resume"));
    } else {
        _watcher.future().resume();
        ui->psbPauseResume->setText(tr("&Pause"));
    }
}

void MainWindow::on_psbCancel_clicked()
{
    _watcher.future().cancel();
}

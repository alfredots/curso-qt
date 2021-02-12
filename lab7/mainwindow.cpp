#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "rssfeedmodel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto *model = new RssFeedModel{QStringLiteral("https://planet.qt.io/rss20.xml"), this};
    ui->listView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}


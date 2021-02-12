#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private Q_SLOTS:
    void on_psbAdd_clicked();  // clazy:exclude=connect-by-name

private:
    Ui::MainWindow *ui;

    virtual bool eventFilter(QObject *watched, QEvent *event) override;
};
#endif // MAINWINDOW_H

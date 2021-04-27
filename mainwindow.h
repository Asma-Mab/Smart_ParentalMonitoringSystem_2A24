#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "secdialog.h"
#include "mainwindow2.h"
#include <QDialog>
#include <QObject>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Login_clicked();

private:
    Ui::MainWindow *ui;
    MainWindow2 *newmain2;
};
#endif // MAINWINDOW_H

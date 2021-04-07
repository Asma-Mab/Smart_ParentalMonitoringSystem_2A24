#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "site.h"
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <enfant.h>
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
    void on_btn_ajout_clicked();

    void on_btn_supp_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_btn_ajout_2_clicked();

    void on_btn_supp_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    site C;
    enfant l;
};
#endif // MAINWINDOW_H

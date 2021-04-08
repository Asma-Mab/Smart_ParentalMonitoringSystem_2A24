#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connexion.h"
#include <QMessageBox>
#include <QPixmap>
#include <QLabel>

Connection ::Connection()
{


}
bool Connection::createconnect()
{ bool test=false;
    QSqlDatabase db = QSqlDatabase ::addDatabase("QODBC");
    db.setDatabaseName("projet2021");
    db.setUserName("mohamed");
    db.setPassword("0000");
    if (db.open())
        test=true;
    return test;



}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);   
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Login_clicked()
{
    QString username = ui ->lineEdit_username->text();
    QString password = ui ->lineEdit_password->text();

    if(username == "bayoudh" &&  password == "gogo0000") {
    QMessageBox::information(this, "Login","Username and  password is correct");
    hide();
    MainWindow2 *newmain2=new MainWindow2();
    newmain2->show();
    }
    else {
    QMessageBox::warning(this, "Login","Username or  password is not correct");
}
}

#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_Login_clicked()
{

    QString username = ui ->lineEdit_username->text();
    QString password = ui ->lineEdit_password->text();


    if((username == "bayoudh" && password =="0000") || (username =="nermin" && password=="0000") || (username == "nathir" && password =="0000" ))
    {
    QMessageBox::information(this, "Login","Username and  password is correct");
    hide();
    MainWindow *newmain2=new MainWindow();
    newmain2->show();
    }
    else {
    QMessageBox::warning(this, "Login","Username or  password is not correct");
}
}

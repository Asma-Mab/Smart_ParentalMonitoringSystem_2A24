#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include <QThread>
#include <QLabel>
#include <QPixmap>
#include <QGridLayout>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QDebug>
#include <QVideoWidget>

MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
}

MainWindow2::~MainWindow2()
{
    delete ui;
}
void MainWindow2::on_pushButton_exit_clicked()
{

    QMediaPlayer* player;
    player= new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/Bayoudh Mohamed/Desktop/icons/bon travail et aurevoir.mp3"));
        player->play();
        qDebug()<<player->errorString();
        QThread::sleep(2);
        QVideoWidget * VW =new QVideoWidget ;
                  player->setVideoOutput(VW);
                  player->setMedia(QUrl::fromLocalFile("C:/Users/Bayoudh Mohamed/Desktop/icons/thank.mpg"));
                  VW->setGeometry(350,120,700,500);
                  VW->show();
                  player->setVolume(10);
                  player->play();
                  qDebug() <<player->state();
                  QThread::sleep(5);
                  VW->close();
                  close();

}



void MainWindow2::on_pushButton_profiles_clicked()
{
    QMediaPlayer* player;
    player= new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/Bayoudh Mohamed/Desktop/icons/gestion des utilisateur.mp3"));
        player->play();
        qDebug()<<player->errorString();
        QThread::sleep(1);
    gc=new gestion_profiles(this);
    gc->show();
}

void MainWindow2::on_pushButton_utilisateurs_clicked()
{
    QMediaPlayer* player;
    player= new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/Bayoudh Mohamed/Desktop/icons/gestion des utilisateur.mp3"));
        player->play();
        qDebug()<<player->errorString();
        QThread::sleep(1);
    gf=new gestion_utilisateurs(this);
    gf->show();
}


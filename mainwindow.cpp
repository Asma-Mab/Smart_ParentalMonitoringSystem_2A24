    #include "mainwindow.h"
#include "ui_mainwindow.h"
#include "evenementinter.h"
#include "promotionitinter.h"
#include"activiteui.h"
#include "contactui.h"
#include<QFileDialog>
#include <QDateTime>
#include <QThread>
#include <QLabel>
#include <QPixmap>
#include <QGridLayout>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QDebug>
#include <QVideoWidget>
#include "enfant_inter.h"
#include "equipement.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Home");
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(myfunction()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_3_clicked()
{
    ContactUI *co = new ContactUI();
    co->show();

}

void MainWindow::myfunction()
{
  QTime time = QTime::currentTime();
  QString time_text = time.toString("hh : mm : ss");
  if((time.second()%2)==0)
  {
      time_text[3] = ' ';
      time_text[8] = ' ';
  }
  ui->label_date->setText(time_text);
}

void MainWindow::on_pushButton_4_clicked()
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

void MainWindow::on_pushButton_5_clicked()
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

void MainWindow::on_pushButton_6_clicked()
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

void MainWindow::on_pushButton_7_clicked()
{
    Enfant_Inter *w = new Enfant_Inter();
    w->show();

}

void MainWindow::on_pushButton_8_clicked()
{
    Equipement *eq = new Equipement();
    eq->show();
}

#include "mainwindow.h"
#include"connexion.h"
#include <QThread>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QMediaPlaylist>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMediaPlayer * player = new QMediaPlayer;
        QVideoWidget * VW =new QVideoWidget ;
        player->setVideoOutput(VW);
        player->setMedia(QUrl::fromLocalFile("C:/Users/Bayoudh Mohamed/Desktop/icons/aa.mpg"));
        VW->setGeometry(320,120,700,500);
        VW->show();
        player->play();
        qDebug() <<player->state();
        QThread::sleep(9);
        VW->close();

     player= new QMediaPlayer;
     player->setMedia(QUrl::fromLocalFile("C:/Users/Bayoudh Mohamed/Desktop/icons/bienvenu.mp3"));
        player->play();
       qDebug()<<player->errorString();
    MainWindow w;
    Connection c;
            bool test=c.createconnect();
            if(!test)
        {
                QMessageBox::critical( nullptr ,QObject::tr("database isn't open")
                        ,QObject::tr("connection failed.\n"
                                    "Click Cancel to exit.") ,QMessageBox::Cancel);



        }
            else{
    w.show();}
    return a.exec();
}

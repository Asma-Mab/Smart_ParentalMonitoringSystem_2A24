#include "gestion_utilisateurs.h"
#include "ui_gestion_utilisateurs.h"
#include <QString>
#include <QMessageBox>
#include "crud_utilisateurs.h"
#include <QThread>
#include <QPixmap>
#include <QPrinter>
#include <QPrintDialog>
#include <QtPrintSupport>
#include <QObject>
#include <QMediaPlayer>
gestion_utilisateurs::gestion_utilisateurs(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gestion_utilisateurs)
{
    ui->setupUi(this);
    ui->tableView->setModel(temputilisateurs.afficher());
    player= new QMediaPlayer(this);
    QPixmap pix("C:/Users/Bayoudh Mohamed/Desktop/Dhouse-module_gsetion_des_clients/client icon.jpg");
    ui -> label_pixmap ->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
}

gestion_utilisateurs::~gestion_utilisateurs()
{
    delete ui;
}
void gestion_utilisateurs::on_pushButton_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Bayoudh Mohamed/Desktop/Dhouse-module_gsetion_des_clients/Quitter.mp3"));
                player->play();
                qDebug()<<player->errorString();
                QThread::sleep(1);
    close();
}

void gestion_utilisateurs::on_pushButton_ajoute_clicked()
{
    int i=ui->lineEdit_id->text().toInt();
    QString p=ui->lineEdit_prenom->text();
    QString n=ui->lineEdit_nom->text();
    int a=ui->lineEdit_age->text().toInt();
        crud_utilisateurs c(i,p,n,a);
        bool test = c.ajouter();
        if (test)
        {
            player->setMedia(QUrl::fromLocalFile("C:/Users/Bayoudh Mohamed/Desktop/icons/utilisateur ajouter.mp3"));
                        player->play();
                        qDebug()<<player->errorString();
                        QThread::sleep(1);

            ui->tableView->setModel(temputilisateurs.afficher());

            QMessageBox::information(nullptr,"AJOUT utilisateurs","utilisateurs AJOUTEE");
        }
        else
        {
            QMessageBox::warning(nullptr,"AJOUT utilisateurs","utilisateurs NON AJOUTEE");
        }


}
void gestion_utilisateurs::on_pushButton_2_clicked()
{
    int id = ui->lineEdit_id_supprimer->text().toInt();
    bool test = temputilisateurs.supprimer(id);
    if (test)
    {
        player->setMedia(QUrl::fromLocalFile("C:/Users/Bayoudh Mohamed/Desktop/icons/utilisateur supprime.mp3"));
                    player->play();
                    qDebug()<<player->errorString();
                    QThread::sleep(1);
        ui->tableView->setModel(temputilisateurs.afficher());

        QMessageBox::information(nullptr,"SUPPRIMER utilisateurs","utilisateurs SUPPRIMER !");
    }
    else
    {
        QMessageBox::warning(nullptr,"SUPPRIMER utilisateurs","utilisateurs NON SUPPRIMER !");
    }
}


void gestion_utilisateurs::on_pushButton_modifer_clicked()
{
    int i=ui->lineEdit_id_modifer->text().toInt();
    QString p=ui->lineEdit_prenom_modifer->text();
    QString n=ui->lineEdit_nom_modifer->text();
    int a=ui->lineEdit_age_modifer->text().toInt();
        crud_utilisateurs c(i,p,n,a);
        bool test = c.modifer();
        if (test)
        {
            player->setMedia(QUrl::fromLocalFile("C:/Users/Bayoudh Mohamed/Desktop/icons/utilisateur modifier.mp3"));
                        player->play();
                        qDebug()<<player->errorString();
                        QThread::sleep(1);
            ui->tableView->setModel(temputilisateurs.afficher());

            QMessageBox::information(nullptr,"MODIFER utilisateurs","utilisateurs MODIFER");
        }
        else
        {
            QMessageBox::warning(nullptr,"MODIFER utilisateurs","utilisateurs NON MODIFER");
        }


}



void gestion_utilisateurs::on_checkBox_clicked()
{
    bool test = true;
      if (test)
          {
          ui->tableView->setModel(temputilisateurs.afficher());

              ui->tableView->setModel(temputilisateurs.trierid());



          }

      else
      {
          QMessageBox::critical(nullptr, QObject::tr("trier utilisateurs"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
      }

}

void gestion_utilisateurs::on_checkBox_2_clicked()
{
    bool test = true;
      if (test)
          {
          ui->tableView->setModel(temputilisateurs.afficher());

              ui->tableView->setModel(temputilisateurs.trierprenom());


          }

      else
      {
          QMessageBox::critical(nullptr, QObject::tr("trier utilisateurs"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
      }

}

void gestion_utilisateurs::on_checkBox_3_clicked()
{
    bool test = true;
      if (test)
          {
          ui->tableView->setModel(temputilisateurs.afficher());

              ui->tableView->setModel(temputilisateurs.triernom());


          }

      else
      {
          QMessageBox::critical(nullptr, QObject::tr("trier utilisateurs"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
      }

}

void gestion_utilisateurs::on_checkBox_4_clicked()
{
    bool test = true;
      if (test)
          {
          ui->tableView->setModel(temputilisateurs.afficher());

              ui->tableView->setModel(temputilisateurs.trierage());



          }

      else
      {
          QMessageBox::critical(nullptr, QObject::tr("trier utilisateurs"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
      }

}


void gestion_utilisateurs::on_pushButton_impression_client_clicked()
{

    QPrinter printer;
    printer.setPrinterName("diserter printer name");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec()==QDialog::Rejected)return;
    ui->tableView->render(&printer);
}

void gestion_utilisateurs::on_pushButton_rechercher_2_clicked()
{
    ui->tableView->setModel(temputilisateurs.afficher());
        QString prenom = ui->lineEdit_id->text();
       ui->tableView_recherche_2->setModel(temputilisateurs.afficher_nom(prenom));
}
//
void gestion_utilisateurs::on_pushButton_rechercher_3_clicked()
{
    ui->tableView->setModel(temputilisateurs.afficher());
        QString prenom = ui->lineEdit_id_supprimer->text();
       ui->tableView_recherche_3->setModel(temputilisateurs.afficher_nom(prenom));
}

void gestion_utilisateurs::on_pushButton_rechercher_4_clicked()
{
    ui->tableView->setModel(temputilisateurs.afficher());
        QString prenom = ui->lineEdit_id_modifer->text();
       ui->tableView_recherche_4->setModel(temputilisateurs.afficher_nom(prenom));
}


void gestion_utilisateurs::on_pushButton_3_clicked()
{
    ui->tableView->setModel(temputilisateurs.afficher());
        QString prenom = ui->lineEdit_prenom->text();
       ui->tableView_recherche_2->setModel(temputilisateurs.afficher_prenom(prenom));
}

void gestion_utilisateurs::on_radioButton_clicked()
{

    ui->tableView->setModel(temputilisateurs.afficher());
    ui->tableView->setModel(temputilisateurs.afficher());
        QString prenom = ui->lineEdit_recherche->text();
       ui->tableView_recherche->setModel(temputilisateurs.afficher_nom(prenom));
}

void gestion_utilisateurs::on_radioButton_2_clicked()
{

    ui->tableView->setModel(temputilisateurs.afficher());
    ui->tableView->setModel(temputilisateurs.afficher());
        QString prenom = ui->lineEdit_recherche->text();
       ui->tableView_recherche->setModel(temputilisateurs.afficher_prenom(prenom));
}

void gestion_utilisateurs::on_radioButton_3_clicked()
{

    ui->tableView->setModel(temputilisateurs.afficher());
    ui->tableView->setModel(temputilisateurs.afficher());
        QString prenom = ui->lineEdit_recherche->text();
       ui->tableView_recherche->setModel(temputilisateurs.afficher_id(prenom));
}

void gestion_utilisateurs::on_radioButton_4_clicked()
{

    ui->tableView->setModel(temputilisateurs.afficher());
    ui->tableView->setModel(temputilisateurs.afficher());
        QString prenom = ui->lineEdit_recherche->text();
       ui->tableView_recherche->setModel(temputilisateurs.afficher_age(prenom));
}


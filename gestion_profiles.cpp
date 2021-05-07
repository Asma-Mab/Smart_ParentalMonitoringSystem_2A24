#include "gestion_profiles.h"
#include "ui_gestion_profiles.h"
#include <QString>
#include <QMessageBox>
#include "crud_profiles.h"
#include <QThread>
#include <QPixmap>
#include <QPrinter>
#include <QPrintDialog>
#include <QtPrintSupport>
#include <QObject>
#include <QMediaPlayer>

gestion_profiles::gestion_profiles(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gestion_profiles)
{

    ui->setupUi(this);
    ui->tableView->setModel(tempprofiles.afficher());
    player= new QMediaPlayer(this);
    QPixmap pix("C:/Users/Bayoudh Mohamed/Desktop/icons/client icon.jpg");
    ui -> label_pixmap_2 ->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));


}

gestion_profiles::~gestion_profiles()
{
    delete ui;
}

void gestion_profiles::on_pushButton_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/Bayoudh Mohamed/Desktop/icons/Quitter.mp3"));
                player->play();
                qDebug()<<player->errorString();
                QThread::sleep(1);
    close();
}

void gestion_profiles::on_pushButton_ajoute_2_clicked()
{
    int nb = tempprofiles.request(ui->lineEdit_id_2->text());
    if(nb==0)
    {
        int i=ui->lineEdit_id_2->text().toInt();
        QString p=ui->lineEdit_prenom_2->text();
        QString n=ui->lineEdit_nom_2->text();
        QString a=ui->lineEdit_age_2->text();
            crud_profiles c(i,p,n,a);
            bool test = c.ajouter();
            if (test)
            {
                player->setMedia(QUrl::fromLocalFile("C:/Users/Bayoudh Mohamed/Desktop/icons/profile ajouter.mp3"));
                            player->play();
                            qDebug()<<player->errorString();
                            QThread::sleep(1);
                ui->tableView->setModel(tempprofiles.afficher());

                QMessageBox::information(nullptr,"AJOUT profiles","profile AJOUTEE");
            }
            else
            {
                QMessageBox::warning(nullptr,"AJOUT profiles","profile NON AJOUTEE");
            }

    }
    else
    {
        QMessageBox::warning(nullptr,"profiles","profile EXISTE");
    }


}
void gestion_profiles::on_pushButton_2_clicked()
{
    int id = ui->lineEdit_id_supprimer2->text().toInt();
    bool test = tempprofiles.supprimer(id);
    if (test)
    {
        player->setMedia(QUrl::fromLocalFile("C:/Users/Bayoudh Mohamed/Desktop/icons/profil supprime.mp3"));
                    player->play();
                    qDebug()<<player->errorString();
                    QThread::sleep(1);
        ui->tableView->setModel(tempprofiles.afficher());

        QMessageBox::information(nullptr,"SUPPRIMER profile","PROFILE SUPPRIMER !");
    }
    else
    {
        QMessageBox::warning(nullptr,"SUPPRIMER profile","PROFILE NON SUPPRIMER !");
    }
}


void gestion_profiles::on_pushButton_modifer_2_clicked()
{
    int i=ui->lineEdit_id_modifer_2->text().toInt();
    QString p=ui->lineEdit_prenom_modifer_2->text();
    QString n=ui->lineEdit_nom_modifer_2->text();
    QString a=ui->lineEdit_age_modifer_2->text();
        crud_profiles c(i,p,n,a);
        bool test = c.modifer();
        if (test)
        {
            player->setMedia(QUrl::fromLocalFile("C:/Users/Bayoudh Mohamed/Desktop/icons/profil modifier.mp3"));
                        player->play();
                        qDebug()<<player->errorString();
                        QThread::sleep(1);
            ui->tableView->setModel(tempprofiles.afficher());

            QMessageBox::information(nullptr,"MODIFER profiles","profiles MODIFER");
        }
        else
        {
            QMessageBox::warning(nullptr,"MODIFER profiles","profiles NON MODIFER");
        }


}



void gestion_profiles::on_checkBox_clicked()
{
    bool test = true;
      if (test)
          {
          ui->tableView->setModel(tempprofiles.afficher());

              ui->tableView->setModel(tempprofiles.trierid());



          }

      else
      {
          QMessageBox::critical(nullptr, QObject::tr("trier profiles"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
      }

}

void gestion_profiles::on_checkBox_2_clicked()
{
    bool test = true;
      if (test)
          {
          ui->tableView->setModel(tempprofiles.afficher());

              ui->tableView->setModel(tempprofiles.triertype());


          }

      else
      {
          QMessageBox::critical(nullptr, QObject::tr("trier profiles"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
      }

}

void gestion_profiles::on_checkBox_3_clicked()
{
    bool test = true;
      if (test)
          {
          ui->tableView->setModel(tempprofiles.afficher());

              ui->tableView->setModel(tempprofiles.trierNom());


          }

      else
      {
          QMessageBox::critical(nullptr, QObject::tr("trier profiles"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
      }

}

void gestion_profiles::on_checkBox_4_clicked()
{
    bool test = true;
      if (test)
          {
          ui->tableView->setModel(tempprofiles.afficher());

              ui->tableView->setModel(tempprofiles.trierpassword());



          }

      else
      {
          QMessageBox::critical(nullptr, QObject::tr("trier profiles"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
      }

}


void gestion_profiles::on_pushButton_impression_profil_clicked()
{

    QPrinter printer;
    printer.setPrinterName("diserter printer name");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec()==QDialog::Rejected)return;
    ui->tableView->render(&printer);
}

void gestion_profiles::on_pushButton_rech1_clicked()
{
    ui->tableView->setModel(tempprofiles.afficher());
        QString prenom = ui->lineEdit_id_2->text();
       ui->tableView_recherche_5->setModel(tempprofiles.afficher_Nom(prenom));
}
//
void gestion_profiles::on_pushButton_rech2_clicked()
{
    ui->tableView->setModel(tempprofiles.afficher());
        QString prenom = ui->lineEdit_id_supprimer2->text();
       ui->tableView_recherche_6->setModel(tempprofiles.afficher_Nom(prenom));
}

void gestion_profiles::on_pushButton_rech3_clicked()
{
    ui->tableView->setModel(tempprofiles.afficher());
        QString prenom = ui->lineEdit_id_modifer_2->text();
       ui->tableView_recherche_7->setModel(tempprofiles.afficher_Nom(prenom));
}


void gestion_profiles::on_lineEdit_recherche_2_clicked()
{
    ui->tableView->setModel(tempprofiles.afficher());
        QString prenom = ui->lineEdit_prenom_2->text();
       ui->tableView_recherche_5->setModel(tempprofiles.afficher_type(prenom));
}

void gestion_profiles::on_radioButton_5_clicked()
{

    ui->tableView->setModel(tempprofiles.afficher());
    ui->tableView->setModel(tempprofiles.afficher());
        QString prenom = ui->lineEdit_recherche_2->text();
       ui->tableView_recherche_8->setModel(tempprofiles.afficher_Nom(prenom));
}

void gestion_profiles::on_radioButton_6_clicked()
{

    ui->tableView->setModel(tempprofiles.afficher());
    ui->tableView->setModel(tempprofiles.afficher());
        QString prenom = ui->lineEdit_recherche_2->text();
       ui->tableView_recherche_8->setModel(tempprofiles.afficher_type(prenom));
}

void gestion_profiles::on_radioButton_7_clicked()
{

    ui->tableView->setModel(tempprofiles.afficher());
    ui->tableView->setModel(tempprofiles.afficher());
        QString prenom = ui->lineEdit_recherche_2->text();
       ui->tableView_recherche_8->setModel(tempprofiles.afficher_id(prenom));
}

void gestion_profiles::on_radioButton_8_clicked()
{

    ui->tableView->setModel(tempprofiles.afficher());
    ui->tableView->setModel(tempprofiles.afficher());
        QString prenom = ui->lineEdit_recherche_2->text();
       ui->tableView_recherche_8->setModel(tempprofiles.afficher_password(prenom));
}


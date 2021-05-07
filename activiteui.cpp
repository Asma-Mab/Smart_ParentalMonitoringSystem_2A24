#include "activiteui.h"
#include "ui_activiteui.h"
#include "activite.h"
#include "connection.h"
#include <QMessageBox>
#include<QFileDialog>
ActiviteUI::ActiviteUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ActiviteUI)
{
    ui->setupUi(this);

    setWindowTitle("Gestion d'activité");

    //Column size
    ui->tablemodifier->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //remplir combobox tri ADMIN
    QStringList list_tri_admin;
    list_tri_admin << "" << "NOM" << "TYPE" ;
    ui->comboBox_tri->addItems(list_tri_admin);


    //refresh
    refresh();
}

ActiviteUI::~ActiviteUI()
{
    delete ui;
}

void ActiviteUI::refresh()
{
    //refresh
    ui->tablemodifier->setModel(activiteTmp.afficher());

    ui->comboBox->setModel(activiteTmp.remplircomboactivity());
    ui->comboBox_modif->setModel(activiteTmp.remplircomboactivity());

}

void ActiviteUI::on_AjouterBouton_clicked()
{
    Activite act(ui->Nom->toPlainText(),ui->type->toPlainText(),ui->dateDebut->date(),ui->dateFin->date());
    bool test = act.ajouter();
    if(test)
{
        //refresh
        refresh();

        //NOTIFICATION
        trayIcon = new QSystemTrayIcon(this);
        trayIcon->setVisible(true);
        trayIcon->setIcon(this->style()->standardIcon(QStyle::SP_DesktopIcon));
        trayIcon->setToolTip("Ajouter" "\n"
                        "Ajouter avec sucées");
        trayIcon->showMessage("Ajouter","Ajouter avec sucées",QSystemTrayIcon::Information,1500);
        trayIcon->show();


        }
          else
          {
              QMessageBox::critical(nullptr, QObject::tr("Ajouter une activité"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
          }

}



void ActiviteUI::on_modifiebtn_clicked()
{
    if((ui->nommodif->text() != "") &&(ui->typemodif->text() != ""))
    {
        if(activiteTmp.modifier(ui->nommodif->text(),ui->typemodif->text(),ui->dateDebutmodif->date(),ui->dateFinmodif->date(),ui->comboBox_modif->currentText()))
        {
            //NOTIFICATION
            trayIcon = new QSystemTrayIcon(this);
            trayIcon->setVisible(true);
            trayIcon->setIcon(this->style()->standardIcon(QStyle::SP_DesktopIcon));
            trayIcon->setToolTip("Modifier" "\n"
                            "Modifier avec sucées");
            trayIcon->showMessage("Modifier","Modifier avec sucées",QSystemTrayIcon::Warning,1500);
            trayIcon->show();

            //refresh
            refresh();

        }
        else
        {

        }
    }
}

void ActiviteUI::on_SupprimerBouton_clicked()
{
    QMessageBox::StandardButton reply =QMessageBox::question(this,
                          "Supprimer","Voulez-vous vraiment supprimer ?",
                          QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        bool test=activiteTmp.supprimer(ui->comboBox->currentText().toInt());
        if(test)
        {
            //refresh
            refresh();

            //NOTIFICATION
            trayIcon = new QSystemTrayIcon(this);
            trayIcon->setVisible(true);
            trayIcon->setIcon(this->style()->standardIcon(QStyle::SP_DesktopIcon));
            trayIcon->setToolTip("Supprimer" "\n"
                            "Supprimer avec sucées");
            trayIcon->showMessage("Supprimer","Supprimer avec sucées",QSystemTrayIcon::Warning,1500);
            trayIcon->show();

        }
        else
        {
            QMessageBox::critical(this, QObject::tr("Supprimer une Activité"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }

    }

}

void ActiviteUI::on_comboBox_modif_currentIndexChanged(const QString &arg1)
{
    QSqlQuery query;

    QString id = ui->comboBox_modif->currentText();

    query =activiteTmp.request(id);
    if(query.exec())
    {
        while(query.next())
        {
            ui->nommodif->setText(query.value(1).toString());
            ui->typemodif->setText(query.value(2).toString());
            ui->dateDebutmodif->setDate(query.value(3).toDate());
            ui->dateFinmodif->setDate(query.value(4).toDate());

        }
    }

}

void ActiviteUI::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QSqlQuery query;

    QString id = ui->comboBox->currentText();

    query =activiteTmp.request(id);
    if(query.exec())
    {
        while(query.next())
        {
            ui->Nomval->setText(query.value(1).toString());
            ui->typeval->setText(query.value(2).toString());
            ui->Datedebutval->setText(query.value(3).toString());
            ui->Datefinval->setText(query.value(4).toString());

        }
    }

}


void ActiviteUI::on_trier_Button_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
           QSqlQuery *qry=new QSqlQuery();

           qry->prepare("select * from ACTIVITE ORDER BY NOM");
           qry->exec();
            modal->setQuery(*qry);
            ui->tablemodifier->setModel(modal);
}

void ActiviteUI::on_comboBox_tri_currentIndexChanged(const QString &arg1)
{
    if(!(ui->comboBox_tri->currentText()==""))
    {
        ui->tablemodifier->setModel(activiteTmp.triafficher(ui->comboBox_tri->currentText()));
    }

}


void ActiviteUI::on_recherche_cursorPositionChanged(int arg1, int arg2)
{
    ui->tablemodifier->setModel(activiteTmp.recherche_activite(ui->recherche->text()));

    QString test =ui->recherche->text();

    if(test=="")
    {
        ui->tablemodifier->setModel(activiteTmp.afficher());//refresh
    }

}

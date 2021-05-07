#include "evenementinter.h"
#include "ui_evenementinter.h"
#include "evenement.h"
#include "connection.h"
#include <QMessageBox>

EvenementInter::EvenementInter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EvenementInter)
{
    ui->setupUi(this);

    setWindowTitle("Gestion d'evenements");

    //Column size
    ui->tablemodifier->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //tabmodif
    Connection c;
    model = new QSqlTableModel(this);
    model = tmpevent.moodel();
    ui->tablemodifier->setModel(model);

    ui->comboBox->setModel(tmpevent.remplircomboevent());
    ui->comboBox_modif->setModel(tmpevent.remplircomboevent());
}

EvenementInter::~EvenementInter()
{
    delete ui;
}

void EvenementInter::on_AjouterBouton_clicked()
{
    Evenement event(ui->Nom->toPlainText(),ui->Description->toPlainText(),ui->dateEdit->date());
    bool test = event.ajouter();
    if(test)
{
        QMessageBox::information(nullptr, QObject::tr("Ajouter un Client"),
        QObject::tr("Client ajouté.\n" "Click Cancel to exit."), QMessageBox::Cancel);

        }
          else
          {
              QMessageBox::critical(nullptr, QObject::tr("Ajouter un Client"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
          }
    //tabmodif
    Connection c;
    model = new QSqlTableModel(this);
    model = tmpevent.moodel();
    ui->tablemodifier->setModel(model);
    //Combo
    ui->comboBox->setModel(tmpevent.remplircomboevent());

}


void EvenementInter::on_SupprimerBouton_clicked()
{
    QMessageBox::StandardButton reply =QMessageBox::question(this,
                          "Supprimer","Voulez-vous vraiment supprimer ?",
                          QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        bool test=tmpevent.supprimer(ui->comboBox->currentText().toInt());
        if(test)
        {
            //refresh
            //tabmodif
            Connection c;
            model = new QSqlTableModel(this);
            model = tmpevent.moodel();
            ui->tablemodifier->setModel(model);
            //Combo
            ui->comboBox->setModel(tmpevent.remplircomboevent());
            ui->comboBox_modif->setModel(tmpevent.remplircomboevent());

            //message
            QMessageBox::information(this, QObject::tr("Supprimer un Evenement"),
                        QObject::tr("Evenement supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::critical(this, QObject::tr("Supprimer un Evenement"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }

    }

}

void EvenementInter::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QSqlQuery query;

    QString id = ui->comboBox->currentText();

    query =tmpevent.request(id);
    if(query.exec())
    {
        while(query.next())
        {
            ui->Nomval->setText(query.value(1).toString());
            ui->Descriptionval->setText(query.value(2).toString());
            ui->Dateeventval->setText(query.value(3).toString());
        }
    }

}

void EvenementInter::on_comboBox_modif_currentIndexChanged(const QString &arg1)
{
    QSqlQuery query;

    QString id = ui->comboBox_modif->currentText();

    query =tmpevent.request(id);
    if(query.exec())
    {
        while(query.next())
        {
            ui->nommodif->setText(query.value(1).toString());
            ui->descmodif->setText(query.value(2).toString());
            ui->datemodif->setDate(query.value(3).toDate());
        }
    }

}


void EvenementInter::on_modifiebtn_clicked()
{
    if((ui->nommodif->text() != "") &&(ui->descmodif->text() != ""))
    {
        if(tmpevent.modifier(ui->nommodif->text(),ui->descmodif->text(),ui->datemodif->date(),ui->comboBox_modif->currentText()))
        {
            //refresh
            //tabmodif
            Connection c;
            model = new QSqlTableModel(this);
            model = tmpevent.moodel();
            ui->tablemodifier->setModel(model);
            //Combo
            ui->comboBox->setModel(tmpevent.remplircomboevent());
            ui->comboBox_modif->setModel(tmpevent.remplircomboevent());

        }
        else
        {

        }
    }
}


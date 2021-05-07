#include "contactui.h"
#include "ui_contactui.h"
#include "activite.h"
#include "connection.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QIntValidator>
#include <QString>
#include <QWidget>
#include <QPainter>
#include <QPdfWriter>
#include <QApplication>
#include <QMessageBox>
#include <QPainter>
#include <QPdfWriter>
#include <QUrl>
#include <QDebug>
#include <QTextBrowser>
#include <QFileDialog>
#include <QTextBlock>
#include <cstdlib>
#include <QDate>
#include<iostream>
#include <QTimer>
#include <QDateTime>
#include <QDate>
#include <QtPrintSupport/QPrintDialog>
#include <QDesktopServices>
#include <QPrinter>
#include <QPrintPreviewDialog>
#include<QDebug>
#include<QValidator>
#include "smtp.h"
#include"tableprinter.h"
#include<QFileDialog>

ContactUI::ContactUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContactUI)
{
    ui->setupUi(this);

    setWindowTitle("Gestion de contact");

    //Column size
    ui->tablemodifier->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tablemodifier_act->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tablemodifier->setModel(contactTmp.afficher());

    ui->comboBox->setModel(contactTmp.remplircombocontact());
    ui->comboBox_modif->setModel(contactTmp.remplircombocontact());
    ui->comboBox_2->setModel(contactTmp.remplircombocontact());

    ui->comboBox_act->setModel(activiteTmp.remplircomboactivity());
    ui->comboBox_modif_act->setModel(activiteTmp.remplircomboactivity());

    //remplir combobox tri ADMIN
    QStringList list_tri_activite;
    list_tri_activite << "" << "NOM" << "TYPE" ;
    ui->comboBox_tri->addItems(list_tri_activite);

    QStringList list_tri_contact;
    list_tri_contact << "" << "NOM" << "ADRESSE" << "NUMTEL" << "EMAIL" ;
    ui->comboBox_tri_contact->addItems(list_tri_contact);
    refresh();

}

ContactUI::~ContactUI()
{
    delete ui;
}

void ContactUI::on_AjouterBouton_clicked()
{
    Contact con(ui->Nom->toPlainText(),ui->adresse->toPlainText(),ui->numtel->toPlainText(),ui->email->toPlainText());
    bool test = con.ajouter();
    if(test)
{
        QMessageBox::information(nullptr, QObject::tr("Ajouter un contact"),
        QObject::tr("Contact ajouté.\n" "Click Cancel to exit."), QMessageBox::Cancel);

        }
          else
          {
              QMessageBox::critical(nullptr, QObject::tr("Ajouter un contact"),
                          QObject::tr("Erreur !.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
          }
    ui->tablemodifier->setModel(contactTmp.afficher());
    //Combo
    ui->comboBox->setModel(contactTmp.remplircombocontact());
    ui->comboBox_modif->setModel(contactTmp.remplircombocontact());
    ui->comboBox_2->setModel(contactTmp.remplircombocontact());

}

void ContactUI::on_modifiebtn_clicked()
{
    if((ui->nommodif->text() != "") &&(ui->adressemodif->text() != "")&&(ui->numTelmodif->text() !="")&&(ui->emailmodif->text() != ""))
    {
        if(contactTmp.modifier(ui->nommodif->text(),ui->adressemodif->text(),ui->numTelmodif->text(),ui->emailmodif->text(),ui->comboBox_modif->currentText()))
        {
            //refresh
            ui->tablemodifier->setModel(contactTmp.afficher());
            //Combo
            ui->comboBox->setModel(contactTmp.remplircombocontact());
            ui->comboBox_modif->setModel(contactTmp.remplircombocontact());

        }
        else
        {

        }
    }
}

void ContactUI::on_SupprimerBouton_clicked()
{
    QMessageBox::StandardButton reply =QMessageBox::question(this,
                          "Supprimer","Voulez-vous vraiment supprimer ?",
                          QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        bool test=contactTmp.supprimer(ui->comboBox->currentText().toInt());
        if(test)
        {
            //refresh
            ui->tablemodifier->setModel(contactTmp.afficher());
            //Combo
            ui->comboBox->setModel(contactTmp.remplircombocontact());
            ui->comboBox_modif->setModel(contactTmp.remplircombocontact());

            //message
            QMessageBox::information(this, QObject::tr("Supprimer un contact"),
                        QObject::tr("Activité supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::critical(this, QObject::tr("Supprimer un contact"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }

    }
}

void ContactUI::on_comboBox_modif_currentIndexChanged(const QString &arg1)
{
    QSqlQuery query;

    QString id = ui->comboBox_modif->currentText();

    query =contactTmp.request(id);
    if(query.exec())
    {
        while(query.next())
        {
            ui->nommodif->setText(query.value(1).toString());
            ui->adressemodif->setText(query.value(2).toString());
            ui->numTelmodif->setText(query.value(3).toString());
            ui->emailmodif->setText(query.value(4).toString());

        }
    }
}

void ContactUI::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QSqlQuery query;

    QString id = ui->comboBox->currentText();

    query =contactTmp.request(id);
    if(query.exec())
    {
        while(query.next())
        {
            ui->Nomval->setText(query.value(1).toString());
            ui->adresseval->setText(query.value(2).toString());
            ui->numtelval->setText(query.value(3).toString());
            ui->emailval->setText(query.value(4).toString());

        }
    }
}

void ContactUI::on_rechercheButton_clicked()
{
    Contact *c = new Contact();
                ui->tablemodifier->setModel(c->recherche_contact(ui->recherche_contact->text()));
}

void ContactUI::on_trier_Button_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel;
           QSqlQuery *qry=new QSqlQuery();

           qry->prepare("select * from CONTACT ORDER BY NOM");
           qry->exec();
            modal->setQuery(*qry);
            ui->tablemodifier->setModel(modal);
}
void ContactUI::sendMail()
{
    Smtp* smtp = new Smtp("mhimdi.raslen@esprit.tn", "191JMT3304", "smtp.gmail.com", 465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail("mhimdi.raslen@esprit.tn", ui->email_2->text() , ui->objet->text(),ui->message->toPlainText());
}

void ContactUI::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

void ContactUI::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    QSqlQuery query;

    QString id = ui->comboBox_modif->currentText();

    query =contactTmp.request(id);
    if(query.exec())
    {
        while(query.next())
        {
            ui->nomLabel->setText(query.value(1).toString());

            ui->email_2->setText(query.value(4).toString());

        }
    }
}



void ContactUI::on_envoyer_clicked()
{
    sendMail();

}
void ContactUI::print(QPrinter *printer)
{
    QPainter painter;
        if(!painter.begin(printer)) {
            qWarning() << "can't start printer";
            return;
        }
        // print table
        TablePrinter tablePrinter(&painter, printer);
        QVector<int> columnStretch = QVector<int>() << 10 << 15 << 20  <<25;
        if(!tablePrinter.printTable(ui->tablemodifier->model(), columnStretch)) {
            qDebug() << tablePrinter.lastError();
        }
        // print second table
        painter.translate(0, 100);
        if(!tablePrinter.printTable(ui->tablemodifier->model(), columnStretch)) {
            qDebug() << tablePrinter.lastError();
        }
        painter.end();
}

//PDF


void ContactUI::on_imprimer_clicked()
{
    //QSound::play(":/new/prefix1/sond/Click button.wav");

       QString strStream;
                  QTextStream out(&strStream);
                  const int rowCount = ui->tablemodifier->model()->rowCount();
                  const int columnCount =ui->tablemodifier->model()->columnCount();

                  out <<  "<html>\n"
                          "<head>\n"
                          "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                          <<  QString("<title>%1</title>\n").arg("eleve")
                          <<  "</head>\n"
                          "<body bgcolor=#F4B8B8 link=#5000A0>\n"
                             // "<img src='C:/Users/ksemt/Desktop/final/icon/logo.webp' width='20' height='20'>\n"
                              "<img src='C:/Users/DeLL/Desktop/logooo.png' width='100' height='100'>\n"
                              "<h1>   Nos contacts </h1>"
                               "<h1>  </h1>"

                              "<table border=1 cellspacing=0 cellpadding=2>\n";


                  // headers
                      out << "<thead><tr bgcolor=#f0f0f0>";
                      for (int column = 0; column < columnCount; column++)
                          if (!ui->tablemodifier->isColumnHidden(column))
                              out << QString("<th>%1</th>").arg(ui->tablemodifier->model()->headerData(column, Qt::Horizontal).toString());
                      out << "</tr></thead>\n";
                      // data table
                         for (int row = 0; row < rowCount; row++) {
                             out << "<tr>";
                             for (int column = 0; column < columnCount; column++) {
                                 if (!ui->tablemodifier->isColumnHidden(column)) {
                                     QString data = ui->tablemodifier->model()->data(ui->tablemodifier->model()->index(row, column)).toString().simplified();
                                     out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                 }
                             }
                             out << "</tr>\n";
                         }
                         out <<  "</table>\n"
                             "</body>\n"
                             "</html>\n";

                         QTextDocument *document = new QTextDocument();
                         document->setHtml(strStream);

                         QPrinter printer;

                         QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                         if (dialog->exec() == QDialog::Accepted) {
                             document->print(&printer);
                      }
}

void ContactUI::on_recherche_contact_cursorPositionChanged(int arg1, int arg2)
{
    ui->tablemodifier->setModel(contactTmp.recherche_contact(ui->recherche_contact->text()));

    QString test =ui->recherche_contact->text();

    if(test=="")
    {
        ui->tablemodifier->setModel(contactTmp.afficher());//refresh
    }

}

void ContactUI::on_comboBox_tri_contact_currentIndexChanged(const QString &arg1)
{
    if(!(ui->comboBox_tri_contact->currentText()==""))
    {
        ui->tablemodifier->setModel(contactTmp.triafficher(ui->comboBox_tri_contact->currentText()));
    }

}

void ContactUI::on_comboBox_tri_contact_activated(const QString &arg1)
{
    if(!(ui->comboBox_tri->currentText()==""))
    {
        ui->tablemodifier->setModel(contactTmp.triafficher(ui->comboBox_tri_contact->currentText()));
    }

}

void ContactUI::refresh()
{
    //refresh
    ui->tablemodifier_act->setModel(activiteTmp.afficher());

    ui->comboBox_act->setModel(activiteTmp.remplircomboactivity());
    ui->comboBox_modif_act->setModel(activiteTmp.remplircomboactivity());

}

void ContactUI::on_AjouterBouton_3_clicked()
{
    Activite act(ui->Nom_act->toPlainText(),ui->type->toPlainText(),ui->dateDebut->date(),ui->dateFin->date());
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

void ContactUI::on_comboBox_modif_act_currentIndexChanged(const QString &arg1)
{
    QSqlQuery query;

    QString id = ui->comboBox_modif_act->currentText();

    query =activiteTmp.request(id);
    if(query.exec())
    {
        while(query.next())
        {
            ui->nommodif_act->setText(query.value(1).toString());
            ui->typemodif->setText(query.value(2).toString());
            ui->dateDebutmodif->setDate(query.value(3).toDate());
            ui->dateFinmodif->setDate(query.value(4).toDate());

        }
    }


}

void ContactUI::on_modifiebtn_3_clicked()
{
    if((ui->nommodif_act->text() != "") &&(ui->typemodif->text() != ""))
    {
        if(activiteTmp.modifier(ui->nommodif_act->text(),ui->typemodif->text(),ui->dateDebutmodif->date(),ui->dateFinmodif->date(),ui->comboBox_modif_act->currentText()))
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

void ContactUI::on_comboBox_act_currentIndexChanged(const QString &arg1)
{
    QSqlQuery query;

    QString id = ui->comboBox_act->currentText();

    query =activiteTmp.request(id);
    if(query.exec())
    {
        while(query.next())
        {
            ui->Nomval_act->setText(query.value(1).toString());
            ui->typeval->setText(query.value(2).toString());
            ui->Datedebutval->setText(query.value(3).toString());
            ui->Datefinval->setText(query.value(4).toString());

        }
    }

}

void ContactUI::on_SupprimerBouton_3_clicked()
{
    QMessageBox::StandardButton reply =QMessageBox::question(this,
                          "Supprimer","Voulez-vous vraiment supprimer ?",
                          QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        bool test=activiteTmp.supprimer(ui->comboBox_act->currentText().toInt());
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

void ContactUI::on_recherche_cursorPositionChanged(int arg1, int arg2)
{
    ui->tablemodifier_act->setModel(activiteTmp.recherche_activite(ui->recherche->text()));

    QString test =ui->recherche->text();

    if(test=="")
    {
        ui->tablemodifier_act->setModel(activiteTmp.afficher());//refresh
    }

}

void ContactUI::on_comboBox_tri_currentIndexChanged(const QString &arg1)
{
    if(!(ui->comboBox_tri->currentText()==""))
    {
        ui->tablemodifier_act->setModel(activiteTmp.triafficher(ui->comboBox_tri->currentText()));
    }

}

/*void ContactUI::on_Excel_contact_clicked()
{
    QTableView *table;
               table = ui->Excels;

               QString filters("CSV files (.csv);;All files (.*)");
               QString defaultFilter("CSV files (*.csv)");
               QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                  filters, &defaultFilter);
               QFile file(fileName);

               QAbstractItemModel *model = table->model();
               if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                   QTextStream data(&file);
                   QStringList strList;
                   for (int i = 0; i < model->columnCount(); i++) {
                       if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                           strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                       else
                           strList.append("");
                   }
                   data << strList.join(";") << "\n";
                   for (int i = 0; i < model->rowCount(); i++) {
                       strList.clear();
                       for (int j = 0; j < model->columnCount(); j++) {

                           if (model->data(model->index(i, j)).toString().length() > 0)
                               strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                           else
                               strList.append("");
                       }
                       data << strList.join(";") + "\n";
                   }
                   file.close();
                   QMessageBox::information(this,"Exporter To Excel","Exporter En Excel Avec Succées ");
               }
}
*/

void ContactUI::on_Excels_clicked()
{
    QTableView *table;
               table = ui->tablemodifier_act;

               QString filters("CSV files (.csv);;All files (.*)");
               QString defaultFilter("CSV files (*.csv)");
               QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                  filters, &defaultFilter);
               QFile file(fileName);

               QAbstractItemModel *model = table->model();
               if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                   QTextStream data(&file);
                   QStringList strList;
                   for (int i = 0; i < model->columnCount(); i++) {
                       if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                           strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                       else
                           strList.append("");
                   }
                   data << strList.join(";") << "\n";
                   for (int i = 0; i < model->rowCount(); i++) {
                       strList.clear();
                       for (int j = 0; j < model->columnCount(); j++) {

                           if (model->data(model->index(i, j)).toString().length() > 0)
                               strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                           else
                               strList.append("");
                       }
                       data << strList.join(";") + "\n";
                   }
                   file.close();
                   QMessageBox::information(this,"Exporter To Excel","Exporter En Excel Avec Succées ");
               }
}

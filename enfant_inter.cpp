#include "enfant_inter.h"
#include "ui_enfant_inter.h"
#include "site.h"
#include <QString>
#include <QMessageBox>
#include <QTextDocument>
#include <QDebug>
#include <QIntValidator>
#include <QFile>
#include <QTextStream>
#include <excel.h>

Enfant_Inter::Enfant_Inter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Enfant_Inter)
{
    ui->setupUi(this);
    ui->tab_chambre->setModel(C.afficher());
        ui->tab_lampe->setModel(l.afficher());
         ui->tab_archive->setModel(l.afficherAR());
        QFile file1("C:/Users/Bayoudh Mohamed/Desktop/Projet2A/don.txt");

            file1.close();
        if (!file1.open(QIODevice::ReadOnly))
        {        QMessageBox::information(0,"info",file1.errorString());    }
         QTextStream cin (&file1);
        ui->label_9->setText(cin.readAll()+" DT");

        ui->notes->hide();
        ui->btn_notes->hide();
            ui->tab_chambre->setModel(C.afficher());
            ui->tab_lampe->setModel(l.afficher());
    QIntValidator *roll = new QIntValidator(100000,999999);
   // ui->line_num->setValidator(new QIntValidator(0,9999999,this));
    ui->line_num->setValidator(roll);
    ui->line_num_2->setValidator(roll);
    ui->tab_chambre->setModel(C.afficher());
    ui->tableView->setModel(C.stat());
    ui->tab_lampe->setModel(l.afficher());
    QFile file("C:/Users/Bayoudh Mohamed/Desktop/Projet2A/Historique.txt");

   if (!file.open(QIODevice::ReadOnly))
   {
       QMessageBox::information(0,"info",file.errorString());
   }
   QTextStream in (&file);
  ui->textBrowser->setText(in.readAll());
}

Enfant_Inter::~Enfant_Inter()
{
    delete ui;
}

void Enfant_Inter::on_btn_ajout_clicked()
{

    int id_site=ui->line_num->text().toInt();
        QString lien=ui->line_eclair->text();
        QString description=ui->line_etat->text();
        site C(id_site,lien,description);


        if(C.ajouter())
        {
            ui->line_num->setText("");
            ui->line_eclair->setText("");
            ui->line_etat->setText("");


            QMessageBox::information(nullptr, QObject::tr("Ajouter un site"),
                               QObject::tr("Ajout avec succès !.\n"
                                           "Click Close to exit."), QMessageBox::Close);

            //mettre à jour mon affichage après ajout:
            ui->tab_chambre->setModel(C.afficher());


            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("Ajouter un site"),
                                   QObject::tr("Erreur l'id existe deja!.\n"
                                               "Click Close to exit."), QMessageBox::Close);
            }
    }


void Enfant_Inter::on_btn_supp_clicked()
{
    site C1;
    int row=ui->tab_chambre->selectionModel()->currentIndex().row();
      C1.set_id_site(ui->tab_chambre->model()->index(row,0).data().toInt());
      bool test=C1.supprimer(C1.get_id_site());

      QMessageBox msgBox;

      if(test)
      {
          msgBox.setText("Suppression avec succès.");


          //Mettre à jour mon affichage après suppression:
          ui->tab_chambre->setModel(C.afficher());

          }
    else
      {
         msgBox.setText("Echec de la suppression!");
      }

        msgBox.exec();
}

void Enfant_Inter::on_pushButton_2_clicked()
{
    int id=ui->lineEdit->text().toInt();
    ui->tab_chambre->setModel(C.chercher(id)); //rechercher
}

void Enfant_Inter::on_pushButton_clicked()
{
    int     id_site=ui->line_num->text().toInt();
    QString lien=ui->line_eclair->text();
        QString description=ui->line_etat->text();
        site C(id_site,lien,description);


        if(C.modifier(id_site))
            {
            ui->line_num->setText("");
            ui->line_eclair->setText("");
            ui->line_etat->setText("");


            QMessageBox::information(nullptr, QObject::tr("modifier un site"),
                               QObject::tr("modification avec succès !.\n"
                                           "Click Close to exit."), QMessageBox::Close);

            //mettre à jour mon affichage après ajout:
            ui->tab_chambre->setModel(C.afficher());


            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("modifier un site"),
                                   QObject::tr("Erreur l'id existe deja!.\n"
                                               "Click Close to exit."), QMessageBox::Close);
            }

}

void Enfant_Inter::on_pushButton_3_clicked()
{
    QString selon=ui->comboBox->currentText();
     ui->tab_chambre->setModel(C.trier(selon));
}

void Enfant_Inter::on_pushButton_4_clicked()
{
    QString strStream;
                       QTextStream out(&strStream);

                        const int rowCount = ui->tab_chambre->model()->rowCount();
                        const int columnCount = ui->tab_chambre->model()->columnCount();
                       out <<  "<html>\n"
                       "<head>\n"
                                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                        <<  QString("<title>%1</title>\n").arg("strTitle")
                                        <<  "</head>\n"
                                        "<body bgcolor=#ffffff link=#5000A0>\n"

                                       //     "<align='right'> " << datefich << "</align>"
                                        "<center> <H1>Liste des sites</H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                                    // headers
                                    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                                    out<<"<cellspacing=10 cellpadding=3>";
                                    for (int column = 0; column < columnCount; column++)
                                        if (!ui->tab_chambre->isColumnHidden(column))
                                            out << QString("<th>%1</th>").arg(ui->tab_chambre->model()->headerData(column, Qt::Horizontal).toString());
                                    out << "</tr></thead>\n";

                                    // data table
                                    for (int row = 0; row < rowCount; row++) {
                                        out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                        for (int column = 0; column < columnCount; column++) {
                                            if (!ui->tab_chambre->isColumnHidden(column)) {
                                                QString data = ui->tab_chambre->model()->data(ui->tab_chambre->model()->index(row, column)).toString().simplified();
                                                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                            }
                                        }
                                        out << "</tr>\n";
                                    }
                                    out <<  "</table> </center>\n"
                                        "</body>\n"
                                        "</html>\n";

                              QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                                if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                               QPrinter printer (QPrinter::PrinterResolution);
                                printer.setOutputFormat(QPrinter::PdfFormat);

                              printer.setOutputFileName(fileName);

                               QTextDocument doc;
                                doc.setHtml(strStream);

                                doc.print(&printer);
}

void Enfant_Inter::on_btn_ajout_2_clicked()
{
    int id_enf=ui->line_num_2->text().toInt();
    QString nom=ui->line_etat_2->text();
    QString prenom=ui->line_prenom->text();
    int     age=ui->line_age->text().toInt();
    enfant l(id_enf,nom,prenom,age);
     QFile file("C:/Users/Bayoudh Mohamed/Desktop/Projet2A/Historique.txt");
     if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
         return;

     QTextStream cout(&file);
//enfant l(69,"nermin","fatatich",200);

        if(l.ajouter())
            {

            QString message2="\nVous avez ajouté un enfant ";
                cout << message2;
                QFile file("C:/Users/Bayoudh Mohamed/Desktop/Projet2A/Historique.txt");
               if (!file.open(QIODevice::ReadOnly))
               {
                   QMessageBox::information(0,"info",file.errorString());
               }
               QTextStream in (&file);
              ui->textBrowser->setText(in.readAll());

            ui->line_num_2->setText("");
            ui->line_etat_2->setText("");
            ui->line_age->setText("");
            ui->line_prenom->setText("");

            QMessageBox::information(nullptr, QObject::tr("Ajouter une enfant"),
                               QObject::tr("Ajout avec succès !.\n"
                                           "Click Close to exit."), QMessageBox::Close);

            //mettre à jour mon affichage après ajout:
            ui->tab_lampe->setModel(l.afficher());


            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("Ajouter une enfant"),
                                   QObject::tr("Erreur l'id existe deja!.\n"
                                               "Click Close to exit."), QMessageBox::Close);
            }

}

void Enfant_Inter::on_btn_supp_2_clicked()
{
    enfant l1;
    int row=ui->tab_lampe->selectionModel()->currentIndex().row();
    int id_enf=ui->tab_lampe->model()->index(row,0).data().toInt();
    bool test=l1.supprimer(id_enf);
    QFile file("C:/Users/Bayoudh Mohamed/Desktop/Projet2A/Historique.txt");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        return;

    QTextStream cout(&file);
    QMessageBox msgBox;


     // QMessageBox msgBox;

      if(test)
      {
         // msgBox.setText("Suppression avec succès.");

          QString message2="\nVous avez supprimé un enfant";
              cout << message2;
              QFile file("C:/Users/Bayoudh Mohamed/Desktop/Projet2A/Historique.txt");
             if (!file.open(QIODevice::ReadOnly))
             {
                 QMessageBox::information(0,"info",file.errorString());
             }
             QTextStream in (&file);
            ui->textBrowser->setText(in.readAll());
      msgBox.setText("Suppression avec succès.");


          //Mettre à jour mon affichage après suppression:
          ui->tab_lampe->setModel(l1.afficher());

          }
    else
      {
         msgBox.setText("Echec de la suppression!");
      }

        msgBox.exec();

}

void Enfant_Inter::on_pushButton_6_clicked()
{
    int id_enf=ui->lineEdit_2->text().toInt();
    ui->tab_lampe->setModel(l.chercher(id_enf));
}

void Enfant_Inter::on_pushButton_8_clicked()
{
    QString strStream;
                       QTextStream out(&strStream);

                        const int rowCount = ui->tab_lampe->model()->rowCount();
                        const int columnCount = ui->tab_lampe->model()->columnCount();
                       out <<  "<html>\n"
                       "<head>\n"
                                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                        <<  QString("<title>%1</title>\n").arg("strTitle")
                                        <<  "</head>\n"
                                        "<body bgcolor=#ffffff link=#5000A0>\n"

                                       //     "<align='right'> " << datefich << "</align>"
                                        "<center> <H1>Liste des enfants</H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                                    // headers
                                    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                                    out<<"<cellspacing=10 cellpadding=3>";
                                    for (int column = 0; column < columnCount; column++)
                                        if (!ui->tab_lampe->isColumnHidden(column))
                                            out << QString("<th>%1</th>").arg(ui->tab_lampe->model()->headerData(column, Qt::Horizontal).toString());
                                    out << "</tr></thead>\n";

                                    // data table
                                    for (int row = 0; row < rowCount; row++) {
                                        out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                        for (int column = 0; column < columnCount; column++) {
                                            if (!ui->tab_lampe->isColumnHidden(column)) {
                                                QString data = ui->tab_lampe->model()->data(ui->tab_lampe->model()->index(row, column)).toString().simplified();
                                                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                            }
                                        }
                                        out << "</tr>\n";
                                    }
                                    out <<  "</table> </center>\n"
                                        "</body>\n"
                                        "</html>\n";

                              QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                                if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                               QPrinter printer (QPrinter::PrinterResolution);
                                printer.setOutputFormat(QPrinter::PdfFormat);

                              printer.setOutputFileName(fileName);

                               QTextDocument doc;
                                doc.setHtml(strStream);

                                doc.print(&printer);
}

void Enfant_Inter::on_pushButton_7_clicked()
{
    int row=ui->tab_lampe->selectionModel()->currentIndex().row();
      int id=ui->tab_lampe->model()->index(row,0).data().toInt();
      QString res=QString::number(id);
    ui->tabWidget_3->setCurrentIndex(0);
    ui->line_num_2->setText(res);
}

void Enfant_Inter::on_pushButton_5_clicked()
{
    int id=ui->line_num_2->text().toInt();
        QString nom=ui->line_etat_2->text();
        QString prenom=ui->line_prenom->text();
        int age = ui->line_age->text().toInt();

        enfant l(id,nom,prenom,age);
        QFile file("C:/Users/Bayoudh Mohamed/Desktop/Projet2A/Historique.txt");
        if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
            return;

        QTextStream cout(&file);

        if(l.modifier(id))
            {

            QString message2="\nVous avez modifié un enfant";
                cout << message2;
                QFile file("C:/Users/Bayoudh Mohamed/Desktop/Projet2A/Historique.txt");
               if (!file.open(QIODevice::ReadOnly))
               {
                   QMessageBox::information(0,"info",file.errorString());
               }
               QTextStream in (&file);
              ui->textBrowser->setText(in.readAll());
            ui->line_num_2->setText("");
            ui->line_etat_2->setText("");
            ui->line_prenom->setText("");
            ui->line_age->setText("");

            QMessageBox::information(nullptr, QObject::tr("Modifier enfant"),
                               QObject::tr("modification avec succès !.\n"
                                           "Click Close to exit."), QMessageBox::Close);

            //mettre à jour mon affichage après ajout:
            ui->tab_lampe->setModel(l.afficher());


            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("Modifier enfant"),
                                   QObject::tr("Erreur!.\n"
                                               "Click Close to exit."), QMessageBox::Close);
            }


}

void Enfant_Inter::on_pushButton_9_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Exportation en fichier Excel"), qApp->applicationDirPath (),
                                                                tr("Fichiers d'extension Excel (*.xls)"));
                if (fileName.isEmpty())
                    return;

                ExportExcelObject obj(fileName, "mydata", ui->tab_lampe);

                // you can change the column order and
                // choose which colum to export
                obj.addField(0, "ID", "char(20)");
                obj.addField(1, "NOM", "char(20)");
                obj.addField(2, "PRENOM", "char(20)");
                obj.addField(3, "AGE", "char(20)");


                int retVal = obj.export2Excel();

                if( retVal > 0)
                {
                    QMessageBox::information(this, tr("FAIS!"),
                                             QString(tr("%1 enregistrements exportés!")).arg(retVal)
                                             );
                }
}

void Enfant_Inter::on_btn_notes_clicked()
{

    QFile file("C:/Users/Bayoudh Mohamed/Desktop/Projet2A/Historique.txt");
            if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                return;

            QTextStream cout(&file);
            QString message2="-"+ui->notes->toPlainText()+"\n";
                    cout << message2;
                    ui->notes->hide();
                    ui->btn_notes->hide();
}
void Enfant_Inter::on_btn_ajout_notes_clicked()
{
    ui->notes->show();
        ui->btn_notes->show();
}

void Enfant_Inter::on_pushButton_10_clicked()
{
    QFile file("C:/Users/Bayoudh Mohamed/Desktop/Projet2A/don.txt");


        file.close();

        if (!file.open(QIODevice::ReadOnly))
          {        QMessageBox::information(0,"info",file.errorString());    }
          QTextStream in (&file);
           QString a=in.readAll();
           int k,l,s;
           k=a.toInt();
           QString message2=""+ui->lineEdit_3->text()+"";
           l=message2.toInt();
           s=k+l;
           QString aux=QString::number(s);
           file.close();
           if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
               return;
           QTextStream out(&file);
           out << aux;
           file.close();
           if (!file.open(QIODevice::ReadOnly))
           {        QMessageBox::information(0,"info",file.errorString());    }
           ui->label_9->setText(in.readAll()+" DT");
           QMessageBox::information(nullptr, QObject::tr("Don"),
                                            QObject::tr("Don effectué.\n"
                                                        "Click Cancel to exit."), QMessageBox::Cancel);

}

void Enfant_Inter::on_pushButton_11_clicked()
{
    ui->tab_chambre->setModel(C.afficher());
}

void Enfant_Inter::on_pushButton_13_clicked()
{
    int row=ui->tab_lampe->selectionModel()->currentIndex().row();
        int id=ui->tab_lampe->model()->index(row,0).data().toInt();
        l.archiver(id);
    ui->tab_lampe->setModel(l.afficher());
    ui->tab_archive->setModel(l.afficherAR());
}

void Enfant_Inter::on_pushButton_12_clicked()
{
    int row=ui->tab_archive->selectionModel()->currentIndex().row();
        int id=ui->tab_archive->model()->index(row,0).data().toInt();
        l.recuperer(id);
    ui->tab_lampe->setModel(l.afficher());
    ui->tab_archive->setModel(l.afficherAR());
}

void Enfant_Inter::on_pushButton_14_clicked()
{
     ui->tab_lampe->setModel(l.afficher());
}

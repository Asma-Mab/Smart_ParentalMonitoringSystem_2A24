#include "equipement.h"
#include "ui_equipement.h"
#include <QMessageBox>
#include <QTextStream>
#include <QFileInfo>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QPixmap>
#include <QPieSeries>
#include <QtCharts>
#include <QChartView>
#include <QSystemTrayIcon>

Equipement::Equipement(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Equipement)
{
    ui->setupUi(this);
    QIntValidator *roll = new QIntValidator(100000,999999);//controle de saisie
       ui->lineEdit->setValidator(roll);
       ui->lineEdit_7->setValidator(roll);
       ui->lineEdit_14->setValidator(roll);//controle de saisie


    QPieSeries *series = new QPieSeries();//stat
       QSqlQuery q("select type,count(*) from machine group by type");


        while(q.next())
        {series->append(q.value(0).toString()+": "+q.value(1).toString(),q.value(1).toInt());}
       QChart *chart = new QChart();
       chart->addSeries(series);
       chart->setTitle("Statistiques");
       chart->setBackgroundBrush(Qt::transparent);
       QChartView *chartview = new QChartView(chart);
       chartview->setRenderHint(QPainter::Antialiasing);
       chartview->setParent(ui->horizontalFrame);
       chartview->resize(400,300);

       chart->setAnimationOptions(QChart::AllAnimations);
       chart->legend()->setVisible(true);
       chart->legend()->setAlignment(Qt::AlignRight);
       series->setLabelsVisible(true);//stat

    ui->tableView->setModel(tmpm.afficher());
    ui->tableView_2->setModel(tmpt.afficher());
    QPixmap pix("C:/Users/Kraiem Nathir/Desktop/Webp.net-resizeimage.jpg");
    ui->label_13->setPixmap(pix);

}

Equipement::~Equipement()
{
    delete ui;
}


void Equipement::on_pushButton_2_clicked()
{

    int id=ui->lineEdit->text().toInt();
    QString type=ui->lineEdit_2->text();
    QString nom=ui->lineEdit_3->text();
    QString description=ui->lineEdit_4->text();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    machine m(id,type,nom,description);
    bool test=m.ajouter();
    if(test)
    { ui->tableView->setModel(tmpm.afficher());
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                                notifier->show();
                                notifier->showMessage("machine ajouté","Succés",QSystemTrayIcon::Information,10000);

}
    else
    {
        ui->tableView->setModel(tmpm.afficher());
               QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                                       notifier->show();
                                       notifier->showMessage("machine non ajouté","Echec",QSystemTrayIcon::Critical,10000);
    }

}

void Equipement::on_pushButton_3_clicked()
{
    int row=ui->tableView->selectionModel()->currentIndex().row();
      int id=ui->tableView->model()->index(row,0).data().toInt();

    tmpm.supprimer(id);
    ui->tableView->setModel(tmpm.afficher());

}

void Equipement::on_pushButton_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    int id=ui->lineEdit->text().toInt();
    QString type=ui->lineEdit_2->text();
    QString nom=ui->lineEdit_3->text();
    QString description=ui->lineEdit_4->text();
    machine m(id,type,nom,description);
    bool test=m.modifier(id);
    if(test)
    { ui->tableView->setModel(tmpm.afficher());
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                                notifier->show();
                                notifier->showMessage("machine modifié","Succés",QSystemTrayIcon::Information,10000);

}
    else
    {
        ui->tableView->setModel(tmpm.afficher());
               QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                                       notifier->show();
                                       notifier->showMessage("machine non modifié","Echec",QSystemTrayIcon::Critical,10000);
    }

}

void Equipement::on_pushButton_4_clicked()
{
    QString selon=ui->comboBox_2->currentText();
    ui->tableView->setModel(tmpm.tri(selon));
}

void Equipement::on_pushButton_5_clicked()
{
    QString rech=ui->lineEdit_6->text();
    QString selon=ui->comboBox->currentText();
    ui->tableView->setModel(tmpm.afficherRech(selon,rech));
    //ui->tableView->setModel(tmpm.afficher());
}

void Equipement::on_pushButton_6_clicked()
{
     ui->tableView->setModel(tmpm.afficher());
}

void Equipement::on_pushButton_8_clicked()
{
    int id=ui->lineEdit_7->text().toInt();
    QString type=ui->lineEdit_8->text();
    QString nom=ui->lineEdit_9->text();
    QString description=ui->lineEdit_10->text();
    QString date=ui->dateEdit->text();
    QString heure_d=ui->lineEdit_13->text();
    QString heure_f=ui->lineEdit_15->text();
    int id_m=ui->lineEdit_14->text().toInt();
        ui->lineEdit_7->clear();
        ui->lineEdit_8->clear();
        ui->lineEdit_9->clear();
        ui->lineEdit_10->clear();
        ui->lineEdit_13->clear();
        ui->lineEdit_15->clear();
        ui->lineEdit_14->clear();
    tache t(id,type,nom,description,date,heure_d,heure_f,id_m);
    bool test=t.ajouter();
    if(test)
    { ui->tableView->setModel(tmpm.afficher());
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);//notification f kol wahd amawjouda ajouter / supprimer...44
                                notifier->show();
                                notifier->showMessage("tache ajouté","Succés",QSystemTrayIcon::Information,10000);//notification

}
    else
    {
        ui->tableView->setModel(tmpm.afficher());
               QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                                       notifier->show();
                                       notifier->showMessage("tache non ajouté","Echec",QSystemTrayIcon::Critical,10000);
    }

}

void Equipement::on_pushButton_7_clicked()
{
    int id=ui->lineEdit_7->text().toInt();
    QString type=ui->lineEdit_8->text();
    QString nom=ui->lineEdit_9->text();
    QString description=ui->lineEdit_10->text();
    QString date=ui->dateEdit->text();
    QString heure_d=ui->lineEdit_13->text();
    QString heure_f=ui->lineEdit_15->text();
    int id_m=ui->lineEdit_14->text().toInt();
    tache t(id,type,nom,description,date,heure_d,heure_f,id_m);
    bool test=t.modifier(id);
    if(test)
    {ui->tableView->setModel(tmpm.afficher());
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                                notifier->show();
                                notifier->showMessage("tache madifié","Succés",QSystemTrayIcon::Information,10000);

}
    else
    {
        ui->tableView->setModel(tmpm.afficher());
               QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                                       notifier->show();
                                       notifier->showMessage("tache non modifié","Echec",QSystemTrayIcon::Critical,10000);
    }

}

void Equipement::on_pushButton_9_clicked()
{
    int row=ui->tableView_2->selectionModel()->currentIndex().row();
      int id=ui->tableView_2->model()->index(row,0).data().toInt();
    bool test=tmpt.supprimer(id);
    if(test)
    { ui->tableView->setModel(tmpm.afficher());
        QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                                notifier->show();
                                notifier->showMessage("tache supprimé","Succés",QSystemTrayIcon::Information,10000);

}
    else
    {
        ui->tableView->setModel(tmpm.afficher());
               QSystemTrayIcon* notifier = new QSystemTrayIcon(this);
                                       notifier->show();
                                       notifier->showMessage("tache non supprimé","Echec",QSystemTrayIcon::Critical,10000);
    }


}

void Equipement::on_pushButton_10_clicked()
{
    QString strStream;
                   QTextStream out(&strStream);

                    const int rowCount = ui->tableView_2->model()->rowCount();
                    const int columnCount = ui->tableView_2->model()->columnCount();
                   out <<  "<html>\n"
                   "<head>\n"
                                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                    <<  QString("<title>%1</title>\n").arg("strTitle")
                                    <<  "</head>\n"
                                    "<body bgcolor=#ffffff link=#5000A0>\n"

                                   //     "<align='right'> " << datefich << "</align>"
                                    "<center> <H1>Liste des taches</H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                                // headers
                                out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                                out<<"<cellspacing=10 cellpadding=3>";
                                for (int column = 1; column < columnCount; column++)
                                    if (!ui->tableView_2->isColumnHidden(column))
                                        out << QString("<th>%1</th>").arg(ui->tableView_2->model()->headerData(column, Qt::Horizontal).toString());
                                out << "</tr></thead>\n";

                                // data table
                                for (int row = 0; row < rowCount; row++) {
                                    out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                    for (int column = 0; column < columnCount; column++) {
                                        if (!ui->tableView_2->isColumnHidden(column)) {
                                            QString data = ui->tableView_2->model()->data(ui->tableView_2->model()->index(row, column)).toString().simplified();
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
                           printer.setPaperSize(QPrinter::A4);
                          printer.setOutputFileName(fileName);

                           QTextDocument doc;
                            doc.setHtml(strStream);
                            doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                            doc.print(&printer);
}

void Equipement::on_pushButton_11_clicked()
{
    int row=ui->tableView->selectionModel()->currentIndex().row();
      id=ui->tableView->model()->index(row,0).data().toInt();
      ui->tabWidget->setCurrentIndex(0);
      QString res=QString::number(id);
      ui->lineEdit->setText(res);
}

void Equipement::on_pushButton_12_clicked()
{
    int row=ui->tableView_2->selectionModel()->currentIndex().row();
      id=ui->tableView_2->model()->index(row,0).data().toInt();
      ui->tabWidget_3->setCurrentIndex(0);
      QString res=QString::number(id);
      ui->lineEdit_7->setText(res);
}

void Equipement::on_pushButton_13_clicked()
{//export Excel
    QTableView *table;
           table = ui->tableView;

           QString filters("CSV files (*.csv);;All files (*.*)");
           QString defaultFilter("CSV files (*.csv)");
           QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                              filters, &defaultFilter);
           QFile file(fileName);

           QAbstractItemModel *model =  table->model();
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

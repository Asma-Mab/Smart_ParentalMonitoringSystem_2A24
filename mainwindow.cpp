#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTextStream>
#include <QFileInfo>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(tmpm.afficher());
    ui->tableView_2->setModel(tmpt.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    int id=ui->lineEdit->text().toInt();
    QString type=ui->lineEdit_2->text();
    QString nom=ui->lineEdit_3->text();
    QString description=ui->lineEdit_4->text();
    machine m(id,type,nom,description);
    bool test=m.ajouter();
    if(test)
    { ui->tableView->setModel(tmpm.afficher());
        QMessageBox::information(nullptr, QObject::tr("machine ajouté"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("machine non ajouté"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_3_clicked()
{
    int id=ui->lineEdit_5->text().toInt();
    tmpm.supprimer(id);

}

void MainWindow::on_pushButton_clicked()
{
    int id=ui->lineEdit->text().toInt();
    QString type=ui->lineEdit_2->text();
    QString nom=ui->lineEdit_3->text();
    QString description=ui->lineEdit_4->text();
    machine m(id,type,nom,description);
    bool test=m.modifier(id);
    if(test)
    { ui->tableView->setModel(tmpm.afficher());
        QMessageBox::information(nullptr, QObject::tr("machine modifié"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("machine non lodifié"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->tableView->setModel(tmpm.tri());
}

void MainWindow::on_pushButton_5_clicked()
{
    int id=ui->lineEdit_6->text().toInt();
    ui->tableView->setModel(tmpm.afficherRech(id));
}

void MainWindow::on_pushButton_6_clicked()
{
     ui->tableView->setModel(tmpm.afficher());
}

void MainWindow::on_pushButton_8_clicked()
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
    bool test=t.ajouter();
    if(test)
    { ui->tableView_2->setModel(tmpt.afficher());
        QMessageBox::information(nullptr, QObject::tr("tache ajouté"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("tache non ajouté"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_7_clicked()
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
    { ui->tableView_2->setModel(tmpt.afficher());
        QMessageBox::information(nullptr, QObject::tr("tache modifié"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("tache non modifié"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_9_clicked()
{
    int id=ui->lineEdit_11->text().toInt();
    bool test=tmpt.supprimer(id);
    if(test)
    { ui->tableView_2->setModel(tmpt.afficher());
        QMessageBox::information(nullptr, QObject::tr("tache supprimé"),
                    QObject::tr("successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("tache non supprimé"),
                    QObject::tr("failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_10_clicked()
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
                                for (int column = 0; column < columnCount; column++)
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

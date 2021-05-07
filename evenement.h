#ifndef EVENEMENT_H
#define EVENEMENT_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QtGui>
#include <QtSql>
#include <QtCore>

class Evenement
{
public:
    Evenement();
    Evenement(QString,QString,QDate);
    Evenement(int,QString,QString,QDate);
    int get_Id();
    QString get_Nom();
    QString get_Description();
    QDate get_Dateevent();

    bool ajouter();
    bool modifier(QString,QString,QDate,QString);
    bool supprimer(int);

    QSqlQueryModel * afficher();
    QSqlTableModel * moodel();
    QSqlQueryModel * remplircomboevent();
    QSqlQuery request(QString);

private:
int id;
QString nom;
QString description;
QDate dateevent;

};

#endif // EVENEMENT_H

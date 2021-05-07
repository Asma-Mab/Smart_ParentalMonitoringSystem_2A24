#ifndef ACTIVITE_H
#define ACTIVITE_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QtGui>
#include <QtSql>
#include <QtCore>

class Activite
{
public:
    Activite();
    Activite(int,QString,QString,QDate,QDate);
    Activite(QString,QString,QDate,QDate);

    bool ajouter();
    bool modifier(QString,QString,QDate,QDate,QString);
    bool supprimer(int);

    QSqlQueryModel * afficher();
    QSqlQueryModel * remplircomboactivity();
    QSqlQuery request(QString);
    QSqlQueryModel* recherche_activite(QString);
    QSqlQueryModel * triafficher(QString);






private:
int id;
QString nom;
QString type;
QDate dateDebut;
QDate dateFin;


};

#endif // ACTIVITE_H

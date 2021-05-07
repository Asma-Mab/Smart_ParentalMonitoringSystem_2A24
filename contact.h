#ifndef CONTACT_H
#define CONTACT_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QtGui>
#include <QtSql>
#include <QtCore>
#include <QPrinter>
#include <QPrintDialog>

class Contact
{
public:
    Contact();
    Contact(int,QString,QString,QString,QString);
    Contact(QString,QString,QString,QString);

    bool ajouter();
    bool modifier(QString,QString,QString,QString,QString);
    bool supprimer(int);

    QSqlQueryModel * afficher();
    QSqlQueryModel * remplircombocontact();
    QSqlQuery request(QString);
    QSqlQueryModel* recherche_contact(QString);
    QSqlQueryModel * triafficher(QString);


private:
int id;
QString nom;
QString adresse;
QString numTel;
QString email;

};

#endif // CONTACT_H

#ifndef MACHINE_H
#define MACHINE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class machine
{

public:
    machine();
    machine(int,QString,QString,QString);//constructeur parametré
    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel * afficher();
    QSqlQueryModel * tri(QString);
     QSqlQueryModel * afficherRech(QString,QString);
    bool modifier(int);
private:
    int id;
    QString type;
    QString nom;
    QString description;
};

#endif // MACHINE_H

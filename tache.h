#ifndef tache_H
#define tache_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class tache
{

public:
    tache();
    tache(int,QString,QString,QString, QString, QString, QString, int);//constructeur parametré
    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel * afficher();

    bool modifier(int);
private:
    int id;
    QString type;
    QString nom;
    QString description;
    QString date;
    QString heure_d;
    QString heure_f;
    int id_machine;
};

#endif // tache_H

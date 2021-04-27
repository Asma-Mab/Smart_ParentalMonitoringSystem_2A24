#ifndef CRUD_UTILISATEURS_H
#define CRUD_UTILISATEURS_H
#include <QVariant>
#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>
#include <QObject>
class crud_utilisateurs
{int id;
    QString prenom;
    QString nom;
    int age;
    //


public:
    crud_utilisateurs();

    crud_utilisateurs(int,QString,QString,int);
    int get_id(){return id;}
    QString get_prenom(){return prenom;}
    QString get_nom(){return nom;}
    int get_age(){return age;}
    bool ajouter();
    bool supprimer(int);
    bool modifer();
    QSqlQueryModel *afficher();
    QSqlQueryModel  *trierid();
    QSqlQueryModel  *trierprenom();
    QSqlQueryModel  *triernom();
    QSqlQueryModel  *trierage();
    QSqlQueryModel *afficher_nom(QString);
    QSqlQueryModel *afficher_id(QString);
    QSqlQueryModel *afficher_prenom(QString);
    QSqlQueryModel *afficher_age(QString);
};

#endif // CRUD_UTILISATEURS_H

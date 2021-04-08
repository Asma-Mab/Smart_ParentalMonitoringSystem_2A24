#ifndef CRUD_PROFILES_H
#define CRUD_PROFILES_H
#include <QVariant>
#include <QSqlQuery>
#include <QString>
#include <QSqlQueryModel>
#include <QObject>
class crud_profiles
{
    int id;
    QString type;
    QString Nom;
    QString password;

public:
    crud_profiles();
    crud_profiles(int,QString,QString,QString);
    int get_id(){return id;}
    QString get_type(){return type;}
    QString get_Nom(){return Nom;}
    QString get_password(){return password;}
    bool ajouter();
    bool supprimer(int);
    bool modifer();
    QSqlQueryModel *afficher();
    QSqlQueryModel  *trierid();
    QSqlQueryModel  *triertype();
    QSqlQueryModel  *trierNom();
    QSqlQueryModel  *trierpassword();
    QSqlQueryModel *afficher_Nom(QString);
    QSqlQueryModel *afficher_id(QString);
    QSqlQueryModel *afficher_type(QString);
    QSqlQueryModel *afficher_password(QString);

};

#endif // CRUD_PROFILES_H

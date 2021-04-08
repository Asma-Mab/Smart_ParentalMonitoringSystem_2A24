#include "crud_profiles.h"
#include <QObject>

crud_profiles::crud_profiles()
{

}
crud_profiles::crud_profiles(int i,QString p,QString n,QString a)
{
    id=i;
    type=p;
    Nom=n;
    password=a;
}
bool crud_profiles::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO profiles(id,type,Nom,password) VALUES (:id,:type,:Nom,:password)");
    QString res= QString::number(id);
    query.bindValue(":id",id);
    query.bindValue(":type",type);
    query.bindValue(":Nom",Nom);
    query.bindValue(":password",password);
    return query.exec();
}
bool crud_profiles::supprimer(int i)
{
    QSqlQuery query;
    query.prepare("DELETE FROM profiles where id=:id");
    QString res= QString::number(i);
    query.bindValue(":id",res);
    return query.exec();
}

bool crud_profiles ::modifer()
{
    QSqlQuery query;
    query.prepare("UPDATE  profiles SET id=:id,type=:type,Nom=:Nom,password=:password where id=:id");
    QString res= QString::number(id);
    query.bindValue(":id",id);
    query.bindValue(":type",type);
    query.bindValue(":Nom",Nom);
    query.bindValue(":password",password);
    return query.exec();
}



QSqlQueryModel * crud_profiles::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from profiles ");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"type");
    model->setHeaderData(2,Qt::Horizontal,"Nom");
    model->setHeaderData(3,Qt::Horizontal,"password");
    return model ;
}
QSqlQueryModel * crud_profiles::trierid()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * from profiles ORDER BY id");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"type");
    model->setHeaderData(2,Qt::Horizontal,"Nom");
    model->setHeaderData(3,Qt::Horizontal,"password");
    return model ;
}
QSqlQueryModel * crud_profiles::triertype()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * from profiles ORDER BY type");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"type");
    model->setHeaderData(2,Qt::Horizontal,"Nom");
    model->setHeaderData(3,Qt::Horizontal,"password");
    return model ;
}
QSqlQueryModel * crud_profiles::trierNom()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * from profiles ORDER BY Nom");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"type");
    model->setHeaderData(2,Qt::Horizontal,"Nom");
    model->setHeaderData(3,Qt::Horizontal,"password");
    return model ;
}
QSqlQueryModel * crud_profiles::trierpassword()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * from profiles ORDER BY password");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"type");
    model->setHeaderData(2,Qt::Horizontal,"Nom");
    model->setHeaderData(3,Qt::Horizontal,"password");
    return model ;
}
QSqlQueryModel * crud_profiles::afficher_id(QString prenom)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from profiles WHERE id = '"+prenom+"'");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"type");
    model->setHeaderData(2,Qt::Horizontal,"Nom");
    model->setHeaderData(3,Qt::Horizontal,"password");
    return model ;
}
QSqlQueryModel * crud_profiles::afficher_type(QString prenom)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from profiles WHERE type = '"+prenom+"'");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"type");
    model->setHeaderData(2,Qt::Horizontal,"Nom");
    model->setHeaderData(3,Qt::Horizontal,"password");
    return model ;
}
QSqlQueryModel * crud_profiles::afficher_Nom(QString prenom)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from profiles WHERE Nom = '"+prenom+"'");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"type");
    model->setHeaderData(2,Qt::Horizontal,"Nom");
    model->setHeaderData(3,Qt::Horizontal,"password");
    return model ;
}
QSqlQueryModel * crud_profiles::afficher_password(QString prenom)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from profiles WHERE password = '"+prenom+"'");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"type");
    model->setHeaderData(2,Qt::Horizontal,"Nom");
    model->setHeaderData(3,Qt::Horizontal,"password");
    return model ;
}

//


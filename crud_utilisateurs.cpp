#include "crud_utilisateurs.h"
#include <QObject>

crud_utilisateurs::crud_utilisateurs()
{

}
crud_utilisateurs::crud_utilisateurs(int i,QString p,QString n,int a)
{
    id=i;
    prenom=p;
    nom=n;
    age=a;
}
bool crud_utilisateurs::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO utilisateurs (id,prenom,nom,age) VALUES (:id,:prenom,:nom,:age)");
    QString res= QString::number(id);
    query.bindValue(":id",id);
    query.bindValue(":prenom",prenom);
    query.bindValue(":nom",nom);
    query.bindValue(":age",age);
    return query.exec();
}
bool crud_utilisateurs::supprimer(int i)
{
    QSqlQuery query;
    query.prepare("DELETE FROM utilisateurs where id=:id");
    QString res= QString::number(i);
    query.bindValue(":id",res);
    return query.exec();
}

bool crud_utilisateurs ::modifer()
{
    QSqlQuery query;
    query.prepare("UPDATE  utilisateurs SET id=:id,prenom=:prenom,nom=:nom,age=:age where id=:id");
    QString res= QString::number(id);
    query.bindValue(":id",id);
    query.bindValue(":prenom",prenom);
    query.bindValue(":nom",nom);
    query.bindValue(":age",age);
    return query.exec();
}



QSqlQueryModel * crud_utilisateurs::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from utilisateurs ");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"prenom");
    model->setHeaderData(2,Qt::Horizontal,"nom");
    model->setHeaderData(3,Qt::Horizontal,"age");
    return model ;
}
QSqlQueryModel * crud_utilisateurs::trierid()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * from utilisateurs ORDER BY id");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"prenom");
    model->setHeaderData(2,Qt::Horizontal,"nom");
    model->setHeaderData(3,Qt::Horizontal,"age");
    return model ;
}
QSqlQueryModel * crud_utilisateurs::trierprenom()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * from utilisateurs ORDER BY prenom");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"prenom");
    model->setHeaderData(2,Qt::Horizontal,"nom");
    model->setHeaderData(3,Qt::Horizontal,"age");
    return model ;
}
QSqlQueryModel * crud_utilisateurs::triernom()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * from utilisateurs ORDER BY nom");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"prenom");
    model->setHeaderData(2,Qt::Horizontal,"nom");
    model->setHeaderData(3,Qt::Horizontal,"age");
    return model ;
}
QSqlQueryModel * crud_utilisateurs::trierage()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * from utilisateurs ORDER BY age");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"prenom");
    model->setHeaderData(2,Qt::Horizontal,"nom");
    model->setHeaderData(3,Qt::Horizontal,"age");
    return model ;
}
QSqlQueryModel * crud_utilisateurs::afficher_nom(QString prenom)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from utilisateurs WHERE id = '"+prenom+"'");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"prenom");
    model->setHeaderData(2,Qt::Horizontal,"nom");
    model->setHeaderData(3,Qt::Horizontal,"age");
    return model ;
}
QSqlQueryModel * crud_utilisateurs::afficher_prenom(QString prenom)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from utilisateurs WHERE prenom = '"+prenom+"'");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"prenom");
    model->setHeaderData(2,Qt::Horizontal,"nom");
    model->setHeaderData(3,Qt::Horizontal,"age");
    return model ;
}
QSqlQueryModel * crud_utilisateurs::afficher_id(QString prenom)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from utilisateurs WHERE nom = '"+prenom+"'");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"prenom");
    model->setHeaderData(2,Qt::Horizontal,"nom");
    model->setHeaderData(3,Qt::Horizontal,"age");
    return model ;
}
QSqlQueryModel * crud_utilisateurs::afficher_age(QString prenom)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from utilisateurs WHERE age = '"+prenom+"'");
    model->setHeaderData(0,Qt::Horizontal,"id");
    model->setHeaderData(1,Qt::Horizontal,"prenom");
    model->setHeaderData(2,Qt::Horizontal,"nom");
    model->setHeaderData(3,Qt::Horizontal,"age");
    return model ;
}

//

int crud_utilisateurs::request(QString id){
    QSqlQuery query;
     query.prepare("select  * from utilisateurs  WHERE ID= '"+id+"'");
     query.exec();
      int total=0;

     while(query.next()){
       total++;

     }


     return total;
}


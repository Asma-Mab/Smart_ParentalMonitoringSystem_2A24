#include "machine.h"
#include <QVariant>
machine::machine()
{

}
machine::machine(int id,QString type,QString nom,QString description)
{
this->id=id;
    this->type=type;
    this->nom=nom;
    this->type=type;
    this->description=description;
}
bool machine::ajouter()
{
    QSqlQuery q;//requete sql
    q.prepare("insert into machine values(:id,:type,:nom,:description)");
    q.bindValue(":id",id);
    q.bindValue(":type",type);
    q.bindValue(":nom",nom);
    q.bindValue(":description",description);
    return q.exec();
}
bool machine::supprimer(int id)
{
    QSqlQuery q;
    q.prepare("delete from machine where id=:id");
    q.bindValue(":id",id);
    return q.exec();
}

QSqlQueryModel * machine::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from machine");
    return model;
}
bool machine::modifier(int id)
{
    QSqlQuery q;
    q.prepare("update machine set type=:type,nom=:nom,description=:description where id=:id");
    q.bindValue(":id",id);
    q.bindValue(":type",type);
    q.bindValue(":nom",nom);
    q.bindValue(":description",description);
    return q.exec();


}

QSqlQueryModel * machine::tri()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from machine order by nom");
    return model;
}
QSqlQueryModel * machine::afficherRech(int id)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString id_str=QString::number(id);
    model->setQuery("select * from machine where id like '"+id_str+"%'");
    return model;
}


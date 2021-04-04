#include "tache.h"
#include <QVariant>
tache::tache()
{

}
tache::tache(int id,QString type,QString nom,QString description, QString date, QString heure_d, QString heure_f, int id_m)
{
this->id=id;
    this->nom=nom;
    this->type=type;
    this->description=description;
    this->date=date;
        this->heure_d=heure_d;
        this->heure_f=heure_f;
        this->id_machine=id_m;
}
bool tache::ajouter()
{
    QSqlQuery q;//requete sql
    q.prepare("insert into tache values(:id,:type,:nom,:description,:date,:heure_d,:heure_f,:id_m)");
    q.bindValue(":id",id);
    q.bindValue(":type",type);
    q.bindValue(":nom",nom);
    q.bindValue(":description",description);
    q.bindValue(":date",date);
    q.bindValue(":heure_d",heure_d);
    q.bindValue(":heure_f",heure_f);
    q.bindValue(":id_m",id_machine);
    return q.exec();
}
bool tache::supprimer(int id)
{
    QSqlQuery q;
    q.prepare("delete from tache where id=:id");
    q.bindValue(":id",id);
    return q.exec();
}

QSqlQueryModel * tache::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from tache");
    return model;
}
bool tache::modifier(int id)
{
    QSqlQuery q;
    q.prepare("update tache set type=:type,nom=:nom,description=:description,datet=:date,heure_d=:heure_d,heure_f=:heure_f,id_machine=:id_m where id=:id");
    q.bindValue(":id",id);
    q.bindValue(":type",type);
    q.bindValue(":nom",nom);
    q.bindValue(":description",description);
    q.bindValue(":date",date);
    q.bindValue(":heure_d",heure_d);
    q.bindValue(":heure_f",heure_f);
    q.bindValue(":id_m",id_machine);
    return q.exec();


}




#include "evenement.h"


//********Initialisation

//Constructeur par defaut
Evenement::Evenement()
{
id=0;
nom="";
description="";
}

//Constructeur pour Afficher
Evenement::Evenement(int id,QString nom,QString description,QDate dateevent)
{
  this->id=id;
  this->nom=nom;
  this->description=description;
  this->dateevent=dateevent;
}

//Constructeur pour Ajouter
Evenement::Evenement(QString nom,QString description,QDate dateevent)
{
  this->nom=nom;
  this->description=description;
  this->dateevent=dateevent;
}

//GETTERS
int Evenement::get_Id(){return  id;}
QString Evenement::get_Nom(){return  nom;}
QString Evenement::get_Description(){return  description;}
QDate Evenement::get_Dateevent(){return  dateevent;}

//*******AJOUTER

bool Evenement::ajouter()
{
QSqlQuery query;

query.prepare("INSERT INTO EVENEMENT (nom, DESCRIPTION,DATEEVENT) "
                    "VALUES (:nom, :description, :dateevent)");


query.bindValue(":nom", nom);
query.bindValue(":description", description);
query.bindValue(":dateevent", dateevent);


return    query.exec();
}
//*******MODIFIER

bool Evenement::modifier(QString nom,QString description,QDate dateevent,QString id)
{
QSqlQuery query;

query.prepare("UPDATE EVENEMENT SET nom= :nom, DESCRIPTION= :description,DATEEVENT= :dateevent "
                    " WHERE  ID = :id ");


query.bindValue(":id", id);
query.bindValue(":nom", nom);
query.bindValue(":description", description);
query.bindValue(":dateevent", dateevent);


return    query.exec();
}

//******AFFICHER

QSqlQueryModel * Evenement::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from EVENEMENT");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("description"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date evenement"));


    return model;
}

//*******SUPPRIMPER

bool Evenement::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from EVENEMENT where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}


//******MODEL

QSqlTableModel * Evenement::moodel()
{
    QSqlTableModel * model  =new QSqlTableModel();

model->setTable("EVENEMENT");
model->select();
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Description"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date evenement"));

return model;
}

//******REMPLIR COMBO BOX

QSqlQueryModel * Evenement::remplircomboevent()
{
    QSqlQueryModel * mod= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select ID from EVENEMENT");
    query.exec();
    mod->setQuery(query);
    return mod;
}


QSqlQuery Evenement::request(QString id)
{
    QSqlQuery query;
    query.prepare("select * from EVENEMENT where ID= '"+id+"'");
    query.addBindValue(id);
    query.exec();
    return query;
}

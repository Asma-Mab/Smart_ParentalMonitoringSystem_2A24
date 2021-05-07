#include "activite.h"

Activite::Activite()
{
id=0;
nom="";
type="";

}
//Constructeur pour Afficher
Activite::Activite(int id,QString nom,QString type,QDate dateDebut,QDate dateFin)
{
  this->id=id;
  this->nom=nom;
  this->type=type;
  this->dateDebut=dateDebut;
  this->dateFin=dateFin;
}

//Constructeur pour Ajouter
Activite::Activite(QString nom,QString type,QDate dateDebut,QDate dateFin)
{
  this->nom=nom;
  this->type=type;
  this->dateDebut=dateDebut;
    this->dateFin=dateFin;

}

//*******AJOUTER

bool Activite::ajouter()
{
QSqlQuery query;

query.prepare("INSERT INTO ACTIVITE (NOM, TYPE,DATEDEBUT,DATEFIN) "
                    "VALUES (:nom, :type, :dateDebut, :dateFin)");


query.bindValue(":nom", nom);
query.bindValue(":type", type);
query.bindValue(":dateDebut", dateDebut);
query.bindValue(":dateFin", dateFin);



return    query.exec();
}
//*******MODIFIER

bool Activite::modifier(QString nom,QString type,QDate dateDebut,QDate dateFin,QString id)
{
QSqlQuery query;

query.prepare("UPDATE ACTIVITE SET NOM= :nom, TYPE= :type,DATEDEBUT= :dateDebut,DATEFIN =:dateFin "
                    " WHERE  ID = :id ");


query.bindValue(":id", id);
query.bindValue(":nom", nom);
query.bindValue(":type", type);
query.bindValue(":dateDebut", dateDebut);
query.bindValue(":dateFin", dateFin);


return    query.exec();
}

//******AFFICHER

QSqlQueryModel * Activite::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from ACTIVITE");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Debut"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date Fin"));



    return model;
}

//*******SUPPRIMPER

bool Activite::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from ACTIVITE where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}


//******REMPLIR COMBO BOX

QSqlQueryModel * Activite::remplircomboactivity()
{
    QSqlQueryModel * mod= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select ID from ACTIVITE");
    query.exec();
    mod->setQuery(query);
    return mod;
}


QSqlQuery Activite::request(QString id)
{
    QSqlQuery query;
    query.prepare("select * from ACTIVITE where ID= '"+id+"'");
    query.addBindValue(id);
    query.exec();
    return query;
}

//******AFFICHER TRI

QSqlQueryModel * Activite::triafficher(QString col)
{QSqlQueryModel * model= new QSqlQueryModel();

    QSqlQuery query;
    query.prepare("select * from ACTIVITE order by "+col);
    query.exec();


model->setQuery(query);

model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Debut"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date Fin"));
return model;
}


QSqlQueryModel *Activite::recherche_activite(QString a)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *q=new QSqlQuery();
    q->prepare("SELECT * FROM  ACTIVITE WHERE NOM LIKE '%"+a+"%' OR TYPE LIKE '%"+a+"%' OR ID LIKE '%"+a+"%'");
    q->exec();
    model->setQuery(*q);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Debut"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date Fin"));

 return model;
}

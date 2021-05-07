#include "contact.h"

Contact::Contact()
{
id=0;
nom="";
adresse="";
numTel="";
email="";

}
//Constructeur pour Afficher
Contact::Contact(int id,QString nom,QString adresse,QString numTel,QString email)
{
  this->id=id;
  this->nom=nom;
  this->adresse=adresse;
  this->numTel=numTel;
  this->email=email;
}

//Constructeur pour Ajouter
Contact::Contact(QString nom,QString adresse,QString numTel,QString email)
{
  this->nom=nom;
  this->adresse=adresse;
  this->numTel=numTel;
    this->email=email;

}
//*******AJOUTER

bool Contact::ajouter()
{
QSqlQuery query;

query.prepare("INSERT INTO Contact (NOM, ADRESSE,NUMTEL,EMAIL) "
                    "VALUES (:nom, :adresse, :numTel, :email)");


query.bindValue(":nom", nom);
query.bindValue(":adresse", adresse);
query.bindValue(":numTel", numTel);
query.bindValue(":email", email);



return    query.exec();
}
//*******MODIFIER

bool Contact::modifier(QString nom,QString adresse,QString numTel,QString email,QString id)
{
QSqlQuery query;

query.prepare("UPDATE Contact SET NOM= :nom, ADRESSE= :adresse,NUMTEL= :numTel,EMAIL =:email "
                    " WHERE  ID = :id ");


query.bindValue(":id", id);
query.bindValue(":nom", nom);
query.bindValue(":adresse", adresse);
query.bindValue(":numTel", numTel);
query.bindValue(":email", email);


return    query.exec();
}

//******AFFICHER

QSqlQueryModel * Contact::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from Contact");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Numéro de téléphone"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("E-mail"));



    return model;
}

//*******SUPPRIMPER

bool Contact::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from Contact where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

//******REMPLIR COMBO BOX

QSqlQueryModel * Contact::remplircombocontact()
{
    QSqlQueryModel * mod= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select ID from Contact");
    query.exec();
    mod->setQuery(query);
    return mod;
}


QSqlQuery Contact::request(QString id)
{
    QSqlQuery query;
    query.prepare("select * from Contact where ID= '"+id+"'");
    query.addBindValue(id);
    query.exec();
    return query;
}
QSqlQueryModel *Contact::recherche_contact(QString c)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *q=new QSqlQuery();
    q->prepare("SELECT * FROM  CONTACT WHERE NOM LIKE '%"+c+"%' OR ADRESSE LIKE '%"+c+"%' OR NUMTEL LIKE '%"+c+"%' OR EMAIL LIKE '%"+c+"%'");
    q->exec();
    model->setQuery(*q);
 return model;
}

//******AFFICHER TRI

QSqlQueryModel * Contact::triafficher(QString col)
{QSqlQueryModel * model= new QSqlQueryModel();

    QSqlQuery query;
    query.prepare("select * from CONTACT order by "+col);
    query.exec();


model->setQuery(query);

model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Numéro de téléphone"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("E-mail"));

return model;
}

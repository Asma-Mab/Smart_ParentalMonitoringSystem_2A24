#include "site.h"
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

//définition du constructeur par défaut:
site::site()
{
id_site=0; lien=""; description="";
}

//définition du constructeur paramétré:
site::site(int id_site,QString lien,QString description){
this->id_site=id_site;
this->lien=lien;
this->description=description;
}


//définition des getters:
int site::get_id_site(){return id_site;}
QString site:: get_lien(){return lien;}
QString site:: get_description(){return description;}


//définition des setters:
void site:: set_id_site(int id_site){this->id_site=id_site;}
void site:: set_lien(QString lien){this->lien=lien;}
void site:: set_description(QString description){this->description=description;}


//définition de la méthode ajouter:
bool site::ajouter(){


    QSqlQuery query;  //declaration de requette sql
    //QString numero_string= QString::number(numero); //convertire num a QString
    query.prepare("INSERT INTO SITE (ID_SITE, LIEN,DESCRIPTION) "
                  "VALUES (:id_site, :lien, :description)");   //preparation de requette
    query.bindValue(":id_site", id_site); //injection sql (securité)
    query.bindValue(":lien", lien);
    query.bindValue(":description", description);

    return   query.exec();


}



bool site::supprimer(int id_site){

 QSqlQuery query;

    query.prepare("Delete from SITE where ID_SITE=:id_site");
    query.bindValue(0, id_site);

    return   query.exec();

}





QSqlQueryModel* site::afficher(){

    QSqlQueryModel* model=new QSqlQueryModel(); //representation graphique d un table sql

         model->setQuery("SELECT * FROM SITE");

    return model;
}




QSqlQueryModel * site::chercher(int id_site)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString rech=QString::number(id_site);
    model->setQuery("select * from SITE where ID_SITE like '"+rech+"%'");

        return model;
}

bool site::modifier(int id_site)
{
    QSqlQuery query;
    query.prepare("update SITE set LIEN=:lien,DESCRIPTION=:description where ID_SITE=:id_site");
    query.bindValue(":id_site", id_site);
    query.bindValue(":lien", lien);
    query.bindValue(":description", description);

    return   query.exec();
}
QSqlQueryModel * site::trier(QString selon)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from SITE order by "+selon+"");

        return model;
}
QSqlQueryModel * site::stat()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select DESCRIPTION,count(*) as nombre from SITE group by DESCRIPTION");

        return model;
}

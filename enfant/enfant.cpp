#include "enfant.h"

enfant::enfant()
{

}
enfant::enfant(int id_enf,QString nom,QString prenom, int age)
{
    this->id_enf=id_enf;
    this->nom=nom;
    this->prenom=prenom;
    this->age= age;
}
bool enfant::ajouter(){


    QSqlQuery query;
    //QString age_string= QString::number(age);
    query.prepare("INSERT INTO ENFANT (ID_ENF, NOM, PRENOM, AGE) "
                  "VALUES (:ID_ENF, :NOM, :PRENOM, :AGE)");
    query.bindValue(":ID_ENF",id_enf);
    query.bindValue(":NOM", nom);
    query.bindValue(":PRENOM", prenom);
    query.bindValue(":AGE", age);

    return   query.exec();


}
bool enfant::supprimer(int id_enf){

 QSqlQuery query;

    query.prepare("Delete from ENFANT where ID_ENF=:ID_ENF");
    query.bindValue(0, id_enf);

    return   query.exec();

}
QSqlQueryModel* enfant::afficher(){

    QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("SELECT * FROM ENFANT");

    return model;
}
QSqlQueryModel * enfant::chercher(int id_enf)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString rech=QString::number(id_enf);
    model->setQuery("select * from ENFANT where ID_ENF like '"+rech+"%'");

        return model;
}
bool enfant::modifier(int id_enf)
{
    QSqlQuery query;
    query.prepare("update ENFANT set NOM=:NOM , PRENOM=:PRENOM , AGE=:AGE where ID_ENF=:ID_ENF");
    query.bindValue(":ID_ENF", id_enf);
    query.bindValue(":NOM", nom);
    query.bindValue(":PRENOM", prenom);
    query.bindValue(":AGE", age);

    return   query.exec();
}

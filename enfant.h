#ifndef ENFANT_H
#define ENFANT_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
class enfant
{
public:
enfant();
enfant(int,QString,QString,int);
bool ajouter();
QSqlQueryModel *afficher();
bool supprimer (int);
QSqlQueryModel *chercher(int);
bool modifier(int);
void archiver(int);
void recuperer(int);
QSqlQueryModel * afficherAR();
void supprimerAR(int);
private:
int id_enf;
QString nom;
QString prenom;
int age;
};

#endif // ENFANT_H

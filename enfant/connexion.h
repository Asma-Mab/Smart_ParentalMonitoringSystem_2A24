#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>


class Connection
{
public:
    Connection();        //constructeur par defaut
    bool createconnexion();     //type de retour
    bool ouvrirconnexion();
    void fermerconnexion();

private:
    QSqlDatabase db;
};


#endif // CONNECTION_H

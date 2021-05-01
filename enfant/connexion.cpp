#include "connexion.h"
#include "QSqlDatabase"

Connection::Connection()
{

}

bool Connection::ouvrirconnexion(){
    bool test=false;
    QSqlDatabase db= QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("test_bd");
    db.setUserName("SYSTEM");
    db.setPassword("SYSTEM");

    if(db.open())
        test=true;
    return test;
}
void Connection::fermerconnexion()
{
    db.close();
}

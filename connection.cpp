#include "connection.h"

Connection::Connection()
{}

bool Connection::ouvrirConnexion()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet2021");
db.setUserName("mohamed");
db.setPassword("0000");

if (db.open())
    test=true;
return  test;
}
QSqlDatabase Connection::getdb()
{
    return db;
}

void Connection::fermerConnexion()
{db.close();}

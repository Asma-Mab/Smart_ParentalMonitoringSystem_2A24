#ifndef CONNECTER_H
#define CONNECTER_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
class Connection
{
public:
Connection();
bool createconnect();
};
#endif // CONNECTER_H

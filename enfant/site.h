#ifndef SITE_H
#define SITE_H
#include <QString>
#include <QSqlQueryModel>


class site
{
public:
    //constructeur par dÃ©faut:
    site();
    //constructeur paramÃ©trÃ©:
    site(int,QString,QString);

    //implementation des getters:
    int get_id_site();
    QString get_lien();
    QString get_description();

    //implementation des setters:
    void set_id_site(int);
    void set_lien(QString);
    void set_description(QString);
    //implementation des methodes (CRUD):
    bool ajouter();
    QSqlQueryModel *afficher();
    QSqlQueryModel *stat();
    QSqlQueryModel *trier(QString);
    bool supprimer (int);
    QSqlQueryModel *chercher(int);
    bool modifier(int);

private:
    int id_site;
    QString lien;
    QString description;
};

#endif // SITE_H

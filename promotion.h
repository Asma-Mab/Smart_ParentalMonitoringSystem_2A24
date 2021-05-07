#ifndef PROMTION_H
#define PROMTION_H
#include <QString>

class promotion
{
public:
    promotion();
    promotion(QString,float,float,float,int);
    promotion(int,QString,float,float,float,int);


private:
    int id;
    QString produit;
    float prixAv;
    float prixAp;
    float pourcentage;
    int duree;

};

#endif // PROMTION_H

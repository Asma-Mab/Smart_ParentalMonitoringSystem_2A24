#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include "machine.h"
#include <QMainWindow>
#include "tache.h"
namespace Ui {
class Equipement;
}

class Equipement : public QMainWindow
{
    Q_OBJECT

public:
    explicit Equipement(QWidget *parent = nullptr);
    ~Equipement();
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();


private:
    Ui::Equipement *ui;
    machine tmpm;
    tache tmpt;
    int id;

};

#endif // EQUIPEMENT_H

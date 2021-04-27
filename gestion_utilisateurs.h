#ifndef GESTION_UTILISATEURS_H
#define GESTION_UTILISATEURS_H
#include <QDialog>
#include "crud_utilisateurs.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QDialog>
#include <QMediaPlayer>
#include <QObject>

namespace Ui {
class gestion_utilisateurs;
}

class gestion_utilisateurs : public QMainWindow
{
    Q_OBJECT

public:
    explicit gestion_utilisateurs(QWidget *parent = nullptr);
    ~gestion_utilisateurs();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_ajoute_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_modifer_clicked();

    void on_pushButton_3_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

    void on_checkBox_4_clicked();

    void on_pushButton_rechercher_clicked();

    void on_pushButton_impression_client_clicked();

    void on_pushButton_ajouter_re_clicked();

    void on_pushButton_rechercher_2_clicked();

    void on_pushButton_rechercher_3_clicked();

    void on_pushButton_rechercher_4_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

private:
    Ui::gestion_utilisateurs *ui;
     crud_utilisateurs temputilisateurs;
     QMediaPlayer* player;
};


#endif // GESTION_UTILISATEURS_H

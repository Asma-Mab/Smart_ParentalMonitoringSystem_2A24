#ifndef GESTION_PROFILES_H
#define GESTION_PROFILES_H

#include <QMainWindow>
#include <QDialog>
#include <QMessageBox>
#include "crud_profiles.h"
#include <QMediaPlayer>
#include <QObject>


namespace Ui {
class gestion_profiles;
}

class gestion_profiles : public QMainWindow
{
    Q_OBJECT

public:
    explicit gestion_profiles(QWidget *parent = nullptr);
    ~gestion_profiles();


private slots:
    void on_pushButton_clicked();



    void on_pushButton_2_clicked();

    void on_pushButton_modifer_2_clicked();

    void on_lineEdit_recherche_2_clicked();



    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

    void on_checkBox_4_clicked();



    void on_pushButton_impression_profil_clicked();



    void on_pushButton_rech1_clicked();

    void on_pushButton_rech2_clicked();

    void on_pushButton_rech3_clicked();
//
    void on_radioButton_5_clicked();

    void on_radioButton_6_clicked();

    void on_radioButton_7_clicked();

    void on_radioButton_8_clicked();

//
    void on_pushButton_ajoute_2_clicked();









private:
    Ui::gestion_profiles *ui;
    crud_profiles tempprofiles;
     QMediaPlayer* player;
};


#endif // GESTION_PROFILES_H

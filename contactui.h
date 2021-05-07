#ifndef CONTACTUI_H
#define CONTACTUI_H

#include <QDialog>
#include"contact.h"
#include <QSystemTrayIcon>
#include "activite.h"

namespace Ui {
class ContactUI;
}

class ContactUI : public QDialog
{
    Q_OBJECT

public:
    explicit ContactUI(QWidget *parent = nullptr);
    ~ContactUI();

private slots:
    void on_AjouterBouton_clicked();

    void on_modifiebtn_clicked();

    void on_SupprimerBouton_clicked();

    void on_comboBox_modif_currentIndexChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_rechercheButton_clicked();

    void on_trier_Button_clicked();
    void sendMail();
    void mailSent(QString status) ;


    void on_comboBox_2_currentIndexChanged(const QString &arg1);

    void on_envoyer_clicked();
    void print(QPrinter *printer);


    void on_imprimer_clicked();

    void on_recherche_contact_cursorPositionChanged(int arg1, int arg2);

    void on_comboBox_tri_contact_currentIndexChanged(const QString &arg1);

    void on_comboBox_tri_contact_activated(const QString &arg1);

    void on_AjouterBouton_3_clicked();

    void on_comboBox_modif_act_currentIndexChanged(const QString &arg1);

    void on_modifiebtn_3_clicked();


    void on_comboBox_act_currentIndexChanged(const QString &arg1);

    void on_SupprimerBouton_3_clicked();

    void on_recherche_cursorPositionChanged(int arg1, int arg2);

    void on_comboBox_tri_currentIndexChanged(const QString &arg1);

    void refresh();

    void on_Excels_clicked();

private:
    Ui::ContactUI *ui;
    Contact contactTmp ;
    Activite activiteTmp ;
    QSystemTrayIcon * trayIcon;

    QSqlTableModel * model;
};

#endif // CONTACTUI_H

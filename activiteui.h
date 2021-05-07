#ifndef ACTIVITEUI_H
#define ACTIVITEUI_H
#include"activite.h"
#include "contact.h"

#include <QDialog>
#include <QSystemTrayIcon>

namespace Ui {
class ActiviteUI;
}

class ActiviteUI : public QDialog
{
    Q_OBJECT

public:
    explicit ActiviteUI(QWidget *parent = nullptr);
    ~ActiviteUI();

private slots:
    void on_AjouterBouton_clicked();

    void on_modifiebtn_clicked();

    void on_SupprimerBouton_clicked();

    void on_comboBox_modif_currentIndexChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_trier_Button_clicked();

    void refresh();
    void on_comboBox_tri_currentIndexChanged(const QString &arg1);

    void on_recherche_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::ActiviteUI *ui;
    Activite activiteTmp ;
    Contact contacttmp;

    QSystemTrayIcon * trayIcon;

    QSqlTableModel * model;

};

#endif // ACTIVITEUI_H

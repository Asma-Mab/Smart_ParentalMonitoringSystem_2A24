#ifndef ENFANT_INTER_H
#define ENFANT_INTER_H

#include <QMainWindow>
#include "site.h"
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <enfant.h>

namespace Ui {
class Enfant_Inter;
}

class Enfant_Inter : public QMainWindow
{
    Q_OBJECT

public:
    explicit Enfant_Inter(QWidget *parent = nullptr);
    ~Enfant_Inter();
private slots:
    //void MakePlot();
    void on_btn_ajout_clicked();

    void on_btn_supp_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_btn_ajout_2_clicked();

    void on_btn_supp_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_9_clicked();

    void on_btn_ajout_notes_clicked();

    void on_btn_notes_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_14_clicked();


private:
    Ui::Enfant_Inter *ui;
    site C;
    enfant l;
};

#endif // ENFANT_INTER_H

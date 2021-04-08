#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>
#include "gestion_utilisateurs.h"
#include "gestion_profiles.h"
#include <QObject>

QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow2;
}

class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow2(QWidget *parent = nullptr);
    ~MainWindow2();
private slots:
    void on_pushButton_exit_clicked();




    //

    void on_pushButton_profiles_clicked();

    void on_pushButton_utilisateurs_clicked();

private:
    Ui::MainWindow2 *ui;
    gestion_profiles *gc;
    gestion_utilisateurs *gf;
    QMediaPlayer *player;
};

#endif // MAINWINDOW2_H

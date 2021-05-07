#include "promotionitinter.h"
#include "ui_promotionitinter.h"

promotioninter::promotioninter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::produitinter)
{
    ui->setupUi(this);
    setWindowTitle("Gestion Produits");
}

promotioninter::~promotioninter()
{
    delete ui;
}

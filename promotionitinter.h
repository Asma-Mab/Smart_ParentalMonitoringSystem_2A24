#ifndef PRODUITINTER_H
#define PRODUITINTER_H

#include <QDialog>

namespace Ui {
class produitinter;
}

class promotioninter : public QDialog
{
    Q_OBJECT

public:
    explicit promotioninter(QWidget *parent = nullptr);
    ~promotioninter();

private:
    Ui::produitinter *ui;
};

#endif // PRODUITINTER_H

#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <QDialog>
#include "carttable.h"

class QKeyEvent;

namespace Ui {
class ShoppingCart;
}

class ShoppingCart : public QDialog
{
    Q_OBJECT

public:
    explicit ShoppingCart(QWidget *parent = 0);
    ~ShoppingCart();
    void closeEvent(QCloseEvent*);

signals:
    void isShown(bool);
    void dialogClosed();

public slots:
    void showOrHide();
    cartTable* returnTable();

private:
    Ui::ShoppingCart *ui;
};

#endif // SHOPPINGCART_H

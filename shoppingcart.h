#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <QDialog>

namespace Ui {
class ShoppingCart;
}

class ShoppingCart : public QDialog
{
    Q_OBJECT

public:
    explicit ShoppingCart(QWidget *parent = 0);
    ~ShoppingCart();

signals:
    void isShown(bool);

public slots:
    void showOrHide();

private:
    Ui::ShoppingCart *ui;
};

#endif // SHOPPINGCART_H

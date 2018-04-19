#ifndef CHECKOUTBUTTON_H
#define CHECKOUTBUTTON_H

#include <QObject>
#include <QPushButton>
#include <vector>
#include "nonstackbasedsumvisitor.h"

class ShoppingCart;

class checkoutButton : public QPushButton{
    Q_OBJECT

public:
    checkoutButton(QWidget* qw):QPushButton(qw){};
    void setMainWindow(ShoppingCart*);

protected:
    ShoppingCart* m_main;


signals:
    void changeLabel(double); //sends the final price to label

public slots:

};

#endif // CHECKOUTBUTTON_H

#ifndef DELETEBUTTON_H
#define DELETEBUTTON_H

#include <QObject>
#include <QPushButton>
#include <vector>

class ShoppingCart;

class deleteButton : public QPushButton{
    Q_OBJECT

public:
    deleteButton(QWidget* qw):QPushButton(qw){};
    void setMainWindow(ShoppingCart*);

signals:

protected:
    ShoppingCart* m_main;


public slots:
    void deleteRow();

};


#endif // DELETEBUTTON_H

#ifndef SHOWBUTTON_H
#define SHOWBUTTON_H

#include <QPushButton>

class showButton : public QPushButton{
    Q_OBJECT

public:
    showButton(QWidget* qw):QPushButton(qw){};

public slots:
    void changeText(bool);
    void changeText(); //for when x is pressed
};

#endif // SHOWBUTTON_H

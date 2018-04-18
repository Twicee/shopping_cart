#ifndef ADDBUTTON_H
#define ADDBUTTON_H

#include <QObject>
#include <QPushButton>
#include <vector>

class MainWindow;

class addButton : public QPushButton{
    Q_OBJECT

public:
    addButton(QWidget* qw):QPushButton(qw){};
    void setMainWindow(MainWindow*);

signals:
    void AddtoCart(std::vector<QString>);

protected:
    MainWindow* m_main;

public slots:
    void AddClicked();
};

#endif // ADDBUTTON_H

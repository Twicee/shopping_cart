#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "shoppingcart.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:


private slots:
    void on_loadButton_clicked();

private:
    Ui::MainWindow *ui;
    ShoppingCart* listener;

};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <QTableWidgetItem>

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

signals:
    void AddtoCart(std::vector<QString>);

public slots:


private slots:
    void on_loadButton_clicked();

    void on_addCartButton_clicked();

    void on_mainTable_cellClicked(int row, int column);

    void on_bundleTable_cellClicked(int row, int column);

private:
    Ui::MainWindow *ui;
    ShoppingCart* listener;
    std::vector<int> tableInfo{-1,-1};
};

#endif // MAINWINDOW_H

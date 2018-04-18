#include "shoppingcart.h"
#include "ui_shoppingcart.h"

ShoppingCart::ShoppingCart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShoppingCart)
{
    ui->setupUi(this);
    ui->cartTable->setColumnCount(2);
    //connect(ui->deleteButton,SIGNAL(clicked()),ui->cartTable,SLOT(removeRow())); // deletes selection

}

ShoppingCart::~ShoppingCart()
{
    delete ui;
}


void ShoppingCart::showOrHide(){
    if (isVisible() == false){
        show();
        emit isShown(true);
    }
    else{
        hide();
        emit isShown(false);
    }
}

void ShoppingCart::AddtoTable(std::vector<QString> itemVector){
    int row_number = ui->cartTable->rowCount();
    ui->cartTable->insertRow(ui->cartTable->rowCount());
    ui->cartTable->setItem(row_number, 0,  new QTableWidgetItem(itemVector[1]));
    if (itemVector[0] == "Pet"){
        ui->cartTable->setItem(row_number, 1,  new QTableWidgetItem(itemVector[3]));
    }
    else{
        ui->cartTable->setItem(row_number, 1,  new QTableWidgetItem(itemVector[2]));
    }
}


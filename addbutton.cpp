#include "addbutton.h"
#include "mainwindow.h"

void addButton::AddClicked(){
    std::vector<QString> itemVector = m_main->getActiveTableRow();
    if (itemVector.size() != 0){
        emit AddtoCart(itemVector);
    }
}

void addButton::setMainWindow(MainWindow* main){
    m_main = main;
}

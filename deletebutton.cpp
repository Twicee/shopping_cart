#include "deletebutton.h"
#include "shoppingcart.h"

void deleteButton::deleteRow(){
    int rowIndex = m_main->returnTable()->currentRow();
    m_main->returnTable()->removeRow(rowIndex);

}

void deleteButton::setMainWindow(ShoppingCart* main){
    m_main = main;
}

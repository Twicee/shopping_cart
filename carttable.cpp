#include "carttable.h"

void cartTable::AddtoTable(std::vector<QString> itemVector){
    int row_number = rowCount();
    insertRow(rowCount());
    setItem(row_number, 0,  new QTableWidgetItem(itemVector[1]));
    if (itemVector[0] == "Pet"){
        setItem(row_number, 1,  new QTableWidgetItem(itemVector[3]));
    }
    else{
        setItem(row_number, 1,  new QTableWidgetItem(itemVector[2]));
    }
}

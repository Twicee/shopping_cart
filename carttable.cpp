#include "carttable.h"

#include "PetDatabaseSortableByPrice.h"
#include "Dog.h"
#include "nonstackbasedsumvisitor.h"
#include "BubbleSortIncreasing.h"
#include <QTableWidgetItem>
#include <fstream>
#include <sstream>

void cartTable::AddtoTable(std::vector<QString> itemVector){
    int row_number = rowCount();

    insertRow(rowCount());
    setItem(row_number, 0,  new QTableWidgetItem(itemVector[1]));
    if (itemVector[0] == "Pet"){
        setItem(row_number, 1,  new QTableWidgetItem(itemVector[3])); // if pet
    }
    else{
        setItem(row_number, 1,  new QTableWidgetItem(itemVector[2])); // if bundle
    }
}

void cartTable::checkout(){
    PetDatabaseSortableByPrice* database = new PetDatabaseSortableByPrice();
    // cart table
    int row_number  = rowCount();
    for (int i = 0; i < row_number; i++){
        std::string name = (item(i,0)->text()).toStdString();
        double price = (item(i,1)->text()).toDouble();
        Dog* pet = new Dog(name, "", price, 0, "");
        database->AddPet(pet);
    }
    // delete old entries
    setRowCount(0);

    // sorting
    BubbleSortIncreasing bsi;
    bsi.sort(database);
    database->DisplayRecords();

    // insertback
    int new_row = 0;
    for (int i = 0; i < database->getSize(); i++){
        new_row = rowCount();
        insertRow(new_row);
        setItem(new_row, 0,  new QTableWidgetItem(QString::fromStdString(database->getPet(i)->GetName())));
        setItem(new_row, 1,  new QTableWidgetItem(QString::number(database->getPet(i)->GetPrice())));
    }

    // writing to outputfile
    ofstream outfile;
    outfile.open("Checkout.csv");
    for (int i = 0; i < database->getSize(); i++){
        string name = database->getPet(i)->GetName();
        string price = to_string(database->getPet(i)->GetPrice());
        outfile << name + "," + price + "\n";
    }
    outfile.close();

    // giving final price to the label
    NonStackBasedSumVisitor nsbsv;
    database->Accept(&nsbsv);
    double totalprice = nsbsv.getResult();

    std::ostringstream priceConvert;
    priceConvert << std::setprecision(4) << totalprice;
    std::string finalPrice = "Total: $"+priceConvert.str();
    QString qPrice = QString::fromStdString(finalPrice);
    emit changeLabel(qPrice);
    parentWidget()->setEnabled(false);
    parentWidget()->parentWidget()->setEnabled(false);

}




#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <fstream>
#include <iostream>
#include <QDebug>
#include <QDir>
#include <string>
#include <sstream>
#include <algorithm>
//using namespace std;

#include "databasebuilder.h"
#include "databaseparser.h"
#include "PetDatabase.h"
#include "PetDatabaseSortableByName.h"
#include "BubbleSortDecreasing.h"
#include "BubbleSortIncreasing.h"
#include "nonstackbasedsumvisitor.h"
#include "BinarySearch.h"
#include "PetDatabaseSearchableByName.h"
#include "showbutton.h"

#include "shoppingcart.h"

// Patterns to use:
//1. You will exercise Abstract Factory Pattern, Composite Pattern,
//    Builder pattern and Visitor Pattern in database construction.

// Abstract factory pattern: Abstract class as
// inteface for concrete algorithm classes

// Composite Pattern (Bundles): Abstract Base class that other
// concrete classes inherit from. Can make bundles which are products of
// other concrete products.

// Builder Pattern:  When you want to build complex data structures
// from some data. Give builder some information and have it build the object

// Visitor Pattern: Make a visitor that the old class accepts to add new functions.
// Old class accepts visitor which lets the visitor do its one role

// For the shopping cart/mainwindow observer pattern
// and distributed collaboration necessary

// To do:
// Load the database and build it with builder pattern?
// Use visitor pattern to calculate bundle prices?
// bundles are composites (composite pattern)

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->addCartButton->setEnabled(false);
    ui->showCartButton->setEnabled(false);

    // SetTable
    ui->mainTable->setColumnCount(4);
    ui->bundleTable->setColumnCount(3);

    // Current directory
    //qDebug() << QDir::currentPath();

    // Shopping cart setup
    listener = new ShoppingCart(this); // defined in .h

    // Connections
    // showButton
    // addCartButton
    connect(ui->showCartButton,SIGNAL(clicked()),listener,SLOT(showOrHide())); // makes button show or hide cart depending if open
    connect(listener,SIGNAL(isShown(bool)),ui->showCartButton,SLOT(changeText(bool)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool sortMatrix(const vector<string>& v1, const vector<string>& v2){
    return v1[0] < v2[0];
}

void MainWindow::on_loadButton_clicked()
{
    // open pets file and read for mainTable
    string file = "Pets.csv";

    // uses builder pattern and abstract factory to build a PetDatabaseSortableByName database
    DatabaseBuilder builder;
    DatabaseParser parser;
    parser.setBuilder(&builder);
    parser.parse(file);
    PetDatabaseSortableByName* database = builder.getDatabase();
    database->DisplayRecords();

    // construct main table
    for (unsigned int i = 0; i < database->getSize(); i++){
        std::string name = database->getPet(i)->GetName();
        std::string animal = database->getPet(i)->GetAnimal();

        // need to fix presicion for price *******
        std::ostringstream converter;
        converter << std::setprecision(4) << database->getPet(i)->GetPrice();
        std::string price = converter.str();

        std::string type = database->getPet(i)->GetType();

        int row_number = ui->mainTable->rowCount();
        ui->mainTable->insertRow(ui->mainTable->rowCount());
        ui->mainTable->setItem(row_number, 0,  new QTableWidgetItem(QString::fromStdString(name)));
        ui->mainTable->setItem(row_number, 1,  new QTableWidgetItem(QString::fromStdString(animal)));
        ui->mainTable->setItem(row_number, 2,  new QTableWidgetItem(QString::fromStdString(price)));
        ui->mainTable->setItem(row_number, 3,  new QTableWidgetItem(QString::fromStdString(type)));
    }

    // test?
    NonStackBasedSumVisitor nsbsv;
    database->Accept(&nsbsv);
    cout << nsbsv.getResult() << endl;

    int bundleRow = ui->bundleTable->rowCount();
    BinarySearch s;
    //read from bundles file
    ifstream bundlesFile("Bundles.csv");
    if (bundlesFile.is_open()){
        string line = "";
        vector<vector<string>> items;  //matrix
        while(getline(bundlesFile,line)){
            istringstream ss(line);
            string token = "";
            vector<string> segments;

            //for each line in the file create a vector of tokens to parse through
            while(getline(ss,token,',')){
                segments.push_back(token);
            }

            //Create a second database by searching the main database for the pets in each bundle
            PetDatabaseSortableByName* savingsDatabase = new PetDatabaseSortableByName();
            PetDatabaseSearchableByName* SName = new PetDatabaseSearchableByName(database);
            for (unsigned int i = 2; i < segments.size(); i++){
                SName->setQuery(segments[i]);
                savingsDatabase->AddPet(SName->getPet(s.search(SName)));
            }

            //Use the visitor and composite and composite pattern to get total price of the bundle for each
            //newly created database
            NonStackBasedSumVisitor nsbsv;
            savingsDatabase->Accept(&nsbsv);
            double initialCost = nsbsv.getResult();

            //add to matrix so we can store the data in a table
            segments.push_back(to_string(initialCost));
            items.push_back(segments);
        }

        //table needs to be sorted by name and add data to table
        sort(items.begin(),items.end(),sortMatrix);
        for (unsigned int j = 0; j < items.size(); j++){
            bundleRow = ui->bundleTable->rowCount();
            ui->bundleTable->insertRow(bundleRow);
            ui->bundleTable->setItem(bundleRow,0,new QTableWidgetItem(QString::fromStdString(items[j][0]))); //name of bundle
            ui->bundleTable->setItem(bundleRow,1,new QTableWidgetItem(QString::fromStdString(items[j][1]))); //original price of bundle
            double savings = (stod(items[j].back())-stod(items[j][1]))/stod(items[j].back())*100;  //Calculate savings usings values obtain from visitor pattern
            std::ostringstream converter;
            converter << std::setprecision(3) << savings;
            std::string strSavings = converter.str()+"%";
            ui->bundleTable->setItem(bundleRow,2,new QTableWidgetItem(QString::fromStdString(strSavings)));
        }
    }


    ui->loadButton->setEnabled(false);
    ui->addCartButton->setEnabled(true);
    ui->showCartButton->setEnabled(true);
}





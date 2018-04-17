#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <fstream>
#include <iostream>
#include <QDebug>
#include <QDir>
#include <string>
#include <sstream>
//using namespace std;

#include "databasebuilder.h"
#include "databaseparser.h"
#include "PetDatabase.h"
#include "PetDatabaseSortableByName.h"
#include "BubbleSortDecreasing.h"
#include "BubbleSortIncreasing.h"

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
    ui->showButton->setEnabled(false);

    // SetTable
    ui->mainTable->setColumnCount(4);

    // Current directory
    qDebug() << QDir::currentPath();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loadButton_clicked()
{
    // enable other buttons
    ui->addCartButton->setEnabled(true);
    ui->showButton->setEnabled(true);

    // open pets file and read for mainTable
    string file = "Pets.csv";

    // ********* The maintable must be sorted by name ***********
    // *********** fluffy isnt working ***********
    DatabaseBuilder builder;
    DatabaseParser parser;
    parser.setBuilder(&builder);
    parser.parse(file);
    vector<Pet*> database = builder.getDatabase();
    BubbleSortIncreasing bs;
    PetDatabaseSortableByName petDatabaseSortableByName(database);
    bs.sort(&petDatabaseSortableByName);
    petDatabaseSortableByName.DisplayRecords();


    ui->loadButton->setEnabled(false);
}





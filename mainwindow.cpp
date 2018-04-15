#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <fstream>
#include <iostream>
#include <QDebug>
#include <QDir>
#include <string>
#include <sstream>
using namespace std;

#include "databuilder.h"
#include "parser.h"

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
    // open file and read
    std::ifstream file("Pets.csv");
    DataBuilder builder;
    builder.buildTable(ui->mainTable);
    Parser parser;
    parser.setBuilder(&builder);

    if (file.is_open()){
        std::string line = "";
        while (std::getline(file, line)){
            //some code here to tokenize the line into segements using "," as segmenting parameter
            parser.tokenize(line); // pass line into parser
        }
    }
    ui->mainTable = builder.returnTable();
    file.close();
            /*
            std::vector<std::string> segments;
            std::istringstream ss(line);
            std::string token = "";
            while(std::getline(ss, token, ',')){
                // add everything to database row somehow
                std::cout << token << std::endl;
                segments.push_back(token);
            }
            */
            /*
             * @681 implies we do not use project 1 as a database but rather the tablewidget
             * When we hit checkout later we need to sort the data so I'm unsure how project 1 is being used
            */

            //string type = segments[0];
            //string name = segments[1];
            //double price = stod(segments[4]);
            //string special;   // you might have to look at 4 cases (Gogs, Fish, Bird, Cat cases to store values in special)

            //update table widget rows here

}

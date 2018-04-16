#ifndef DATABUILDER_H
#define DATABUILDER_H

#include "builder.h"
#include <string>
#include <vector>

class DataBuilder : public Builder{
protected:
    QTableWidget* m_table;
public:
    void buildThis(QTableWidget* table){
        m_table = table;
    }


    // American Bulldog
    // Fluffy Ragdoll
    // Diurnal Eagle
    // Freshwater catfish
    // sort by name(Casper on top)
    virtual void add(std::vector<std::vector<std::string> > matrix){
        for (unsigned int i = 0; i < matrix.size(); i++){
            int row_value = m_table->rowCount();
            m_table->insertRow(m_table->rowCount());
            m_table->setItem(row_value,0,  new QTableWidgetItem(QString::fromStdString(matrix[i][1])));
            m_table->setItem(row_value,1,  new QTableWidgetItem(QString::fromStdString(matrix[i][0])));
            m_table->setItem(row_value,2,  new QTableWidgetItem(QString::fromStdString(matrix[i][4])));
            // special attribute
            if (matrix[i][0] == "Bird"){
                if (matrix[i][5] == "FALSE")
                    std::string val = ("Diurnal " + matrix[i][2]);
                else{
                    std::string val = ("Nocturnal " + matrix[i][2]);
                    m_table->setItem(row_value,3,  new QTableWidgetItem(QString::fromStdString(val)));
                }
            }
            else if (matrix[i][0] == "Cat"){
                if (matrix[i][5] == "true1"){ // what the hell?
                    std::string val = ("Fluffy " + matrix[i][2]);
                    m_table->setItem(row_value,3,  new QTableWidgetItem(QString::fromStdString(val)));
                }
                else{
                    std::cout << matrix[i][5] << endl;
                    m_table->setItem(row_value,3,  new QTableWidgetItem(QString::fromStdString(matrix[i][2])));
                }
            }
            else if (matrix[i][0] == "Fish"){
                std::string val = (matrix[i][5] + " " + matrix[i][2]);
                m_table->setItem(row_value,3,  new QTableWidgetItem(QString::fromStdString(val)));
            }
            else
                m_table->setItem(row_value,3,  new QTableWidgetItem(QString::fromStdString(matrix[i][2])));
        }
    }

};

#endif // DATABUILDER_H

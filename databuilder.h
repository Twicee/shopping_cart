#ifndef DATABUILDER_H
#define DATABUILDER_H

#include "builder.h"
#include <vector>

class DataBuilder : public Builder{
protected:
    QTableWidget* m_table;
public:
    virtual void buildTable(QTableWidget* table){
        m_table = table;
    }

    virtual void addRow(std::vector<std::string> row) const{
        int row_value = m_table->rowCount();
        m_table->insertRow(m_table->rowCount());
        m_table->setItem(row_value,0,  new QTableWidgetItem(QString::fromStdString(row[1])));
        m_table->setItem(row_value,1,  new QTableWidgetItem(QString::fromStdString(row[0])));
        m_table->setItem(row_value,2,  new QTableWidgetItem(QString::fromStdString(row[3])));
        m_table->setItem(row_value,3,  new QTableWidgetItem(QString::fromStdString(row[2])));

    }

    virtual QTableWidget* returnTable(){
        return m_table;
    }

};

#endif // DATABUILDER_H

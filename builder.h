#ifndef BUILDER_H
#define BUILDER_H

#include <QTableWidget>
#include <string>
#include <vector>

class Builder{
public:
    virtual void buildTable(QTableWidget* table) =0;
    virtual void addRow(std::vector<std::string> row) const =0;
    virtual QTableWidget* returnTable() =0;

};

#endif // BUILDER_H

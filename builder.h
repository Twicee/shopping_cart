#ifndef BUILDER_H
#define BUILDER_H

#include <QTableWidget>
#include <string>
#include <vector>

class Builder{
public:
    virtual void add(std::vector<std::string> row) =0;
};

#endif // BUILDER_H

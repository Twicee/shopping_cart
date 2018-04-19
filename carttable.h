#ifndef CARTTABLE_H
#define CARTTABLE_H

#include <QTableWidget>
#include <vector>

class cartTable : public QTableWidget{
    Q_OBJECT
public:
    cartTable(QWidget* qw):QTableWidget(qw){};

public slots:
   void AddtoTable(std::vector<QString> itemVector);
};

#endif // CARTTABLE_H

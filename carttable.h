#ifndef CARTTABLE_H
#define CARTTABLE_H

#include <QTableWidget>
#include <vector>

class cartTable : public QTableWidget{
    Q_OBJECT
public:
    cartTable(QWidget* qw):QTableWidget(qw){};

signals:
    void changeLabel(QString);

public slots:
   void checkout();
   void AddtoTable(std::vector<QString> itemVector);
};

#endif // CARTTABLE_H

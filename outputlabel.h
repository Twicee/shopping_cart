#ifndef OUTPUTLABEL_H
#define OUTPUTLABEL_H


#include <QObject>
#include <QLabel>
#include <vector>
#include "nonstackbasedsumvisitor.h"

class outputlabel: public QLabel{
    Q_OBJECT

public:
    outputlabel(QWidget* qw):QLabel(qw){};

public slots:
    void changeText(QString);

};

#endif // OUTPUTLABEL_H

#ifndef ECHEQUIER_H
#define ECHEQUIER_H
#include <QtGui>
#include "case.h"

class Echequier: public QWidget
{
public:
    Echequier(QWidget * parent = 0);
private:
    QGridLayout *tableau;
};

#endif // ECHEQUIER_H

#ifndef ECHEQUIER_H
#define ECHEQUIER_H
#include <QtGui>
#include "case.h"

class Echequier: public QWidget
{
public:
    //constructeur
    Echequier(QWidget * parent = 0);
    //getters
    QGridLayout getEchequier();
    Case* getCase(QPoint position);
    //setters

    //fonctions
    void placerReine(QPoint position);
private:
    QGridLayout *tableau;
    QVector<Case*> listeCases;

};

#endif // ECHEQUIER_H

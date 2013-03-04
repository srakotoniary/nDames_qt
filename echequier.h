#ifndef ECHEQUIER_H
#define ECHEQUIER_H
#include <QtGui>
#include "case.h"

class Echequier: public QWidget
{
public:
    //constructeur
    Echequier(QWidget * parent = 0);
    Echequier(int nb);
    //getters
    QGridLayout getEchequier();
    Case* getCase(int position);
    //setters

    //fonctions
    void placerReine(int presenceReine);
private:
    QGridLayout *tableau;
    QVector<Case*> listeCases;
    int nbDames;

};

#endif // ECHEQUIER_H

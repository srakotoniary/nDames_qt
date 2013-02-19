#ifndef FENETRE_H
#define FENETRE_H

#include <QtGui>
#include "echequier.h"
class Fenetre: public QMainWindow
{
Q_OBJECT

public:
    //constructeurs
    Fenetre();
    Fenetre(int largeur,int hauteur);
    //fonctions
    int getNbDames();

public slots:
    void changerNbDames(int largeur);

private:
   QSlider *m_slider;
   QLCDNumber *m_lcd;
   int nDames;
};


#endif // FENETRE_H

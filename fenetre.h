#ifndef FENETRE_H
#define FENETRE_H

#include <QtGui>
#include "echequier.h"
class Fenetre: public QMainWindow
{
Q_OBJECT

public:
    Fenetre();
    Fenetre(int largeur,int hauteur);

public slots:
    void changerLargeur(int largeur);

private:
   QSlider *m_slider;
   QLCDNumber *m_lcd;
};


#endif // FENETRE_H

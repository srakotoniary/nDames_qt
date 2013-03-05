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
    //getters
    int getNbDames();
    //fonctions
    void AfficheSolution(QString typeAlgo);
    QVector<int> algoBacktrack();

public slots:
    void changerNbDames(int val);
    void faireTourner();

private:
   QSlider *m_slider;
   QLCDNumber *m_lcd;
   QPushButton *lancerAlgo;
   QVBoxLayout *parametreDivers;
   QHBoxLayout *tableauEtParametre;
   QWidget *zoneCentrale;
   QComboBox *listeAlgo;
   int nDames;
   Echequier *echequier;
};


#endif // FENETRE_H

#ifndef FENETRE_H
#define FENETRE_H

#include <QtGui>
#include "echequier.h"
#include "forwardchecking.h"
#include "generateandtest.h"
#include "backtrack.h"
#include "recherchelocal.h"

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

public slots:
    void changerNbDames(int val);
    void faireTourner();
    void rSuivant();
    void rPrecedent();
    void rEffacer();

private:
   QSlider *m_slider;
   QLCDNumber *m_lcd;
   QPushButton *lancerAlgo;
   QPushButton *avancer;
   QPushButton *reculer;
   QPushButton *effacer;
   QVBoxLayout *parametreDivers;
   QHBoxLayout *tableauEtParametre;
   QWidget *zoneCentrale;
   QComboBox *listeAlgo;
   int nDames;
   int nbSol;
   QVector<QVector<int> >listeResultat;
   QVector<int>resultat;
   Echequier *echequier;
};


#endif // FENETRE_H

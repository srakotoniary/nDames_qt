#ifndef ALGO_H
#define ALGO_H

#include <QVector>

class Algo
{
public:
    Algo(int nbR, int choix);

    bool testEchiquier();
    bool placementPossible(int position);

    void affiche();
    QVector<int > getSolution_i(int i);

    int getNbReine();
    int getIter();
    QVector<QVector<int> > getNbSol();

    int nbLigne (int position);
    int nbColonne(int position);

    virtual void execution(int x) = 0;

protected:
    QVector<int > Echiquier;
    int nbReines;
    QVector<QVector<int> > nbSol;
    int nbIter;

};

#endif // ALGO_H

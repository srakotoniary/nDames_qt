#ifndef ALGO_H
#define ALGO_H

#include <QVector>

class Algo
{
public:
    Algo(int nbR);
    QVector<int > generateAndTest(int x);
     QVector<int > testAndGenerate(int x);
    bool placementPossible(int position);
    void affiche();

    bool testEchiquier();

    bool testLigne(int x, int y);
    bool testColonne(int x, int y);
    bool testDiag(int x, int y);

    int nbLigne (int position);
    int nbColonne(int position);
private:
    QVector<int > Echiquier;
    int nbReines;
    QVector<QVector<int> > nbSol;
   //int  Echiquier[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

};

#endif // ALGO_H

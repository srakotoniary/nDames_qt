#ifndef ALGO_H
#define ALGO_H

#include <QVector>

class Algo
{
public:
    Algo(int nbR, int choix);

    //========================================

    bool placementPossible(int position);
    QVector<int > generateAndTest(int x);
    QVector<int > testAndGenerate(int x);
    void backtrack(int x);

    //=========================================
    void initFC();
    void forwardChecking(int x, int nb);
    bool colonneSuivanteImpossible(int position);
    void supprimeDomaine(int position);
    void restaureDomaine(int position);
    //========================================
    void affiche();

    bool testEchiquier();

    bool testLigne(int x, int y);
    bool testColonne(int x, int y);
    bool testDiag(int x, int y);

    int nbLigne (int position);
    int nbColonne(int position);

private:
    QVector<int > Echiquier;
    QVector<bool > domaine;
    int nbReines;
    QVector<QVector<int> > nbSol;
   //int  Echiquier[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

};

#endif // ALGO_H

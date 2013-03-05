#ifndef ALGO_H
#define ALGO_H
#include <QtGui>

class Algo
{
private:
    QVector<QVector<int> > Echiquier;
    int nbReine;

public:
    Algo(int nb);
    int generatetest(int nbReines);
   // QPoint placeReine(int i, int j, Qvector<QPoint> reines); //teste et place (si c'est possible) une reine a la case (i,j)
};

#endif // ALGO_H

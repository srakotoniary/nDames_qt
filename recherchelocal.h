#ifndef RECHERCHELOCAL_H
#define RECHERCHELOCAL_H
#include "algo.h"

class RechercheLocal : public Algo
{
public:
    RechercheLocal(int nb, QVector<int > pl_reines);
    void execution(int x);
    int strategieDeRecherche(int x);
    int conflitReineN(int position);
private:
    QVector<int > pl_reines;
    int nbModif;
};

#endif // RECHERCHELOCAL_H

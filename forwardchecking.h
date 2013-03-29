#ifndef FORWARDCHECKING_H
#define FORWARDCHECKING_H
#include "algo.h"

class ForwardChecking : public Algo
{
public:
    ForwardChecking(int nb);
    void initFC();
    void execution(int x);
    void supprimeDomaine(int position);

};

#endif // FORWARDCHECKING_H

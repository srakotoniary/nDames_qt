#include "generateandtest.h"
#include <iostream>

GenerateAndTest::GenerateAndTest(int nb): Algo(nb,0)
{
    execution(0);
  //  std::cout << "nombre de Sol" << nbSol.size()<<std::endl;
    // std::cout << "nombre Iter" << nbIter <<std::endl;
}

void GenerateAndTest::execution(int x){
    nbIter++;

    //si on a pas examiner toutes les colonnes
    if(x<nbReines)
        for(int j = x; j < Echiquier.size() ; j += nbReines){       //ligne suivante
            if(Echiquier[j] == 0){
                Echiquier[j] = 1;
                execution(x+1);
                Echiquier[j] = 0;
            }
         } else
            if(testEchiquier()){        //si l'echiquier est valide
              //  affiche();
                nbSol.push_back(Echiquier);
         }
}

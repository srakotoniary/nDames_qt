#include "backtrack.h"
#include <iostream>

Backtrack::Backtrack(int nb): Algo(nb,0)
{
    execution(0);
//    std::cout << "nombre de Sol" << nbSol.size()<<std::endl;
//     std::cout << "nombre Iter" << nbIter <<std::endl;
}

void Backtrack::execution(int x){
        nbIter++;
        if(testEchiquier()){    //si l'echiquier verifie les contraintes
           if(x<nbReines)
                for(int j = x; j < Echiquier.size() ; j += nbReines){       //ligne suivante
                    Echiquier[j]=1;
                    execution(x+1);            //colonne suivante
                    Echiquier[j]=0;
                }
           else {
                //    affiche();
                    nbSol.push_back(Echiquier);
               //     std::cout << nbSol.size() <<std::endl;

                }
        }
}

#include "forwardchecking.h"
#include <iostream>

ForwardChecking::ForwardChecking(int nb): Algo(nb,0)
{
    initFC();
    execution(0);
    //std::cout << "nombre de Sol" << nbSol.size()<<std::endl;
    //std::cout << "nombre Iter" << nbIter <<std::endl;
}

void ForwardChecking::execution(int x){
     nbIter++;
     QVector<int > tmp;

     /*
     spec ts = { 5000 / 1000, (5000 % 1000) * 1000 * 1000 };
     nanosleep(&ts, NULL);
     */

     if(x < nbReines){
         for(int j = x; j < Echiquier.size() ; j += nbReines){   //ligne suivante
             tmp = Echiquier;            //sauvegarde le domaine actuel

             if(Echiquier[j] == 1){      //si la position est possible
                 supprimeDomaine(j);            //on supprime les domaines qui interfere avec la position
                 execution(x+1);                //colonne suivante
                 Echiquier=tmp;                 //restaure les domaines
             }
         }
     } else {
         //affiche();
         nbSol.push_back(Echiquier);                       //on sauvegarde la solution
         //std::cout << nbSol.size() <<std::endl;
     }
}

void ForwardChecking::initFC(){
    for(int i=0; i<nbReines*nbReines; i++){
        Echiquier[i]=1;
    }
}


void ForwardChecking::supprimeDomaine(int position){

    int ligne = position / nbReines;
    int colonne = position % nbReines;

    //test ligne
    for (int i = ligne*nbReines; i < ligne*nbReines + nbReines; i++){
        if(i != position)
            if(Echiquier[i]==1)
                Echiquier[i]=0;
    }

    //test colonne
    for (int i = colonne; i<nbReines * nbReines; i = i + nbReines ){
        if ( i != position)
            if(Echiquier[i]==1)
                Echiquier[i]=0;
    }

    //std::cout<<"test colonne ok"<<std::endl;

    //Digonale sud-est
    if(colonne+1 != nbReines)
    for (int i = position + (nbReines+1); i < nbReines * nbReines; i = i+ (nbReines+1) ){
        if((i%nbReines) == 0)   //si c'est la premiere colonne on break (cas ou on a depasser la limite du bord a droite)
            break;
        if(Echiquier[i]==1)
            Echiquier[i]=0;
    }

    //Digonale nord-ouest
    if(colonne != 0)
    for (int i = position - (nbReines + 1); i >= 0 ; i = i - (nbReines + 1) ){
        if((i%nbReines)+1 == nbReines)
            break;
        if(Echiquier[i]==1)
            Echiquier[i]=0;
    }

    //Diagonale Nord-est
    if(colonne+1 != nbReines)
    for (int i = position- (nbReines-1); i >= 0 ; i= i - (nbReines - 1) ){

        if(Echiquier[i]==1)
            Echiquier[i]=0;
        if((i%nbReines)+1 == nbReines)
            break;
    }

    //Diagonale Sud-ouest
    if(colonne != 0)
    for (int i = position + (nbReines-1); i < nbReines * nbReines; i = i + (nbReines - 1) ){
        if((i%nbReines)+1 == nbReines)
            break;
        if(Echiquier[i]==1)
            Echiquier[i]=0;
    }

}

//=========================================================================================================

/*
void Algo::fc(int x){
    nbIter++;
    if(x<nbReines)
        for(int j = x; j < Echiquier.size() ; j += nbReines){   //ligne suivante
            if(placementPossible(j)){
                 Echiquier[j]=1;
                 fc(x+1);            //colonne suivante
                 Echiquier[j]=0;              //restaure les domaines

            }
        }
   else {
            affiche();
            nbSol.push_back(Echiquier);
            std::cout << nbSol.size() <<std::endl;

        }


}
*/

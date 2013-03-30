#include "recherchelocal.h"
#include <iostream>

RechercheLocal::RechercheLocal(int nb, QVector<int > pl_reines): Algo(nb,0), pl_reines(pl_reines), nbModif(1)
{
    for(int i = 0; i< nb; i++){
        Echiquier[pl_reines[i]]=1;
    }
    affiche();
    nbSol.push_back(Echiquier);

    execution(0);

//  std::cout << "nombre de Sol" << nbSol.size()<<std::endl;
//  std::cout << "nombre Iter" << nbIter <<std::endl;
}

void RechercheLocal::execution(int x){

    int sTmp;

    while(!testEchiquier() && nbModif != 0){    //tant que l'echiquier n'est pas valide ou qu'il y a fait maj

        sTmp = strategieDeRecherche(pl_reines[x]);
        if(sTmp != nbReines)
            pl_reines[x] = sTmp;

        // affiche();
        x++;
        if(x == pl_reines.size()){   //si on parcouru tout l'espace de recherche
            x = 0;
            nbModif = 0;
        }
    }
}

int RechercheLocal::strategieDeRecherche(int x){
    nbIter++;
    int conflit = conflitReineN(x);         //récupere le nb de conflit avec d'autre reines
    int nouvellePosition = x;

    int tmpc;

    int colonne = x % nbReines;

    if(conflit != 0){
        //recherche la premiere meilleur configuration
        for(int j = colonne; j < Echiquier.size() ; j += nbReines){       //ligne suivante
            tmpc = conflitReineN(j);
            if(tmpc < conflit){             //si il y a une config voisine de meilleur qualité
                conflit = tmpc;
                nouvellePosition = j;
            }
        }
        if(nouvellePosition != x){      //si il y a une maj
            Echiquier[x] = 0;
            Echiquier[nouvellePosition]=1;
           // affiche();
            nbModif++;
            nbSol.push_back(Echiquier);

            return nouvellePosition;
        }

     }
    return nbReines; //si il n'y a pas de meilleur solution on retourne un QVector<int > vide
}


//retourne le nb de conflit avec d'autres reines
int RechercheLocal::conflitReineN(int position){
    int compteurConflit = 0;

    int ligne = position / nbReines;
    int colonne = position % nbReines;

    //test ligne
    for (int i = ligne*nbReines; i < ligne*nbReines + nbReines; i++){
        if(i != position)
            if(Echiquier[i]==1)
                compteurConflit++;
    }

    //test colonne
    for (int i = colonne; i<nbReines * nbReines; i = i + nbReines ){
        if ( i != position)
            if(Echiquier[i]==1)
                compteurConflit++;
    }

    //std::cout<<"test colonne ok"<<std::endl;

    //Digonale sud-est
    if(colonne+1 != nbReines)
    for (int i = position + (nbReines+1); i < nbReines * nbReines; i = i+ (nbReines+1) ){
        if((i%nbReines) == 0)   //si c'est la premiere colonne on break (cas ou on a depasser la limite du bord a droite)
            break;
        if(Echiquier[i]==1)
            compteurConflit++;
    }

    //Digonale nord-ouest
    if(colonne != 0)
    for (int i = position - (nbReines + 1); i >= 0 ; i = i - (nbReines + 1) ){
        if((i%nbReines)+1 == nbReines)
            break;
        if(Echiquier[i]==1)
            compteurConflit++;
    }

    //Diagonale Nord-est
    if(colonne+1 != nbReines)
    for (int i = position- (nbReines-1); i >= 0 ; i= i - (nbReines - 1) ){

        if(Echiquier[i]==1)
            compteurConflit++;
        if((i%nbReines)+1 == nbReines)
            break;
    }

    //Diagonale Sud-ouest
    if(colonne != 0)
    for (int i = position + (nbReines-1); i < nbReines * nbReines; i = i + (nbReines - 1) ){
        if((i%nbReines)+1 == nbReines)
            break;
        if(Echiquier[i]==1)
            compteurConflit++;
    }

    return compteurConflit;
}

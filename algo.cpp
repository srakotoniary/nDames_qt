#include "algo.h"
#include <iostream>

//int Echiquier[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

Algo::Algo(int nbR, int choix):nbReines(nbR), nbIter(0)
{
    for(int i=0; i<nbR*nbR; i++){
            Echiquier.push_back(0);
    }

/*
    affiche();
    Echiquier[9] = 1;

    //teste placementPossible
    std::cout << std::endl;
    for(int i = 0; i < nbReines*nbReines; i++)  {
        std::cout << "|" <<placementPossible(i);
        if((i+1)%nbReines == 0 )
        std::cout << std::endl;
    }
*/
}

bool Algo::testEchiquier(){
    for(int i=0; i<nbReines*nbReines; i++)
        if(!placementPossible(i) && Echiquier[i] == 1)    //si un des test echoue on retourne false
         //   std::cout << i << "="  <<!placementPossible(i) << "&&" << Echiquier[i] << std::endl;
                return 0;
    return true;
}

void Algo::affiche(){

    std::cout << std::endl;
    for(int i = 0; i < nbReines*nbReines; i++){
        std::cout << Echiquier[i] << "|";
        if((i+1)%nbReines == 0 )
            std::cout << std::endl;
    }

}

QVector<int > Algo::getSolution_i(int i){
    return nbSol[i];
}


int Algo::getNbReine(){
    return nbReines;
}


int Algo::getIter(){
    return nbIter;
}
QVector<QVector<int> > Algo::getNbSol(){
    return nbSol;
}

bool Algo::placementPossible(int position){
    int ligne = position / nbReines;
    int colonne = position % nbReines;

    //test ligne
    for (int i = ligne*nbReines; i < ligne*nbReines + nbReines; i++){
        if(i != position)
            if(Echiquier[i]==1)
                return false;
    }

    //test colonne
    for (int i = colonne; i<nbReines * nbReines; i = i + nbReines ){
        if ( i != position)
            if (Echiquier[i]==1)
                return false;
    }

    //std::cout<<"test colonne ok"<<std::endl;

    //Digonale sud-est
    if(colonne+1 != nbReines)
    for (int i = position + (nbReines+1); i < nbReines * nbReines; i = i+ (nbReines+1) ){
        if((i%nbReines) == 0)   //si c'est la premiere colonne on break (cas ou on a depasser la limite du bord a droite)
            break;
        if (Echiquier[i]==1)
            return false;
    }

    //Digonale nord-ouest
    if(colonne != 0)
    for (int i = position - (nbReines + 1); i >= 0 ; i = i - (nbReines + 1) ){
        if((i%nbReines)+1 == nbReines)
            break;
        if (Echiquier[i]==1)
            return false;
    }

    //Diagonale Nord-est
    if(colonne+1 != nbReines)
    for (int i = position- (nbReines-1); i >= 0 ; i= i - (nbReines - 1) ){
        if (Echiquier[i]==1)
            return false;
        if((i%nbReines)+1 == nbReines)
            break;
    }

    //Diagonale Sud-ouest
    if(colonne != 0)
    for (int i = position + (nbReines-1); i < nbReines * nbReines; i = i + (nbReines - 1) ){
        if((i%nbReines)+1 == nbReines)
            break;
        if (Echiquier[i]==1)
            return false;
    }

    return true;
}


/*
bool Algo::placementPossible(int position){
   // affichage
    int ligne = position / nbReines;
    int colonne = position % nbReines;
    //std::cout<<"ligne:"<<ligne<<" colonne : "<<colonne<<std::endl;
    //test ligne
    for (int i=0;i<nbReines;i++ ){

        if ((nbReines*ligne+ i)!=position)
            if (Echiquier[nbReines*ligne+ i]==1)
                return false;
    }
    //std::cout<<"test ligne ok"<<std::endl;
    //test colonne
    for (int i=0;i<nbReines;i++ ){
        if ((nbReines*ligne+i)!=position)
            if (Echiquier[nbReines*i+colonne]==1)
                return false;
    }
    //std::cout<<"test colonne ok"<<std::endl;
    //haut gauche
    int position2=position;
    while(nbLigne(position2)>=0||(nbColonne(position2)>=0)){
        if(Echiquier[position2]==1 )
            return false;
        position2=position2-(nbReines+1);
        if (nbLigne(position2)==nbLigne(position))
            break;
        if (nbColonne(position2)==nbColonne(position))break; } //bas droit

    int position3=position;
    while(nbLigne(position3)<nbReines||(nbColonne(position3)<nbReines)){
        if(Echiquier[position3]==1 )
            return false;
        position3=position3+(nbReines+1);
        if (nbLigne(position3)==nbLigne(position))
            break;
        if (nbColonne(position3)==nbColonne(position))
            break;
    }
 //   std::cout<<"test diagonale vers la doite ok"<<std::endl;
    //haut droit
    int position4=position;
    while(nbLigne(position4)>=0||(nbColonne(position4)<nbReines)){
        if(Echiquier[position4]==1) {
         //   std::cout<<"test"<<std::endl;
            return false;
        }
        position4=position4-(nbReines-1);
        if (nbLigne(position4)==nbLigne(position))
            break;
        if (nbColonne(position4)==nbColonne(position))
            break;
    }
    //bas gauche
    int position5=position;
    while(nbLigne(position5)>nbReines||(nbColonne(position5)>=0)){
        if(Echiquier[position5]==1)
            return false;
        position5=position5+(nbReines-1);
        if (nbLigne(position5)==nbLigne(position))
            break;
        if (nbColonne(position5)==nbColonne(position))
            break;
    }
  //  std::cout<<"test diagonale vers la gauche ok"<<std::endl;
    return true;
}
*/


int Algo::nbLigne (int position){
    return (position/nbReines);
}
int Algo::nbColonne(int position){
    return (position %nbReines);
}

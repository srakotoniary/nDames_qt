#include "algo.h"
#include <iostream>

//int Echiquier[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
int nbIter;
Algo::Algo(int nbR, int choix):nbReines(nbR)
{
    nbIter = 0;
    for(int i=0; i<nbR*nbR; i++){
            Echiquier.push_back(0);
    }
  //  std::cout << '\n' <<Echiquier.size() << std::endl;
  //  Echiquier[9] = 1;

   // affiche();

    //teste placementPossible
    /*std::cout << std::endl;
    for(int i = 0; i < nbReines*nbReines; i++)  {
        std::cout << "|" <<placementPossible(i);
        if((i+1)%nbReines == 0 )
        std::cout << std::endl;
    }*/

    affiche();

    if(choix == 0)
        generateAndTest(0);
    else if(choix == 1)
        //testAndGenerate(0);
        backtrack(0);
    else if(choix == 2){
        initFC();
        forwardChecking(0,nbReines);
    }
    std::cout << "nombre de Sol" << nbSol.size()<<std::endl;
    std::cout << "nombre Iter" << nbIter <<std::endl;
}


bool Algo::testEchiquier(){
    for(int i=0; i<nbReines*nbReines; i++)
        if(!placementPossible(i) && Echiquier[i] == 1)    //si un des test echoue on retourne false
         //   std::cout << i << "="  <<!placementPossible(i) << "&&" << Echiquier[i] << std::endl;
                return 0;
    return true;
}


QVector<int> Algo::generateAndTest(int x){
    nbIter++;
    QVector<int>  tmp;

    if(nbReines+x <= nbReines*nbReines){ //generate...
        for(int j = 0 + x; j <(x+nbReines); j++){

            if(Echiquier[j] == 0){

                Echiquier[j] = 1;

                tmp = generateAndTest(x+nbReines);
                if(!tmp.empty())
                    nbSol.push_back(tmp);

                Echiquier[j] = 0;

            }
        }

    } else {  //...And Test
        if(testEchiquier()){

            affiche();
            //nbSol.push_back(Echiquier);
            //std::cout << nbSol.size() <<std::endl;
            return Echiquier;
        }

    }
    tmp.clear();
    return tmp;
}

void Algo::backtrack(int x){
    nbIter++;
    if(testEchiquier()){    //si l'echiquier verifie les contraintes
       if(x<nbReines)
            for(int j = x; j < Echiquier.size() ; j += nbReines){       //ligne suivante
                Echiquier[j]=1;
                backtrack(x+1);            //colonne suivante
                Echiquier[j]=0;
            }
       else {
                affiche();
                nbSol.push_back(Echiquier);
                std::cout << nbSol.size() <<std::endl;

            }
    }

}

bool Algo::colonneSuivanteImpossible(int position){
    for(int i = position; i<Echiquier.size(); i = i+ nbReines)
        if(Echiquier[i]==1)
            return false;
    return true;

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
void Algo::initFC(){
    for(int i=0; i<nbReines*nbReines; i++){
        Echiquier[i]=1;
    }
}



void Algo::forwardChecking(int x, int nb){
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
                supprimeDomaine(j);         //on supprime les domaines qui interfere avec la position
                forwardChecking(x+1,nb-1);        //colonne suivante
                Echiquier=tmp;              //restaure les domaines
            }
        }

    } else {
        affiche();
        nbSol.push_back(Echiquier);                       //on sauvegarde la solution
        std::cout << nbSol.size() <<std::endl;
    }


}

void Algo::supprimeDomaine(int position){

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

//======================================================================================================

void Algo::affiche(){

    std::cout << std::endl;
    for(int i = 0; i < nbReines*nbReines; i++){
        std::cout << Echiquier[i] << "|";
        if((i+1)%nbReines == 0 )
            std::cout << std::endl;
    }

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

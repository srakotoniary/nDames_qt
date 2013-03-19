#include "algo.h"
#include <iostream>

QVector<int> essai;

int n = 4;

//int Echiquier[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

void initEssai(){
    for(int i=0; i<4; i++)
        essai.push_back(0);
}

//essai

Algo::Algo(int nbR):nbReines(nbR)
{
    for(int i=0; i<nbR*nbR; i++){
            Echiquier.push_back(0);
    }
   // nbSol = 0;
}
/*
bool Algo::testEchiquier(){
   // std::cout << "ok" << std::endl;
   // std::cout << "======="<< Echiquier.size()<<"======" << std::endl;

    for(int i=0; i<Echiquier.size(); i++)
        for(int j=0; j<Echiquier.size(); j++)
            if(!testLigne(i,j) || !testColonne(i,j))    //si un des test echoue on retourne false
                    return false;

    return true;
}


bool Algo::testColonne(int x, int y){
    for(int i = 0; i < nbReines; i++)
        if(Echiquier[i][y]==1 && i != x)    //si il y a est une reine sur la colonne y et différentes de la pos de x,y
            return false;
    return true;
}

bool Algo::testDiag(int x, int y){
    for(int i = 0; i < nbReines; i++)
        for(int j = 0; j < nbReines; j++)
            if(Echiquier[i][j]==1 && i != x)    //si il y a est une reine sur la colonne y et différentes de la pos de x,y
                return false;
    return true;
}

bool Algo::testLigne(int x, int y){
    for(int i = 0; i < nbReines; i++)
        if(Echiquier[x][i]==1 && i != y)    //si il y a est une reine sur la ligne x et différentes de la pos de x,y
            return false;
    return true;
}

QVector<QVector<int> > Algo::generateAndTest(int x, int y, int nbReine){

    QVector<QVector<int> > tmp;
    nbReine--;
//C
  if(nbReine >= 0){ //generate...
      for(int j = 0; j < nbReines; j++){
        //      std::cout << "["<< nbReine << "," << j << "]" << std::endl;
        //      std::cout << "["<< nbReine << "," << j << "] " << Echiquier[nbReine][j] << std::endl;
                    if(Echiquier[nbReine][j] == 0){
                        Echiquier[nbReine][j] = 1;
                        tmp = generateAndTest(nbReine,j, nbReine);
                        affiche();
                        std::cout << tmp.empty() <<std::endl;
                        if(!tmp.empty()){
                            std::cout << "ok" << std::endl;

                            nbSol.push_back(tmp);

                        }
                        Echiquier[nbReine][j] = 0;
                    }
            }
  } else {  //...And Test
    if(testEchiquier()){
        std::cout << "ok" << std::endl;

        affiche();
       return Echiquier;
    } else {
        std::cout << "nok" << std::endl;

        tmp.clear();
        return tmp;
    }
  }

}

void Algo::affiche(){

  for(int i=0; i<nbReines; i++){ // std::cout << "faux" << std::endl;
    for(int j=0; j<nbReines; j++)
      std::cout << Echiquier[i][j] << ", ";
  std::cout << std::endl;
  }
  std::cout << nbSol.size() << std::endl;
}

*/

QVector<int> Algo::generateAndTest(int x, int y, int nbReine){

    QVector<int>  tmp;
    nbReine--;
//C
  if(nbReine >= 0){ //generate...
      for(int j = 0; j < nbReines; j++){
        //      std::cout << "["<< nbReine << "," << j << "]" << std::endl;
        //      std::cout << "["<< nbReine << "," << j << "] " << Echiquier[nbReine][j] << std::endl;
                    if(Echiquier[nbReine][j] == 0){
                        Echiquier[nbReine][j] = 1;
                        tmp = generateAndTest(nbReine,j, nbReine);
                        affiche();
                        std::cout << tmp.empty() <<std::endl;
                        if(!tmp.empty()){
                            std::cout << "ok" << std::endl;

                            nbSol.push_back(tmp);

                        }
                        Echiquier[nbReine][j] = 0;
                    }
            }
  } else {  //...And Test
    if(testEchiquier()){
        std::cout << "ok" << std::endl;

        affiche();
       return Echiquier;
    } else {
        std::cout << "nok" << std::endl;

        tmp.clear();
        return tmp;
    }
  }

}

void Algo::affiche(){
    for(int i = 0; i < nbReines*nbReines; i++){
        std::cout << essai[i] << std::endl;
        if(nbReines/i == 0 )
            std::cout << std::endl;
    }
}



bool Algo::placementPossible(int position){
   // affichage
    int ligne = position / nbReines;
    int colonne = position % nbReines; std::cout<<"ligne:"<<ligne<<" colonne : "<<colonne<<std::endl;
    //test ligne
    for (int i=0;i<nbReines;i ){
        if ((nbReines*ligne+ i)!=position)
            if (Echiquier[nbReines*ligne+ i]==1)
                return false;
    }
    std::cout<<"test ligne ok"<<std::endl;
    //test colonne
    for (int i=0;i<nbReines;i ){
        if ((nbReines*ligne+i)!=position)
            if (Echiquier[nbReines*i+colonne]==1)
                return false;
    }
    std::cout<<"test colonne ok"<<std::endl;
    //haut gauche
    int position2=position;
    while(nbLigne(position2)>=0||(nbColonne(position2)>=0)){
        if(Echiquier[position2]==1)
            return false;
        position2=position2-(nbReines+1);
        if (nbLigne(position2)==nbLigne(position))
            break;
        if (nbColonne(position2)==nbColonne(position))break; } //bas droit
    int position3=position;
    while(nbLigne(position3)<nbReines||(nbColonne(position3)<nbReines)){
        if(Echiquier[position3]==1)
            return false;
        position3=position3+(nbReines+1);
        if (nbLigne(position3)==nbLigne(position))
            break;
        if (nbColonne(position3)==nbColonne(position))
            break;
    }
    std::cout<<"test diagonale vers la doite ok"<<std::endl;
    //haut droit
    int position4=position;
    while(nbLigne(position4)>=0||(nbColonne(position4)<nbReines)){
        if(Echiquier[position4]==1) {
            std::cout<<"test"<<std::endl;
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
    std::cout<<"test diagonale vers la gauche ok"<<std::endl;
    return true;
}

int Algo::nbLigne (int position){
    return (position/nbReines);
}
int Algo::nbColonne(int position){
    return (position %nbReines);
}

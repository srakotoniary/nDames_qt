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
    QVector<int> tmp;
    for(int i=0; i<nbR; i++){
        for(int j=0; j<nbR; j++)
            tmp.push_back(0);
        Echiquier.push_back(tmp);
        tmp.clear();
    }
   // nbSol = 0;
}

bool Algo::testEchiquier(){
    std::cout << "ok" << std::endl;
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
  nbReine--;
//std::cout << "[ok]" << std::endl;
  if(nbReine >= 0){ //generate...
      for(int j = 0; j < nbReines; j++){
    //      std::cout << "["<< nbReine << "," << j << "]" << std::endl;
    //      std::cout << "["<< nbReine << "," << j << "] " << Echiquier[nbReine][j] << std::endl;
                    if(Echiquier[nbReine][j] == 0){
                        Echiquier[nbReine][j] = 1;
                        nbSol.push_back(generateAndTest(nbReine,j, nbReine));

                        Echiquier[nbReine][j] = 0;
                    }
            }
  } else {  //...And Test
   // if(testEchiquier()){
        affiche();
        std::cout << "=============" << std::endl;
     //   return Echiquier;
    // }//else
        //return 0;
    }
  //return 1;
  return Echiquier;
}

void Algo::affiche(){

  for(int i = 0; i<nbReines; i++){ // std::cout << "faux" << std::endl;
    for(int j = 0; j<nbReines
        ; j++)
      std::cout << Echiquier[i][j] << ", ";
  std::cout << std::endl;
  }
  std::cout << nbSol.size() << std::endl;
}

/*
bool Algo::positionPossible(int x, int y){
    return true;
}

void Algo::affiche(){
    for(int i = 0; i < nbReines*nbReines; i++){
        std::cout << essai[i] << std::endl;
        if(nbReines/i == 0 )
            std::cout << std::endl;
    }
}
*/

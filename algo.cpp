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
/*
bool Algo::testEchiquier(){
  int nbLine = 0, nbColumn = 0, nbDiag = 0;

  //test ligne
  for(int i = 0; i < nbReines; i++){
    for(int j = 0; j < nbReines; j++){
      if(Echiquier[i][j] == 1)
    nbLine++;
      if(Echiquier[j][i] == 1)
    nbColumn++;
    }

    for(int i = 0; i < nbReines; i++){
        for(int j = 0; j < nbReines; j++){
            if(Echiquier[i][j] == 1){
                std::cout << "=====" << i <<"," << j <<"========" << std::endl;
                for(int di = 1, dj = 1; di < nbReines && dj < nbReines; di++,dj++){
                    std::cout << "=============" << std::endl;
                    if(Echiquier[i+di][j+dj] == 1 && (di+i < nbReines && dj+j < nbReines) )
                        nbDiag++;
                    std::cout << Echiquier[i-di][j+dj] <<"=============" << std::endl;
                    if(Echiquier[i-di][j+dj] == 1 && (i-di < nbReines && dj+j < nbReines))
                        nbDiag++;
                    std::cout << "=============" << std::endl;
                }

                for(int di = nbReines-1, dj = nbReines-1; di > 0 && dj > 0; di--,dj--){
                    if(Echiquier[i+di][j-dj] == 1 && (di+i >= 0 && j-dj >= 0))
                        nbDiag++;
                    if(Echiquier[i-di][j-dj] == 1 && (i-di >= 0 && j-dj >= 0))
                        nbDiag++;
                //if(essaiEchiquier[i-di][j+dj] == 1 && (i-di > 0 && dj+j > 0))
                //std::cout << i-di << ",a" << j+dj << std::endl;
                }
            }
        }
    }

   if(nbLine > 1 || nbColumn > 1 || nbDiag > 1){
     // std::cout << "faux" << std::endl;
      return false;
    }
    else{
      nbLine = 0;
      nbColumn = 0;
      nbDiag = 0;

    }
  }

  return true;
}
*/


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
    if(testEchiquier()){
        affiche();
        std::cout << "=============" << std::endl;
        return Echiquier;
     }//else
        //return 0;
    }
  //return 1;
  //return Echiquier;
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

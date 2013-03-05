#include "algo.h"
#include <iostream>

Algo::Algo(int nb): nbReine(nb)
{
    QVector<int> ligne;

    for(int i = 0; i < nb; i++){
        for(int j = 0; j < nb; j++)
            ligne.push_back(0);
        Echiquier.push_back(ligne);
        ligne.clear();
    }

    for(int i = 0; i < nb; i++){
        for(int j = 0; j < nb; j++)
            std::cout << Echiquier[i][j];
       std::cout << std::endl;
    }
}

int Algo::generatetest(int nbReines){
/*
    QPair<int,QPoint> Generates;
    QVector<QPoint> Generate;
    QVector<QPoint> Solution;
    QPoint reine;
    // int ligne = nbReines;
    // int colonne = nbReines;

    //Boucle
    for(int ri = 0; ri<nbReines; ri++){
        for(int rj = 0; rj<nbReines;rj++){

            //initialise la position de la reine "fixe"
            reine.setX(ri);
            reine.setY(rj);
            Generate.push_back(reine);

            //Parcours des différents solution pour une reine "fixe" à (ri,rj)
            for(int i = 0; i<nbReines; i++){
                for(int j = 0; j<nbReines; j++){
                    //Initialise la position de la reine suivante placé en (i,j), si la position est différente de la reine "fixe"
                    if(!(i==ri && j==rj)){
                        reine.setX(i);
                        reine.setY(j);
                        Generate.push_back(reine);
                    }
                }
                //fin

            }

            //Un cas
        }
    }
*/
    return 0;
}

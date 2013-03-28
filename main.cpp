#include <QApplication>
#include "fenetre.h"
#include "case.h"

#include "algo.h"
#include "generateandtest.h"
#include "backtrack.h"
#include "forwardchecking.h"

#include <iostream>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //Fenetre fenetre;
    //Fenetre fenetre3(500,300);
    //fenetre.show();

    //Algo *a = new Algo(5,2);
    QVector<int > E;

    //Réalise l'algo generate and test avec 5 dames
    GenerateAndTest *gt = new GenerateAndTest(5);

    //Réalise l'algo backtrak avec 5 dames
    Backtrack *bt = new Backtrack(5);

    //Réalise l'algo ForwardCheking avec 5 dames
    ForwardChecking *fc = new ForwardChecking(5);

    //Récupere la 3 ieme solution de FC
    E = fc->getSolution_i(2);
    std::cout << std::endl;

    for(int i = 0; i<fc->getNbReine()*fc->getNbReine() ; i++){
        std::cout << E[i] << "|";
        if((i+1)%fc->getNbReine() == 0 )
            std::cout << std::endl;
    }

    return 0;//app.exec();
}

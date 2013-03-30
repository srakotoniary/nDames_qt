#include <QApplication>
#include "fenetre.h"
#include "case.h"

#include "algo.h"
#include "generateandtest.h"
#include "backtrack.h"
#include "forwardchecking.h"
#include "recherchelocal.h"

#include <iostream>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Fenetre fenetre;
    Fenetre fenetre3(500,300);
    fenetre.show();

    /*

    //  Exemple utilisation recherche local pour 5 reines

      //creer un vecteur contenant les positions des reines

      QVector<int > p;
        p.push_back(10);  //colonne 1
        p.push_back(1);   //colonne 2
        p.push_back(2);     //colonne 3
        p.push_back(8);     //colonne 4
        p.push_back(14);     //colonne 5

        RechercheLocal *r = new RechercheLocal(5, p);

        r->affiche();
    */

    return app.exec();
}

#include "echequier.h"
#include <iostream>

Echequier::Echequier(QWidget * parent) : QWidget(parent)
{
    setMinimumSize(700,500);
    nbDames=0;
    listeCases.clear();
}

Echequier::Echequier(int nb)
{
    setMinimumSize(700,500);
    listeCases.clear();
    nbDames=nb;

    tableau = new QGridLayout(this);



    for(int i=0;i<nbDames;i++){
        int alternance=0;
        for (int j=0;j<nbDames;j++){
            std::cout<<"ajout case"<<std::endl;
            if(i%2==0){
                if(alternance==0){
                    Case *c = new Case(i,j,true);
                    tableau->addWidget(c,i,j);
                    listeCases.push_back(c);
                    alternance++;
                }

                else {
                    Case *c = new Case(i,j,false);
                    tableau->addWidget(c,i,j);
                    listeCases.push_back(c);
                    alternance--;
                }
            }
            else{
                if(alternance==0){
                    Case *c = new Case(i,j,false);
                    tableau->addWidget(c,i,j);
                    listeCases.push_back(c);
                    alternance++;
                }

                else {
                    Case *c = new Case(i,j,true);
                    tableau->addWidget(c,i,j);
                    listeCases.push_back(c);
                    alternance--;
                }
            }
        }
    }


}


Case* Echequier::getCase(int position){

    return listeCases[position];
}

void Echequier::placerReine(int presenceReine){
    getCase(presenceReine)->setDameSurLaCase(true);

}


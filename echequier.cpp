#include "echequier.h"
#include <iostream>

Echequier::Echequier(QWidget * parent) : QWidget(parent)
{
    setMinimumSize(700,500);
    nbDames=0;
}

Echequier::Echequier(int nb)
{
    setMinimumSize(700,500);
    nbDames=nb;

    QImage m_image = QImage(QSize(100,100), QImage::Format_RGB32);
    m_image.fill(qRgb(255, 255, 255));
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


Case* Echequier::getCase(QPoint position){
    int i= position.x();
    int j= position.y();
    return listeCases[i*nbDames+j];
}

void Echequier::placerReine(int presenceReine){
    //getCase(position)->setDameSurLaCase(true);

}


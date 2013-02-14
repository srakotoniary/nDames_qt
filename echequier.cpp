#include "echequier.h"
#include <iostream>

Echequier::Echequier(QWidget * parent) : QWidget(parent)
{
    setMinimumSize(500,100);

    QImage m_image = QImage(QSize(100,100), QImage::Format_RGB32);
    m_image.fill(qRgb(255, 255, 255));
    tableau = new QGridLayout(this);



    for(int i=0;i<4;i++){
        int alternance=0;
        for (int j=0;j<4;j++){
            std::cout<<"ajout case"<<std::endl;
            if(i%2==0){
                if(alternance==0){
                    tableau->addWidget(new Case(i,j,true),i,j);
                    alternance++;
                }

                else {
                    tableau->addWidget(new Case(i,j,false),i,j);
                    alternance--;
                }
            }
            else{
                if(alternance==0){
                    tableau->addWidget(new Case(i,j,false),i,j);
                    alternance++;
                }

                else {
                    tableau->addWidget(new Case(i,j,true),i,j);
                    alternance--;
                }
            }
        }
    }


}


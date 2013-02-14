#include "echequier.h"

Echequier::Echequier(QWidget * parent) : QWidget(parent)
{
    setMinimumSize(400,100);

    QImage m_image = QImage(QSize(100,100), QImage::Format_RGB32);
    m_image.fill(qRgb(255, 255, 255));
    tableau = new QGridLayout;



    for(int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            tableau->addWidget(new Case(i,j),i,j);
        }
    }

}


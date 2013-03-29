#include "case.h"
#include <iostream>

Case::Case(): QLabel()
{
    position=QPoint(-1,-1);
    dameSurLaCase=false;
    couleur=NULL;
    setMinimumSize(50,50);
    setText("coord :"+position.x()+position.y());
    // Set background colour to black
}

Case::Case(int x, int y, bool coul): QLabel()
{
    position=QPoint(x,y);
    dameSurLaCase=false;
    couleur =coul;
    setMinimumSize(50,50);
    if (couleur==true) {setStyleSheet("QLabel { background-color : white; color : white; }");}
    else {setStyleSheet("QLabel { background-color : black; color : white; }");}

/*
    if (couleur==true) {setText("Blanc"); setStyleSheet("QLabel { background-color : green; color : white; }");}
    else {setText("Noir"); setStyleSheet("QLabel { background-color : blue; color : white; }");}
    std::cout<<"coordonnees de la case: "<<position.x()<<","<<position.y()<<std::endl;
*/

}
bool Case::getDameSurLaCase()
{
    return dameSurLaCase;
}

QPoint Case::GetPosition()
{
    return position;
}

bool Case::getCouleur()
{
    return couleur;
}

void Case::setDameSurLaCase(bool val)
{
    dameSurLaCase=val;
    //QString CurrentDir = QDir::currentPath();
    //std::cout<<CurrentDir.toStdString()<<std::endl;
    QPixmap pixmap("image/quee.svg");
    //std::cout<<"largeur" <<pixmap.isNull()<<std::endl;

    setPixmap(pixmap.scaledToWidth(this->width()));
    setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
}

void Case::setPosition(int x, int y)
{
    position=QPoint(x,y);
}

void Case::setCouleur(bool val)
{
    couleur=val;
}

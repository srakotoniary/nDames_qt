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
    if (couleur==true) setText("Blanc");
    else setText("noir");
    std::cout<<"coordonnees de la case: "<<position.x()<<","<<position.y()<<std::endl;
    // Set background colour to black

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
    setText("Reine");
}

void Case::setPosition(int x, int y)
{
    position=QPoint(x,y);
}

void Case::setCouleur(bool val)
{
    couleur=val;
}

#include "case.h"

Case::Case(): QWidget()
{
    position=QPoint(-1,-1);
    dameSurLaCase=false;
}

Case::Case(int x, int y): QWidget()
{
    position=QPoint(x,y);
    dameSurLaCase=false;

}
bool Case::getDameSurLaCase()
{
    return dameSurLaCase;
}

QPoint Case::GetPosition()
{
    return position;
}

void Case::setDameSurLaCase(bool val)
{
    dameSurLaCase=val;
}

void Case::setPosition(int x, int y)
{
    position=QPoint(x,y);
}

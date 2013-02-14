#ifndef CASE_H
#define CASE_H
#include <QtGui>
class Case: public QLabel
{
public:
    Case();
    Case(int x ,int y,bool coul);
    //getters
    QPoint GetPosition();
    bool getDameSurLaCase();
    QPalette getPalette();
    bool getCouleur();
    //setters
    void setDameSurLaCase(bool val);
    void setPosition(int x, int y);
    void setCouleur(bool val);

private:
    bool dameSurLaCase;
    QPoint position;
    QPalette palette;
    bool couleur;

};

#endif // CASE_H

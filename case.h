#ifndef CASE_H
#define CASE_H
#include <QtGui>
class Case: public QWidget
{
public:
    Case();
    Case(int x ,int y);
    //getters
    QPoint GetPosition();
    bool getDameSurLaCase();
    //setters
    void setDameSurLaCase(bool val);
    void setPosition(int x, int y);

private:
    bool dameSurLaCase;
    QPoint position;

};

#endif // CASE_H

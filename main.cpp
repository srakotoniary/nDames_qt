#include <QApplication>
#include "fenetre.h"
#include "case.h"
#include "algo.h"
#include <iostream>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //Fenetre fenetre;
    //Fenetre fenetre3(500,300);
    //fenetre.show();

    Algo *a = new Algo(5,0);

    //a->generateAndTest(0);
   // a->testAndGenerate(0);
 //   a->backtrack(0);
  //  a->forwardChecking(0,4);
    return 0;//app.exec();
}

#include <QApplication>
#include "fenetre.h"
#include "case.h"
#include "algo.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Fenetre fenetre;
    //Fenetre fenetre3(500,300);
    fenetre.show();

   // Algo *a = new Algo(4);



    return app.exec();
}

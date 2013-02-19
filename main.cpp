#include <QApplication>
#include "fenetre.h"
#include "case.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Fenetre fenetre;
    //Fenetre fenetre3(500,300);
    fenetre.show();






    return app.exec();
}

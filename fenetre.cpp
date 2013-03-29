#include "fenetre.h"
#include <iostream>

Fenetre::Fenetre() : QMainWindow()
{

    //Definition de la fenetre
    setFixedSize(1000, 800);

    //Definition de quitter
    QMenu *menuFichier = menuBar()->addMenu("&Fichier");
    QAction *actionQuitter = new QAction("&Quitter", this);
    menuFichier->addAction(actionQuitter);

    connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));

    //Definion comboBox
    listeAlgo = new QComboBox();
    listeAlgo->addItem("Generate&Test");
    listeAlgo->addItem("Backtrack");
    listeAlgo->addItem("ForwardChecking");

    //tuto site du zero
    m_lcd = new QLCDNumber(this);
    m_lcd->setSegmentStyle(QLCDNumber::Flat);
    m_lcd->move(20, 20);
    m_lcd->setFixedSize(250,150);

    m_slider = new QSlider(Qt::Horizontal, this);
    m_slider->setGeometry(10, 60, 100, 20);
    m_slider->setRange(0,10);
    m_slider->setValue(0);

    QObject::connect(m_slider, SIGNAL(valueChanged(int)), m_lcd, SLOT(display(int))) ;
    QObject::connect(m_slider, SIGNAL(valueChanged(int)), this, SLOT(changerNbDames(int))) ;

    //Definir parametre cote
    parametreDivers = new QVBoxLayout;
    parametreDivers->addWidget(listeAlgo);
    parametreDivers->addWidget(m_lcd);
    parametreDivers->addWidget(m_slider);
    lancerAlgo = new QPushButton("Lancer");
    QObject::connect(lancerAlgo,SIGNAL(clicked()),this, SLOT(faireTourner())) ;
    parametreDivers->addWidget(lancerAlgo);

    //Definition widget central
    zoneCentrale = new QWidget;
    tableauEtParametre= new QHBoxLayout;
    echequier =new Echequier();
    tableauEtParametre->addLayout(parametreDivers);
    tableauEtParametre->addWidget(echequier);

    zoneCentrale->setLayout(tableauEtParametre);
    setCentralWidget(zoneCentrale);
}

Fenetre::Fenetre(int largeur,int hauteur) : QMainWindow()
{
//A faire pour une taille donnée
}

void Fenetre::changerNbDames(int val)
{
   nDames=val;
   delete echequier;
   echequier= new Echequier(nDames);
   tableauEtParametre->addWidget(echequier);

}

int Fenetre::getNbDames()
{
    return nDames;
}

void Fenetre::faireTourner()
{
    AfficheSolution(listeAlgo->currentText());
}



void Fenetre::AfficheSolution(QString typeAlgo)
{

    if (typeAlgo=="Backtrack")
    {
        std::cout<<typeAlgo.toStdString()<<std::endl;
        QVector<int > E;

        //Réalise l'algo backtrack
        std::cout<<getNbDames()<<std::endl;
        Backtrack *bt = new Backtrack(getNbDames());

        //Récupere la 3 ieme solution de FC
        E = bt->getSolution_i(0);
        std::cout << std::endl;

        for(int i = 0; i<bt->getNbReine()*bt->getNbReine() ; i++){
            std::cout << E[i] << "|";
            if((i+1)%bt->getNbReine() == 0 )
                std::cout << std::endl;
            if(E[i]==1)echequier->placerReine(i);
        }

    }
        else if (typeAlgo=="ForwardChecking")
                {
                    QVector<int > E;

                    //Réalise l'algo forwardchecking
                    ForwardChecking *fc = new ForwardChecking(getNbDames());

                    //Récupere la 3 ieme solution de FC
                    E = fc->getSolution_i(0);
                    std::cout << std::endl;

                    for(int i = 0; i<fc->getNbReine()*fc->getNbReine() ; i++){
                        std::cout << E[i] << "|";
                        if((i+1)%fc->getNbReine() == 0 )
                            std::cout << std::endl;
                        if(E[i]==1)echequier->placerReine(i);
                    }
                }

                else if (typeAlgo=="Generate&Test")
                        {
                            QVector<int > E;
                            std::cout<<typeAlgo.toStdString()<<std::endl;
                            //Réalise l'algo generate and test
                            GenerateAndTest *gt = new GenerateAndTest(getNbDames());

                            //Récupere la 3 ieme solution de FC
                            E = gt->getSolution_i(0);
                            std::cout << std::endl;

                            for(int i = 0; i<gt->getNbReine()*gt->getNbReine() ; i++){
                                std::cout << E[i] << "|";
                                if((i+1)%gt->getNbReine() == 0 )
                                    std::cout << std::endl;
                                if(E[i]==1)echequier->placerReine(i);
                            }
                        }

}


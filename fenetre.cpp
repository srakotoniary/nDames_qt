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
    listeAlgo->addItem("Ac-1");

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
        /*QVector<int> resultat = new QVector<int>;
        resultat.clear();
        for(int i=0;i<resultat.size();i++)
        {
            if (resultat[i]==1)
            echequier->placerReine(i);
        }*/
    }
        else if (typeAlgo=="Ac-1")
                {
                    std::cout<<typeAlgo.toStdString()<<std::endl;
                }
                else if (typeAlgo=="Generate&Test")
                        {
                            std::cout<<typeAlgo.toStdString()<<std::endl;
                        }

}


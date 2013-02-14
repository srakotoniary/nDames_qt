#include "fenetre.h"

Fenetre::Fenetre() : QMainWindow()
{

    //Definition de la fenetre
    setFixedSize(750, 500);

    //Definition de quitter
    QMenu *menuFichier = menuBar()->addMenu("&Fichier");
    QAction *actionQuitter = new QAction("&Quitter", this);
    menuFichier->addAction(actionQuitter);

    connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));

    //Definion barre d'outils
    QComboBox *listeAlgo = new QComboBox();
    listeAlgo->addItem("Generate&Test");
    listeAlgo->addItem("Backtrack");
    listeAlgo->addItem("Ac-1");

    //tuto site du zero
    m_lcd = new QLCDNumber(this);
    m_lcd->setSegmentStyle(QLCDNumber::Flat);
    m_lcd->move(50, 20);

    m_slider = new QSlider(Qt::Horizontal, this);
    m_slider->setGeometry(10, 60, 150, 20);
    m_slider->setRange(0,500);
    QObject::connect(m_slider, SIGNAL(valueChanged(int)), m_lcd, SLOT(display(int))) ;
    QObject::connect(m_slider, SIGNAL(valueChanged(int)), this, SLOT(changerLargeur(int))) ;

    //Definir parametre cote
    QVBoxLayout *parametreDivers = new QVBoxLayout;
    parametreDivers->addWidget(listeAlgo);
    parametreDivers->addWidget(m_lcd);
    parametreDivers->addWidget(m_slider);
    parametreDivers->addWidget(new QPushButton("Lancer"));

    //Definition widget central
    QWidget *zoneCentrale = new QWidget;
    QHBoxLayout *tableauEtParametre= new QHBoxLayout;
    Echequier *tableau =new Echequier();
    tableauEtParametre->addWidget(tableau);
    tableauEtParametre->addLayout(parametreDivers);
    zoneCentrale->setLayout(tableauEtParametre);
    setCentralWidget(zoneCentrale);
}

Fenetre::Fenetre(int largeur,int hauteur) : QMainWindow()
{

    //Definition de la fenetre
    setFixedSize(largeur, hauteur);


    //Definition de quitter
    QMenu *menuFichier = menuBar()->addMenu("&Fichier");
    QAction *actionQuitter = new QAction("&Quitter", this);
    menuFichier->addAction(actionQuitter);

    connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));

    //Definion barre d'outils
    QComboBox *listeAlgo = new QComboBox();
    listeAlgo->addItem("Generate&Test");
    listeAlgo->addItem("Backtrack");
    listeAlgo->addItem("Ac-1");


    //tuto site du zero
    m_lcd = new QLCDNumber(this);
    m_lcd->setSegmentStyle(QLCDNumber::Flat);
    m_lcd->move(50, 20);

    m_slider = new QSlider(Qt::Horizontal, this);
    m_slider->setGeometry(10, 60, 150, 20);
    m_slider->setRange(0, 500);
    QObject::connect(m_slider, SIGNAL(valueChanged(int)), m_lcd, SLOT(display(int))) ;
    QObject::connect(m_slider, SIGNAL(valueChanged(int)), this, SLOT(changerLargeur(int))) ;

    //Definir parametre cote
    QVBoxLayout *parametreDivers = new QVBoxLayout;
    parametreDivers->addWidget(listeAlgo);
    parametreDivers->addWidget(m_lcd);
    parametreDivers->addWidget(m_slider);
    parametreDivers->addWidget(new QPushButton("Lancer"));


    //Definition widget central
    QWidget *zoneCentrale = new QWidget;
    QHBoxLayout *tableauEtParametre= new QHBoxLayout;
    QGridLayout *tableau = new QGridLayout;

    tableauEtParametre->addLayout(tableau);
    tableauEtParametre->addLayout(parametreDivers);

    zoneCentrale->setLayout(tableauEtParametre);
    setCentralWidget(zoneCentrale);
}

void Fenetre::changerLargeur(int largeur)
{
    setFixedSize(750+largeur, 500);
}

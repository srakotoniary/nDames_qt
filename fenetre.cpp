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

    //Definion comboBox
    QComboBox *listeAlgo = new QComboBox();
    listeAlgo->addItem("Generate&Test");
    listeAlgo->addItem("Backtrack");
    listeAlgo->addItem("Ac-1");

    //tuto site du zero
    m_lcd = new QLCDNumber(this);
    m_lcd->setSegmentStyle(QLCDNumber::Flat);
    m_lcd->move(20, 20);

    m_slider = new QSlider(Qt::Horizontal, this);
    m_slider->setGeometry(10, 60, 100, 20);
    m_slider->setRange(4,10);
    m_slider->setValue(4);
    QObject::connect(m_slider, SIGNAL(valueChanged(int)), m_lcd, SLOT(display(int))) ;
    QObject::connect(m_slider, SIGNAL(valueChanged(int)), this, SLOT(changerNbDames(int))) ;

    //Definir parametre cote
    QVBoxLayout *parametreDivers = new QVBoxLayout;
    parametreDivers->addWidget(listeAlgo);
    parametreDivers->addWidget(m_lcd);
    parametreDivers->addWidget(m_slider);
    parametreDivers->addWidget(new QPushButton("Lancer"));

    //Definition widget central
    QWidget *zoneCentrale = new QWidget;
    QHBoxLayout *tableauEtParametre= new QHBoxLayout;
    echequier =new Echequier();
    tableauEtParametre->addWidget(echequier);
    tableauEtParametre->addLayout(parametreDivers);
    zoneCentrale->setLayout(tableauEtParametre);
    setCentralWidget(zoneCentrale);
}

Fenetre::Fenetre(int largeur,int hauteur) : QMainWindow()
{


}

void Fenetre::changerNbDames(int val)
{
   nDames=val;
}

int Fenetre::getNbDames()
{
    return nDames;
}

void Fenetre::AfficheSolution(QVector<QPoint> Resultat)
{
    for(int i=0;i<Resultat.size();i++){
        echequier->placerReine(Resultat[i]);
    }
}


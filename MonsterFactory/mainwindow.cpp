#include "mainwindow.h"
#include <QCoreApplication>
#include "MonsterStructures/energia.h"
#include "MonsterStructures/maldad.h"
#include "MonsterStructures/materia.h"
#include "MonsterStructures/mounstro.h"
#include "DataStructures/cola.h"
#include "MonsterStructures/energythread.h"
#include "MonsterStructures/maldadthread.h"
#include "MonsterStructures/materiathread.h"
#include "./ui_mainwindow.h"
Cola<Mounstro*>* cola = new Cola<Mounstro*>();

// Esto despues se tiene que hacer mas lindo por que si no va a terminar siendo un desastre
Cola<Energia*>* colaEnergia = new Cola<Energia*>();
Cola<Maldad*>* colaMaldad = new Cola<Maldad*>();
Cola<Materia*>* colaMateria = new Cola<Materia*>();

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    EnergyThread* energyThread = new EnergyThread(1, colaEnergia);
    energyThread -> start();

    MaldadThread* maldadThread = new MaldadThread(1, colaMaldad);
    maldadThread -> start();

    MateriaThread* materiaThread = new MateriaThread(1, colaMateria);
    materiaThread -> start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_test_clicked()
{

    Energia* energia = new Energia();
    Maldad* maldad = new Maldad();
    Materia* materia = new Materia();
    Mounstro* mounstro = new Mounstro(energia -> type, materia -> type, maldad -> type);
    cola->push(mounstro);
    qDebug() << mounstro -> type;
}


void MainWindow::on_pushButton_clicked()
{
    if(!(colaEnergia -> isEmpty() && colaMaldad -> isEmpty() && colaMateria -> isEmpty())){
    qDebug() << colaEnergia -> pop() -> data -> type;
    qDebug() << colaMaldad -> pop() -> data -> type;
    qDebug() << colaMateria -> pop() -> data -> type;
    } else {
        qDebug() << "Funciono";
    }
}


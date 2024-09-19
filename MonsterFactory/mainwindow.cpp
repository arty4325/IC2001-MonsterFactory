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
#include "Etapas/combinador.h"
#include "./ui_mainwindow.h"

// Esto despues se tiene que hacer mas lindo por que si no va a terminar siendo un desastre
Cola<Energia*>* colaEnergia = new Cola<Energia*>();
Cola<Maldad*>* colaMaldad = new Cola<Maldad*>();
Cola<Materia*>* colaMateria = new Cola<Materia*>();
Cola<Mounstro*>* colaMounstros = new Cola<Mounstro*>();
EnergyThread* energyThread = new EnergyThread(1, colaEnergia);
MaldadThread* maldadThread = new MaldadThread(1, colaMaldad);
MateriaThread* materiaThread = new MateriaThread(1, colaMateria);
Combinador* combinador = new Combinador(1, colaMounstros, colaEnergia, colaMaldad, colaMateria);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    energyThread -> start();
    maldadThread -> start();
    materiaThread -> start();
    combinador -> start();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_maldadSpinBox_valueChanged(int arg1)
{
    qDebug() << arg1;
    maldadThread -> changeTime(arg1);
}


void MainWindow::on_materiaSpinBox_valueChanged(int arg1)
{
    qDebug() << arg1;
    materiaThread -> changeTime(arg1);
}


void MainWindow::on_energiaSpinBox_valueChanged(int arg1)
{
    qDebug() << arg1;
    energyThread -> changeTime(arg1);
}


void MainWindow::on_combinadorSpinBox_valueChanged(int arg1)
{
    qDebug() << arg1;
    combinador -> changeTime(arg1);
}


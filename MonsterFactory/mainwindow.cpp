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
#include "labelthread.h"
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
LabelThread* labelThread = new LabelThread(1, colaEnergia, colaMaldad, colaMateria, colaMounstros);




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    energyThread -> start();
    //energyThread -> setLabel(ui->energyLabel);
    labelThread -> setEmergyLabel(ui->energyLabel);
    maldadThread -> start();
    //maldadThread -> setLabel(ui->maldadLabel);
    labelThread -> setMaldadLabel(ui->maldadLabel);
    materiaThread -> start();
    labelThread -> setMateriaLabel(ui->materiaLabel);
    combinador -> start();
    labelThread -> setMounstroLabel(ui->mounstrosLabel);
    labelThread -> start();
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





void MainWindow::on_checkBox_stateChanged(int arg1)
{
    // Pausa Energia
    qDebug() << arg1;
    energyThread->stop(arg1);
}


void MainWindow::on_checkBox_2_stateChanged(int arg1)
{
    // Pausa Materia
    qDebug() << arg1;
    materiaThread -> stop(arg1);

}


void MainWindow::on_checkBox_3_stateChanged(int arg1)
{
    // Pausa Maldad
    qDebug() << arg1;
    maldadThread -> stop(arg1);

}


void MainWindow::on_checkBox_4_stateChanged(int arg1)
{
    // Pausa Combinador (Generador de Mounstros)
    qDebug() << arg1;
    combinador -> stop(arg1);
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    // Cambiar el tamaño de lista Energia
    //qDebug() << (colaEnergia->getCantItems() > arg1) << " " << colaEnergia -> getCantItems() << " " << arg1;
    colaEnergia->changeMax(arg1);

}


void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    // Cambiar el tamano de la lista materia
    //qDebug() << (colaMateria->getCantItems() > arg1) << " " << colaMateria -> getCantItems() << " " << arg1;
    colaMateria->changeMax(arg1);
}


void MainWindow::on_spinBox_3_valueChanged(int arg1)
{
    // Cambiar el tamano de la lista maldad
    //qDebug() << (colaMaldad->getCantItems() > arg1) << " " << colaMaldad -> getCantItems() << " " << arg1;
    colaMaldad->changeMax(arg1);

}





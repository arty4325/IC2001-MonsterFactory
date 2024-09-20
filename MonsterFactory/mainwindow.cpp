#include "mainwindow.h"
#include <QCoreApplication>
#include "MonsterStructures/energia.h"
#include "MonsterStructures/maldad.h"
#include "MonsterStructures/materia.h"
#include "MonsterStructures/mounstro.h"
#include "DataStructures/cola.h"
#include "DataStructures/listaOrdenada.h"
#include "MonsterStructures/energythread.h"
#include "MonsterStructures/maldadthread.h"
#include "MonsterStructures/materiathread.h"
#include "Etapas/combinador.h"
#include "Etapas/horno.h"
#include "labelthread.h"
#include "./ui_mainwindow.h"


// Esto despues se tiene que hacer mas lindo por que si no va a terminar siendo un desastre
Cola<Energia*>* colaEnergia = new Cola<Energia*>();
Cola<Maldad*>* colaMaldad = new Cola<Maldad*>();
Cola<Materia*>* colaMateria = new Cola<Materia*>();
Cola<Mounstro*>* colaMounstros = new Cola<Mounstro*>();
ListaOrdenada<Mounstro*>* basurero = new ListaOrdenada<Mounstro*>();
EnergyThread* energyThread = new EnergyThread(1, colaEnergia);
MaldadThread* maldadThread = new MaldadThread(1, colaMaldad);
MateriaThread* materiaThread = new MateriaThread(1, colaMateria);
Combinador* combinador = new Combinador(1, colaMounstros, basurero, colaEnergia, colaMaldad, colaMateria);
LabelThread* labelThread = new LabelThread(1, colaEnergia, colaMaldad, colaMateria, colaMounstros, basurero);

// Creacion de bandejas
Cola<Mounstro*>* primeraBandeja = new Cola<Mounstro*>();
Cola<Mounstro*>* segundaBandeja = new Cola<Mounstro*>();
Cola<Mounstro*>* terceraBandeja = new Cola<Mounstro*>();
Cola<Mounstro*>* cuartaBandeja = new Cola<Mounstro*>();

Horno* horno = new Horno(1, primeraBandeja, segundaBandeja, terceraBandeja, cuartaBandeja);





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
    labelThread -> setBasureroLabel(ui->basureroLabel);
    labelThread -> start();
    horno->start();
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





void MainWindow::on_hornoSpinBox_valueChanged(int arg1)
{
    // Aqui se cambia el tiempo del horno
    horno -> changeTime(arg1);
}


void MainWindow::on_bandeja1CheckBox_stateChanged(int arg1)
{
    // Parar o reanudar bandeja 1
}


void MainWindow::on_bandeja2CheckBox_stateChanged(int arg1)
{
    // Parar o reanudar bandeja 2
}


void MainWindow::on_bandeja3CheckBox_stateChanged(int arg1)
{
    // Parar o reanudar bandeja 3
}


void MainWindow::on_bandeja4CheckBox_stateChanged(int arg1)
{
    // Parar o reanudar bandeja 4
}


void MainWindow::on_bandeja1SpinBox_valueChanged(int arg1)
{
    // Cant items bandeja 1
}


void MainWindow::on_bandeja2SpinBox_valueChanged(int arg1)
{
    // Cant items bandeja 2
}


void MainWindow::on_bandeja3SpinBox_valueChanged(int arg1)
{
    // Cant items bandeja 3
}


void MainWindow::on_bandeja4SpinBox_valueChanged(int arg1)
{
    // Cant items bandeja 4
}


#include "mainwindow.h"
#include <QCoreApplication>
#include "MonsterStructures/energia.h"
#include "MonsterStructures/maldad.h"
#include "MonsterStructures/materia.h"
#include "MonsterStructures/mounstro.h"
#include "DataStructures/cola.h"
#include "./ui_mainwindow.h"
Cola<Mounstro*>* cola = new Cola<Mounstro*>();

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    if(!(cola -> isEmpty())){
    qDebug() << cola -> pop() -> data -> type;
    } else {
        qDebug() << "Funciono";
    }
}


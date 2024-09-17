#include "mainwindow.h"
#include "MonsterStructures/energia.h"
#include "MonsterStructures/maldad.h"
#include "MonsterStructures/materia.h"
#include "./ui_mainwindow.h"

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
    qDebug() << energia -> type << " " << maldad -> type << " " << materia -> type;
}


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
#include "Etapas/calidad.h"
#include "Etapas/almacen.h"
#include "labelthread.h"
#include "./ui_mainwindow.h"
#include "Etapas/pedidomanager.h"
#include "Etapas/entrega.h"
#include "Etapas/pedido.h"
#include "colamounstros.h"
#include "ReadingStructures/readtextfiles.h"



readTextFiles* readingStructure = new readTextFiles();
Cola<Energia*>* colaEnergia = new Cola<Energia*>();
Cola<Maldad*>* colaMaldad = new Cola<Maldad*>();
Cola<Materia*>* colaMateria = new Cola<Materia*>();
Cola<Mounstro*>* colaMounstros = new Cola<Mounstro*>();
Cola<Mounstro*>* colaCalidad = new Cola<Mounstro*>();
ListaOrdenada<Mounstro*>* basurero = new ListaOrdenada<Mounstro*>();
EnergyThread* energyThread = new EnergyThread(1, colaEnergia);
MaldadThread* maldadThread = new MaldadThread(1, colaMaldad);
MateriaThread* materiaThread = new MateriaThread(1, colaMateria);
Combinador* combinador = new Combinador(2, colaMounstros, basurero, colaEnergia, colaMaldad, colaMateria);

// Creacion de bandejas
Cola<Mounstro*>* primeraBandeja = new Cola<Mounstro*>();
Cola<Mounstro*>* segundaBandeja = new Cola<Mounstro*>();
Cola<Mounstro*>* terceraBandeja = new Cola<Mounstro*>();
Cola<Mounstro*>* cuartaBandeja = new Cola<Mounstro*>();


// Creacion de almacen
ListaOrdenada<Mounstro*>* listaAlmacen = new ListaOrdenada<Mounstro*>();
ListaOrdenada<Mounstro*>* colaEntregados = new ListaOrdenada<Mounstro*>();
ListaOrdenada<Mounstro*>* colaAlmacen = new ListaOrdenada<Mounstro*>();


// Creacion de pedidos
ListaOrdenada<Pedido*>* listaPedidos = new ListaOrdenada<Pedido*>();
ListaOrdenada<Pedido*>* listaPedidosPrioridad = new ListaOrdenada<Pedido*>();
ListaOrdenada<Pedido*>* listaPedidosEntregados = new ListaOrdenada<Pedido*>();

Horno* horno = new Horno(2, colaMounstros, primeraBandeja, segundaBandeja, terceraBandeja, cuartaBandeja, colaCalidad);

PedidoManager* pedidoManager = new PedidoManager(3, listaPedidos, listaPedidosPrioridad, listaAlmacen);

Entrega* entrega = new Entrega(3, listaPedidos, listaPedidosPrioridad, listaAlmacen, listaPedidosEntregados);


// Almacen

Almacen* almacen = new Almacen(listaAlmacen, colaEntregados, colaAlmacen);


LabelThread* labelThread = new LabelThread(1, colaEnergia, colaMaldad, colaMateria, colaMounstros, basurero,
                                           primeraBandeja, segundaBandeja, terceraBandeja, cuartaBandeja,
                                           colaCalidad, listaAlmacen, colaEntregados, colaAlmacen, listaPedidosPrioridad,
                                           listaPedidos, listaPedidosEntregados);




// Calidad

Calidad* calidad = new Calidad(1, colaCalidad, basurero, almacen);




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // Esto crea las ventanas que permiten ver el setado de la fabrica en tiempo real
    _colaMounstros = new ColaMounstros(this, colaMounstros);
    itinerarioHorno = new ItinerarioHorno(this, primeraBandeja, segundaBandeja, terceraBandeja, cuartaBandeja);
    verAlmacen = new VerAlmacen(this, listaAlmacen);
    verPedidosEntregados = new VerPedidosEntregados(this, listaPedidosEntregados);
    verPedidosPrioridad = new PedidosPrioridad(this, listaPedidosPrioridad);
    verPedidosLabel = new PedidosLabel(this, listaPedidos);
    verShowHistory = new ShowHistory(this);
    ui->setupUi(this);
    energyThread -> start();
    labelThread -> setEmergyLabel(ui->energyLabel);
    maldadThread -> start();;
    labelThread -> setMaldadLabel(ui->maldadLabel);
    materiaThread -> start();
    labelThread -> setMateriaLabel(ui->materiaLabel);
    combinador -> start();
    labelThread -> setMounstroLabel(ui->mounstrosLabel);
    labelThread -> setBasureroLabel(ui->basureroLabel);
    labelThread -> setHorno1Label(ui->bandeja1Label);
    labelThread -> setHorno2Label(ui->bandeja2Label);
    labelThread -> setHorno3Label(ui->bandeja3Label);
    labelThread -> setHorno4Label(ui->bandeja4Label);
    labelThread -> setCalidadLabel(ui->calidadLabel);
    labelThread -> setAlmacenLabel(ui->almacenLabel);
    labelThread -> setEntregadosLabel(ui->almacenEntregadosLabel);
    labelThread -> setNoEntregadosLabel(ui->almacenPorEntregarLabel);
    labelThread -> setEntregaPrioridadLabel(ui->entregaPrioridadLabel);
    labelThread -> setEntregaLabel(ui -> entregaLabel);
    labelThread -> setPedidosEntregados(ui ->pedidosEntregadosLabel);

    labelThread -> start();
    horno->start();
    calidad -> start();
    pedidoManager -> start();
    entrega -> start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_maldadSpinBox_valueChanged(int arg1)
{
    maldadThread -> changeTime(arg1);
}

void MainWindow::on_materiaSpinBox_valueChanged(int arg1)
{
    materiaThread -> changeTime(arg1);
}

void MainWindow::on_energiaSpinBox_valueChanged(int arg1)
{
    energyThread -> changeTime(arg1);
}

void MainWindow::on_combinadorSpinBox_valueChanged(int arg1)
{
    combinador -> changeTime(arg1);
}





void MainWindow::on_checkBox_stateChanged(int arg1)
{
    energyThread->stop(arg1);
}


void MainWindow::on_checkBox_2_stateChanged(int arg1)
{
    materiaThread -> stop(arg1);
}


void MainWindow::on_checkBox_3_stateChanged(int arg1)
{
    maldadThread -> stop(arg1);

}


void MainWindow::on_checkBox_4_stateChanged(int arg1)
{
    combinador -> stop(arg1);
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    colaEnergia->changeMax(arg1);

}


void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    colaMateria->changeMax(arg1);
}


void MainWindow::on_spinBox_3_valueChanged(int arg1)
{
    colaMaldad->changeMax(arg1);

}





void MainWindow::on_hornoSpinBox_valueChanged(int arg1)
{
    horno -> changeTime(arg1);
}


void MainWindow::on_bandeja1CheckBox_stateChanged(int arg1)
{
    horno ->changeFirstBlocked(arg1);
}


void MainWindow::on_bandeja2CheckBox_stateChanged(int arg1)
{
    horno ->changeSecondBlocked(arg1);
}


void MainWindow::on_bandeja3CheckBox_stateChanged(int arg1)
{
    horno ->changeThirdBlocked(arg1);
}


void MainWindow::on_bandeja4CheckBox_stateChanged(int arg1)
{
    horno ->changeFourthBlocked(arg1);
}


void MainWindow::on_bandeja1SpinBox_valueChanged(int arg1)
{
    horno -> changeMaxPrimeraBandeja(arg1);
}


void MainWindow::on_bandeja2SpinBox_valueChanged(int arg1)
{
    horno -> changeMaxSegundaBandeja(arg1);
}


void MainWindow::on_bandeja3SpinBox_valueChanged(int arg1)
{
    horno -> changeMaxTerceraBandeja(arg1);
}


void MainWindow::on_bandeja4SpinBox_valueChanged(int arg1)
{
    horno -> changeMaxCuartaBandeja(arg1);
}


void MainWindow::on_calidadSpinBox_valueChanged(int arg1)
{
    colaCalidad ->changeMax(arg1);
}


void MainWindow::on_bandeja2CheckBox_2_stateChanged(int arg1)
{
    calidad ->stop(arg1);
}


void MainWindow::on_inspector1SpinBox_valueChanged(int arg1)
{
    calidad ->changeFirstProbability(arg1);
}


void MainWindow::on_inspector2SpinBox_valueChanged(int arg1)
{
    calidad -> changeSecondProbability(arg1);
}


#include <QTimer>

void MainWindow::on_pushButton_clicked()
{
    _colaMounstros->show();

    // Crear un temporizador
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [=]() {
        _colaMounstros->printColaMounstros();
    });
    timer->start(1000);
}


void MainWindow::on_itinerarioHorno_clicked()
{
    itinerarioHorno -> show();
    QTimer* timer = new QTimer(this);

    connect(timer, &QTimer::timeout, [=](){
        itinerarioHorno->printHorno();
    });
    timer->start(1000);
}




void MainWindow::on_verAlmacen_clicked()
{
    verAlmacen -> show();
    QTimer* timer = new QTimer(this);

    connect(timer, &QTimer::timeout, [=](){
        verAlmacen->printAlmacen();
    });
    timer->start(1000);
}


void MainWindow::on_pedidosEntregados_clicked()
{
    verPedidosEntregados->show();
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [=](){
        verPedidosEntregados->printPedidos();
    });
    timer->start(1000);
}


void MainWindow::on_pedidosPrioridad_clicked()
{
    verPedidosPrioridad -> show();
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [=](){
        verPedidosPrioridad->printPedidosPrioridad();
    });
    timer->start(1000);
}


void MainWindow::on_pedidos_clicked()
{
    verPedidosLabel -> show();
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [=](){
        verPedidosLabel ->PrintPedidos();
    });
    timer->start(1000);
}


void MainWindow::on_pushButton_2_clicked()
{
    verShowHistory -> show();
    verShowHistory ->printData(readingStructure->read(1));
}


void MainWindow::on_pushButton_3_clicked()
{
    verShowHistory -> show();
    verShowHistory ->printData(readingStructure->read(2));
}


void MainWindow::on_historialPrimerInspector_clicked()
{
    verShowHistory -> show();
    verShowHistory ->printData(readingStructure->read(3));
}


void MainWindow::on_historialSegundoInspector_clicked()
{
    verShowHistory -> show();
    verShowHistory ->printData(readingStructure->read(4));
}


void MainWindow::on_historialEntregados_clicked()
{
    verShowHistory -> show();
    verShowHistory ->printData(readingStructure->read(5));
}


void MainWindow::on_historialAlmacen_clicked()
{
    // Como el almacen cambia en tiempo real si el pedido esta entregado o no, se arma en ejecucion el historial
    QString var = "";
    for(int i = 0; i < colaAlmacen->cantItems; i++){
        Mounstro* mounstroAlmacen;
        mounstroAlmacen = colaAlmacen ->ver(i);
        var +=
            QString::number(mounstroAlmacen -> Consecutivo)
            += " Energia: " + mounstroAlmacen -> energia
            += " Materia: " + mounstroAlmacen -> material
            += " Maldad: " + mounstroAlmacen -> maldad
            += " Creacion: " + (mounstroAlmacen ->Creacion).toString("yyyy-MM-dd hh:mm:ss")
            += " Bandeja Horneo: " + QString::number(mounstroAlmacen ->bandejaHorneo)
            += " Estado: " + QString(mounstroAlmacen -> enAlmacen ? "true" : "false")
            += " Pedido: " + mounstroAlmacen ->pedido
            += " Entrega: " + mounstroAlmacen ->tiempoEntrega.toString("yyyy-MM-dd hh:mm:ss")
            += "\n"
            ;

    }
    verShowHistory -> show();
    verShowHistory -> printData(var);
}


void MainWindow::on_historialPedidos_clicked()
{

    QString data = readingStructure->read(6);
    data.replace("=", " ");
    verShowHistory->show();
    verShowHistory->printData(data);
}


void MainWindow::on_pausarTodo_stateChanged(int arg1)
{
    energyThread -> stop(arg1);
    maldadThread -> stop(arg1);
    materiaThread -> stop(arg1);
    combinador -> stop(arg1);
    horno -> stop(arg1);
    pedidoManager -> stop(arg1);
    entrega -> stop(arg1);
    calidad -> stop(arg1);
}


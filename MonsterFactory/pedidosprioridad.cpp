#include "pedidosprioridad.h"
#include "ui_pedidosprioridad.h"

PedidosPrioridad::PedidosPrioridad(QWidget *parent, ListaOrdenada<Pedido*>* listaPedidosPrioridad)
    : QDialog(parent)
    , ui(new Ui::PedidosPrioridad)
{
    ui->setupUi(this);
    this->listaPedidosPrioridad = listaPedidosPrioridad;
}

PedidosPrioridad::~PedidosPrioridad()
{
    delete ui;
}


void PedidosPrioridad::printPedidosPrioridad(){
    QString var = "";
    for(int i = 0; i < listaPedidosPrioridad->cantItems; i++){
        var += listaPedidosPrioridad->ver(i)->getName();
    }
    ui->labelPedidosPrioridad->setText(var);
}



/**
void ColaMounstros::printColaMounstros(){
    QString var = "";
    for(int i = 0; i < colaMounstros->getCantItems(); i++ ){
        var += colaMounstros->getElementoEnIndice(i)->type + "\n";
    }
    ui->infoColaMounstros->setText(var);
}
**/

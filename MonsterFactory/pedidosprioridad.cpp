#include "pedidosprioridad.h"
#include "ui_pedidosprioridad.h"

PedidosPrioridad::PedidosPrioridad(QWidget *parent, ListaOrdenada<Pedido*>* listaPedidosPrioridad) // Laben permite ver los pedidos en prioridad
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


void PedidosPrioridad::printPedidosPrioridad(){ // Toma los pedidios que estan en prioridad y los mustra
    QString var = "";
    for(int i = 0; i < listaPedidosPrioridad->cantItems; i++){
        var += listaPedidosPrioridad->ver(i)->getName();
    }
    ui->labelPedidosPrioridad->setText(var);
}




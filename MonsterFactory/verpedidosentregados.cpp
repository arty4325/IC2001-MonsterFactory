#include "verpedidosentregados.h"
#include "ui_verpedidosentregados.h"

VerPedidosEntregados::VerPedidosEntregados(QWidget *parent, ListaOrdenada<Pedido*>* listaPedidosEntregados) // Permite ver en tiempo real los pedidos que fueron entregados
    : QDialog(parent)
    , ui(new Ui::VerPedidosEntregados)
{
    ui->setupUi(this);
    this->listaPedidosEntregados = listaPedidosEntregados;

}

VerPedidosEntregados::~VerPedidosEntregados()
{
    delete ui;
}


void VerPedidosEntregados::printPedidos(){ // Toma la lista de pedidos entregados y la muestra
    QString var = "";
    for(int i = 0; i < listaPedidosEntregados->size(); i++){
        var += listaPedidosEntregados->ver(i)->getName() += "\n";
    }
    ui->pedidosEntregados->setText(var);
}




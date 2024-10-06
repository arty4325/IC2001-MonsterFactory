#include "pedidoslabel.h"
#include "ui_pedidoslabel.h"

PedidosLabel::PedidosLabel(QWidget *parent, ListaOrdenada<Pedido*>* listaPedidos) // Label permite ver en tiempo real los pedidos
    : QDialog(parent)
    , ui(new Ui::PedidosLabel)
{
    ui->setupUi(this);
    this->listaPedidos = listaPedidos;
}

PedidosLabel::~PedidosLabel()
{
    delete ui;
}


void PedidosLabel::PrintPedidos(){ // toma los pedidos y los imprime en esta ventana
    QString var = "";
    for(int i = 0; i < listaPedidos->cantItems; i++){
        var += listaPedidos->ver(i)->getName();
    }
    ui->pedidosView ->setText(var);
}





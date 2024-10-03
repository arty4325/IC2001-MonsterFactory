#include "verpedidosentregados.h"
#include "ui_verpedidosentregados.h"

VerPedidosEntregados::VerPedidosEntregados(QWidget *parent, ListaOrdenada<Pedido*>* listaPedidosEntregados)
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


void VerPedidosEntregados::printPedidos(){
    QString var = "";
    for(int i = 0; i < listaPedidosEntregados->size(); i++){
        var += listaPedidosEntregados->ver(i)->getName() += "\n";
    }
    ui->pedidosEntregados->setText(var);
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

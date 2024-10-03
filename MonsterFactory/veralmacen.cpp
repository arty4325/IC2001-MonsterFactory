#include "veralmacen.h"
#include "ui_veralmacen.h"

VerAlmacen::VerAlmacen(QWidget *parent, ListaOrdenada<Mounstro*>* listaAlmacen)
    : QDialog(parent)
    , ui(new Ui::VerAlmacen)
{
    ui->setupUi(this);
    this->listaAlmacen = listaAlmacen;
}

VerAlmacen::~VerAlmacen()
{
    delete ui;
}

void VerAlmacen::printAlmacen()
{
    QString var = "";
    for(int i = 0; i < listaAlmacen->size(); i++){
        var += listaAlmacen->ver(i)->type + "\n";
    }
    ui->itemsAlmacen->setText(var);
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

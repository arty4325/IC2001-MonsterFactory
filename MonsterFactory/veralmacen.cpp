#include "veralmacen.h"
#include "ui_veralmacen.h"

VerAlmacen::VerAlmacen(QWidget *parent, ListaOrdenada<Mounstro*>* listaAlmacen) // Permite ver en tiempo real el almacen
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

void VerAlmacen::printAlmacen() // Toma la informacion del almacen y la muestra
{
    QString var = "";
    for(int i = 0; i < listaAlmacen->size(); i++){
        var += listaAlmacen->ver(i)->type + "\n";
    }
    ui->itemsAlmacen->setText(var);
}

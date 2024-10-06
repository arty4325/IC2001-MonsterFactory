#include "colamounstros.h"
#include "ui_colamounstros.h"
#include "DataStructures/cola.h"
#include "MonsterStructures/mounstro.h"


ColaMounstros::ColaMounstros(QWidget *parent, Cola<Mounstro*>* colaMounstros) : // ventana para ver en tiempo real que esta en la cola de mousntros
    QDialog(parent),
    ui(new Ui::ColaMounstros)
{
    ui->setupUi(this);
    this->colaMounstros = colaMounstros;
}

ColaMounstros::~ColaMounstros()
{
    delete ui;
}


void ColaMounstros::printColaMounstros(){ // toma todos los elementos de la cola de mousntros y los despliega en pantalla
    QString var = "";
    for(int i = 0; i < colaMounstros->getCantItems(); i++ ){
        var += colaMounstros->getElementoEnIndice(i)->type + "\n";
    }
    ui->infoColaMounstros->setText(var);
}



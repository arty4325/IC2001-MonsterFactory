#include "itinerariohorno.h"
#include "ui_itinerariohorno.h"

ItinerarioHorno::ItinerarioHorno(QWidget *parent, Cola<Mounstro*>* primeraBandeja, Cola<Mounstro*>* segundaBandeja,
                                 Cola<Mounstro*>* terceraBandeja, Cola<Mounstro*>* cuartaBandeja)
    : QDialog(parent)
    , ui(new Ui::ItinerarioHorno)
{
    ui->setupUi(this);
    this->primeraBandeja = primeraBandeja;
    this->segundaBandeja = segundaBandeja;
    this->terceraBandeja = terceraBandeja;
    this->cuartaBandeja = cuartaBandeja;
}

ItinerarioHorno::~ItinerarioHorno()
{
    delete ui;
}


void ItinerarioHorno::printHorno(){
    QString varPrimeraBandeja = "";
    QString varSegundaBandeja = "";
    QString varTerceraBandeja = "";
    QString varCuartaBandeja = "";
    for(int i = 0; i < primeraBandeja->getCantItems(); i++){
        varPrimeraBandeja += primeraBandeja ->getElementoEnIndice(i)->type + "\n";
    }
    for(int i = 0; i < segundaBandeja -> getCantItems(); i++){
        varSegundaBandeja += segundaBandeja ->getElementoEnIndice(i)->type + "\n";
    }
    for(int i = 0; i < terceraBandeja -> getCantItems(); i++){
        varTerceraBandeja += terceraBandeja -> getElementoEnIndice(i) -> type + "\n";
    }
    for(int i = 0; i < cuartaBandeja -> getCantItems(); i++){
        varCuartaBandeja += cuartaBandeja -> getElementoEnIndice(i) -> type + "\n";
    }
    ui->bandeja1->setText(varPrimeraBandeja);
    ui->bandeja2->setText(varSegundaBandeja);
    ui->bandeja3->setText(varTerceraBandeja);
    ui->bandeja4->setText(varCuartaBandeja);
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

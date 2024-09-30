#include "pedido.h"

Pedido::Pedido() {}

Pedido::Pedido(QString inputString, int cantItems){
    this->cantItems = cantItems;
    this->inputString = inputString;
    this->mounstrosPedido->cantItems = cantItems;
}

bool Pedido::Contiene(QString searchString){
    return inputString.contains(searchString);
}

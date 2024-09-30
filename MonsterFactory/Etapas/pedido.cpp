#include "pedido.h"

Pedido::Pedido() {}

Pedido::Pedido(QString inputString, int cantItems){
    this->cantItems = cantItems;
    this->inputString = inputString;
}

bool Pedido::Contiene(QString searchString){
    return inputString.contains(searchString);
}

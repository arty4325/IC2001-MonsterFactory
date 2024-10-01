#include "pedido.h"

Pedido::Pedido() {}

Pedido::Pedido(QString inputString, int cantItems){
    this->cantItems = cantItems;
    this->inputString = inputString;
}

bool Pedido::Contiene(QString searchString){
    return inputString.contains(searchString);
}

bool Pedido::ContieneYRemueve(QString searchString) {
    int index = inputString.indexOf(searchString);  // Encuentra el índice de la primera aparición

    if (index != -1) {
        inputString.remove(index, searchString.length());  // Elimina solo la primera aparición
        return true;  // Indica que el string fue encontrado y eliminado
    }

    return false;  // Indica que el string no fue encontrado
}


void Pedido::ChangeMax(int val){
    this->mounstrosPedido->changeMax(val);
}


void Pedido::IncertMonster(Mounstro* mounstro){
    mounstrosPedido->push(mounstro);
}

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

bool Pedido::isPedidoFull(){
    return mounstrosPedido->isFull();
}

QString Pedido::getName() {
    // Separar el string en partes usando '=' como delimitador
    QStringList parts = this->inputString.split("=");

    // Retornar el último elemento, que debería ser el nombre (después de los "=")
    if (!parts.isEmpty()) {
        QString name = parts.last().trimmed(); // Trim para eliminar espacios en blanco
        return name;
    }

    return ""; // Si no se encuentra, retornamos un string vacío
}

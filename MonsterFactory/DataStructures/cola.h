#ifndef COLA_H
#define COLA_H
#include <QList>
#include <QDebug>
#include<QObject>
#include <QRandomGenerator>
#include "nodoCola.h"


// Los metodos de una cola son:
// isEmpty() -> revisa si la lista esta vacia
// push -> incerta
// Nodo* pop(); -> elimina cola y lo toma
// Nodo* peck(); -> Ve el valor que toca en la cola



template <typename T>
class Cola {
public:
    int cantItems = 0; // La cantidad de elementos que tiene esta cola
    int maxCant; // La maxima cantidad de elementos que puede llegar a tener esta cola
    nodoCola<T>* primerNodo = nullptr;
    nodoCola<T>* ultimoNodo = nullptr;
    Cola(){
        cantItems = 0;
        maxCant = 20;
        primerNodo = nullptr;
        ultimoNodo = nullptr;
    }

    int getCantItems() {
        return cantItems;
    }

    bool getIsFull(){
        return(!(cantItems <= maxCant));
    }

    void changeMax(int val){
        if(val > cantItems){
            maxCant = val;
        } else {
        }
    }

    bool isEmpty() const{
        if(cantItems == 0){
            return true;
        } else {
            return false;
        }
    }

    bool isFull() const{
        if(cantItems == maxCant){
            return true;
        } else {
            return false;
        }
    }

    void push(T _data) { // Se quiere poner mas informacion en la cola
        nodoCola<T>* nodo = new nodoCola<T>();
        nodo->data = _data;
        nodo->next = nullptr;

        if(cantItems < maxCant){ // Se revisa si la cola esta llena
            if (isEmpty()) {
                primerNodo = ultimoNodo = nodo;
            } else {
                ultimoNodo->next = nodo;
                ultimoNodo = nodo;
            }
            cantItems += 1;
        } else {
            // La lista esta llena
        }
    }

    nodoCola<T>* pop() { // Elimina un nodo y lo devuelve
        if (isEmpty()) {
            return nullptr;
        }

        nodoCola<T>* nodoEliminar = primerNodo;
        primerNodo = primerNodo->next;
        cantItems -= 1;

        if (isEmpty()) {
            ultimoNodo = nullptr;
        }

        nodoEliminar->next = nullptr;
        return nodoEliminar;
    }

    nodoCola<T>* peck() const { // Ve un nodo
        if (isEmpty()) {
            return nullptr;
        }
        return primerNodo;
    }

    T getElementoEnIndice(int indice) const { // Esto no es perteneciente a una cola, pero para efectos de mostrar informacion, se puede recorrer la cola
        if (indice < 0 || indice >= cantItems) {
            throw std::out_of_range("Índice fuera de rango");  // Manejo de error si el índice no es válido
        }

        nodoCola<T>* current = primerNodo;  // Comienza desde el primer nodo
        int contador = 0;

        // Recorre la cola hasta llegar al índice deseado
        while (current != nullptr && contador < indice) {
            current = current->next;
            contador++;
        }

        return current->data;  // Devuelve el dato del nodo en el índice especificado
    }

};





#endif // COLA_H

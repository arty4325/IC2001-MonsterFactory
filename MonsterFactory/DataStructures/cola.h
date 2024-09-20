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
    int cantItems = 0;
    int maxCant;
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
            qDebug() << "Se logro cambiar";
        } else {
            qDebug() << "No se permite este cambio";
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

    void push(T _data) {
        nodoCola<T>* nodo = new nodoCola<T>();
        nodo->data = _data;
        nodo->next = nullptr;

        if(cantItems < maxCant){
            if (isEmpty()) {
                primerNodo = ultimoNodo = nodo;
            } else {
                ultimoNodo->next = nodo;
                ultimoNodo = nodo;
            }
            cantItems += 1;
        } else {
            //qDebug() << "La lista esta llena";
        }
    }

    nodoCola<T>* pop() {
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

    nodoCola<T>* peck() const {
        if (isEmpty()) {
            return nullptr;
        }
        return primerNodo;
    }
};


// Ahora viene la cola FiFo



#endif // COLA_H

#ifndef LISTAORDENADA_H
#define LISTAORDENADA_H
#include "nodoOrdenado.h"
#include <QList>
#include <QDebug>
#include<QObject>
#include <QRandomGenerator>



template <typename T>
class ListaOrdenada {
public:
    int cantItems = 0;
    nodoOrdenado<T>* primerNodo = nullptr;
    nodoOrdenado<T>* ultimoNodo = nullptr;

    // La verdad solamente quiero incertar y saber cuantos items hay (Por ahora)

    void incert(T _data){
        nodoOrdenado<T>* nodo = new nodoOrdenado<T>();
        if(cantItems == 0){
            primerNodo = ultimoNodo = nodo;
            cantItems += 1;
        } else {
            // quiero agregar un nodo despues de ultimoNodo
            nodoOrdenado<T>* tempNodo = ultimoNodo;
            ultimoNodo = nodo;
            ultimoNodo -> previous = tempNodo;
            tempNodo -> next = ultimoNodo;
            cantItems += 1;
        }
    }


};



#endif // LISTAORDENADA_H

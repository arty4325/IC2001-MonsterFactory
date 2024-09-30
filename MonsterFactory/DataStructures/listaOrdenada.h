#ifndef LISTAORDENADA_H
#define LISTAORDENADA_H
#include "nodoOrdenado.h"
#include <QList>
#include <QDebug>
#include <QObject>
#include <QRandomGenerator>

template <typename T>
class ListaOrdenada {
public:
    int cantItems = 0;
    nodoOrdenado<T>* primerNodo = nullptr;
    nodoOrdenado<T>* ultimoNodo = nullptr;

    // Método para insertar un nuevo nodo en la lista
    void incert(T _data){
        nodoOrdenado<T>* nodo = new nodoOrdenado<T>();
        nodo->data = _data;
        if(cantItems == 0){
            primerNodo = ultimoNodo = nodo;
        } else {
            // Agregar el nuevo nodo después del último nodo
            nodoOrdenado<T>* tempNodo = ultimoNodo;
            ultimoNodo = nodo;
            ultimoNodo->previous = tempNodo;
            tempNodo->next = ultimoNodo;
        }
        cantItems += 1;
    }

    // Método para borrar un nodo en un índice específico y devolver el item eliminado
    T borrar(int indice){
        if(indice < 0 || indice >= cantItems){
            qDebug() << "Índice fuera de rango";
            return T();  // Devuelve un objeto por defecto si el índice es inválido
        }

        nodoOrdenado<T>* nodoActual = primerNodo;
        for(int i = 0; i < indice; i++){
            nodoActual = nodoActual->next;
        }

        // Desconectar el nodo a eliminar de la lista
        if(nodoActual->previous != nullptr){
            nodoActual->previous->next = nodoActual->next;
        } else {
            primerNodo = nodoActual->next;  // Si es el primer nodo
        }

        if(nodoActual->next != nullptr){
            nodoActual->next->previous = nodoActual->previous;
        } else {
            ultimoNodo = nodoActual->previous;  // Si es el último nodo
        }

        T dataEliminada = nodoActual->data;
        delete nodoActual;
        cantItems -= 1;

        return dataEliminada;  // Retorna el dato eliminado
    }

    // Método para ver el valor de un nodo en un índice específico
    T ver(int indice) const {
        if(indice < 0 || indice >= cantItems){
            qDebug() << "Índice fuera de rango";
            return T();  // Devuelve un objeto por defecto si el índice es inválido
        }

        nodoOrdenado<T>* nodoActual = primerNodo;
        for(int i = 0; i < indice; i++){
            nodoActual = nodoActual->next;
        }

        return nodoActual->data;  // Retorna el dato del nodo en el índice
    }

    // Método que devuelve el tamaño de la lista
    int size() const {
        return cantItems;
    }
};

#endif // LISTAORDENADA_H

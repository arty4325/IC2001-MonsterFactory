#ifndef NODOORDENADO_H
#define NODOORDENADO_H


template <typename T>
class nodoOrdenado {
public:
    T data;
    nodoOrdenado* next;
    nodoOrdenado* previous;

    nodoOrdenado(){
        data = 0;
        next = nullptr;
    }

    nodoOrdenado(T _data){
        data = _data;
        next = nullptr;
    }
};


#endif // NODOORDENADO_H

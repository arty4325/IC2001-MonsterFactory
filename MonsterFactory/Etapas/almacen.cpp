#include "almacen.h"

Almacen::Almacen() {}

Almacen::Almacen(ListaOrdenada<Mounstro*>* listaAlmacen, Cola<Mounstro*>* colaEntregados, Cola<Mounstro*>* colaAlmacen ){
    this-> listaAlmacen = listaAlmacen;
    this-> colaEntregados = colaEntregados;
    this-> colaAlmacen = colaAlmacen;
}

void Almacen::incertAlmacen(Mounstro* mounstro){
    listaAlmacen -> incert(mounstro);
}

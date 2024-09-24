#ifndef ALMACEN_H
#define ALMACEN_H
#include <QtCore>
#include <QDebug>
#include <QRandomGenerator>
#include <QString>
#include <QLabel>
#include "../DataStructures/cola.h"
#include "../MonsterStructures/mounstro.h"
#include "../DataStructures/listaOrdenada.h"



class Almacen
{
public:
    Almacen();
    Almacen(ListaOrdenada<Mounstro*>* listaAlmacen, ListaOrdenada<Mounstro*>* colaEntregados, ListaOrdenada<Mounstro*>* colaAlmacen );
    void incertAlmacen(Mounstro* mounstro);
private:
    ListaOrdenada<Mounstro*>* colaEntregados;
    ListaOrdenada<Mounstro*>* colaAlmacen;
    ListaOrdenada<Mounstro*>* listaAlmacen;
};

#endif // ALMACEN_H

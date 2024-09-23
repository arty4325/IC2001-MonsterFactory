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
    Almacen(ListaOrdenada<Mounstro*>* listaAlmacen, Cola<Mounstro*>* colaEntregados, Cola<Mounstro*>* colaAlmacen );
    void incertAlmacen(Mounstro* mounstro);
private:
    Cola<Mounstro*>* colaEntregados;
    Cola<Mounstro*>* colaAlmacen;
    ListaOrdenada<Mounstro*>* listaAlmacen;
};

#endif // ALMACEN_H

#ifndef PEDIDOMANAGER_H
#define PEDIDOMANAGER_H
#include <QtCore>
#include <QDebug>
#include <QRandomGenerator>
#include <QString>
#include <QLabel>
#include "pedido.h"
#include "../DataStructures/cola.h"
#include "../MonsterStructures/mounstro.h"
#include "../ReadingStructures/readtextfiles.h"
#include "../DataStructures/listaOrdenada.h"

class PedidoManager : public QThread
{
public:
    PedidoManager();
    PedidoManager(int sleepTime, ListaOrdenada<Pedido*>* listaPedidos,  ListaOrdenada<Pedido*>* listaPedidosPrioridad, ListaOrdenada<Mounstro*>* listaAlmacen);
    void run();
private:
    bool running;
    int sleepTime;
    ListaOrdenada<Pedido*>* listaPedidos;
    ListaOrdenada<Pedido*>* listaPedidosPrioridad;
    ListaOrdenada<Mounstro*>* listaAlmacen;

};

#endif // PEDIDOMANAGER_H

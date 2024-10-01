#ifndef ENTREGA_H
#define ENTREGA_H
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

class Entrega : public QThread
{
public:
    Entrega();
    Entrega(int sleepTime, ListaOrdenada<Pedido*>* listaPedidos,ListaOrdenada<Pedido*>* listaPedidosPrioridad, ListaOrdenada<Mounstro*>* listaAlmacen);
    void run();
private:
    bool running;
    int sleepTime;
    ListaOrdenada<Pedido*>* listaPedidos;
    ListaOrdenada<Pedido*>* listaPedidosPrioridad;
    ListaOrdenada<Mounstro*>* listaAlmacen;

};

#endif // ENTREGA_H

#ifndef PEDIDOMANAGER_H
#define PEDIDOMANAGER_H
#include <QtCore>
#include <QDebug>
#include <QRandomGenerator>
#include <QString>
#include <QLabel>
#include "pedido.h"
#include "../DataStructures/cola.h"

class PedidoManager : public QThread
{
public:
    PedidoManager();
    PedidoManager(int sleepTime, Cola<Pedido*>* colaPedidos,  Cola<Pedido*>* colaPedidosPrioridad);
    void run();
private:
    bool running;
    int sleepTime;
    Cola<Pedido*>* colaPedidos;
    Cola<Pedido*>* colaPedidosPrioridad;

};

#endif // PEDIDOMANAGER_H

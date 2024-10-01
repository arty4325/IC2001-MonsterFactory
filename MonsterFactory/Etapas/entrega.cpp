#include "entrega.h"

Entrega::Entrega() {}


#include "../MonsterStructures/mounstro.h"
#include "../ReadingStructures/readtextfiles.h"
#include <QRegularExpression>
#include <QString>
#include <QStringList>
#include <QDebug>


Entrega::Entrega(int sleepTime, ListaOrdenada<Pedido*>* listaPedidosPrioridad,ListaOrdenada<Pedido*>* listaPedidos) {
    this->sleepTime = sleepTime;
    this->running = true;
    this->listaPedidosPrioridad = listaPedidosPrioridad;
    this->listaPedidos = listaPedidos;
}

void Entrega::run()
{
    this->running = true;

    while (true) {
        if (!this->running) {
            QThread::sleep(1);
            continue;
        }
        qDebug() << "Se tramitan las entregas";
        QThread::sleep(this->sleepTime);
    }
}


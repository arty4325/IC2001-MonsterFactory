#include "entrega.h"

Entrega::Entrega() {}


#include "../MonsterStructures/mounstro.h"
#include "../ReadingStructures/readtextfiles.h"
#include <QRegularExpression>
#include <QString>
#include <QStringList>
#include <QDebug>


Entrega::Entrega(int sleepTime, ListaOrdenada<Pedido*>* listaPedidosPrioridad,ListaOrdenada<Pedido*>* listaPedidos, ListaOrdenada<Mounstro*>* listaAlmacen) {
    this->sleepTime = sleepTime;
    this->running = true;
    this->listaPedidosPrioridad = listaPedidosPrioridad;
    this->listaPedidos = listaPedidos;
    this->listaAlmacen = listaAlmacen;
}

void Entrega::run()
{
    this->running = true;

    while (true) {
        if (!this->running) {
            QThread::sleep(1);
            continue;
        }
        //qDebug() << "Se tramitan las entregas";
        for(int i = 0; i < listaAlmacen->size(); i++){
            for(int k = 0; k < listaPedidosPrioridad->size(); k++){
                if(listaPedidosPrioridad->ver(k)->Contiene(listaAlmacen->ver(i)->type)){
                    listaPedidosPrioridad ->ver(k) -> ContieneYRemueve(listaAlmacen->ver(i)->type);
                    listaPedidosPrioridad->ver(k)->IncertMonster(listaAlmacen->borrar(i));
                }
            }
        }
        // Aqui se vieron los de prioridad, ahora se ven los normales




        QThread::sleep(this->sleepTime);
    }
}


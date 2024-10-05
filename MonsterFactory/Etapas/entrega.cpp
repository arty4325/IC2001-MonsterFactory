#include "entrega.h"

Entrega::Entrega() {}


#include "../MonsterStructures/mounstro.h"
#include "../ReadingStructures/readtextfiles.h"
#include <QRegularExpression>
#include <QString>
#include <QStringList>
#include <QDebug>
#include "../ReadingStructures/readtextfiles.h"


Entrega::Entrega(int sleepTime, ListaOrdenada<Pedido*>* listaPedidos,ListaOrdenada<Pedido*>* listaPedidosPrioridad, ListaOrdenada<Mounstro*>* listaAlmacen, ListaOrdenada<Pedido*>* listaPedidosEntregados) {
    this->sleepTime = sleepTime;
    this->running = true;
    this->listaPedidosPrioridad = listaPedidosPrioridad;
    this->listaPedidos = listaPedidos;
    this->listaAlmacen = listaAlmacen;
    this->listaPedidosEntregados = listaPedidosEntregados;
}

void Entrega::run()
{
    this->running = true;

    while (true) {
        if (!this->running) {
            QThread::sleep(1);
            continue;
        }

        // Usar una ListaOrdenada<int> para almacenar los índices de los elementos a eliminar
        ListaOrdenada<int> indicesAEliminar;
        readTextFiles* readingStructures = new readTextFiles();
        // Procesar primero los pedidos prioritarios
        for (int i = 0; i < listaAlmacen->size(); ++i) {
            bool procesado = false;

            // Verificar en la lista de pedidos prioritarios
            for (int k = 0; k < listaPedidosPrioridad->size(); ++k) {
                qDebug() << listaAlmacen -> ver(i) -> type;
                if (listaPedidosPrioridad->ver(k)->Contiene(listaAlmacen->ver(i)->type)) {
                    listaPedidosPrioridad->ver(k)->ContieneYRemueve(listaAlmacen->ver(i)->type);
                    listaPedidosPrioridad->ver(k)->IncertMonster(listaAlmacen->ver(i));
                    if(listaPedidosPrioridad->ver(k)->isPedidoFull()){
                        qDebug() << "Hola mina xd 1";
                        listaAlmacen ->ver(i) -> enAlmacen = false;
                        // A que pedido y cuando
                        listaAlmacen -> ver(i) -> tiempoEntrega = QDateTime::currentDateTime();
                        //qDebug() << listaPedidosPrioridad->ver(k)->getName();
                        listaAlmacen -> ver(i)->pedido = listaPedidosPrioridad->ver(k)->getName();
                        //qDebug() << listaPedidosPrioridad -> ver(k) ->getName() + QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
                        readingStructures->appendTextToFile("C:/Users/artur/OneDrive/Escritorio/ITCR/IIS2024/Estructuras de Datos/Proyectos/IC2001-MonsterFactory/MonsterFactory/Historicos/historiaEntregados.txt",
                                                            listaPedidosPrioridad -> ver(k) ->getName() + " " + QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") + " Prioridad");
                        listaPedidosEntregados->incert(listaPedidosPrioridad->borrar(k));
                        // Se le agrega el PEDIDO


                    }
                    indicesAEliminar.incert(i);  // Marcar el índice para eliminar
                    procesado = true;
                    break;  // Si el monstruo ha sido procesado, no buscar en más pedidos
                }
            }

            // Si no fue procesado en la lista de prioridad, verificar en la lista normal
            if (!procesado) {
                for (int w = 0; w < listaPedidos->size(); ++w) {
                    if (listaPedidos->ver(w)->Contiene(listaAlmacen->ver(i)->type)) {
                        listaPedidos->ver(w)->ContieneYRemueve(listaAlmacen->ver(i)->type);
                        listaPedidos->ver(w)->IncertMonster(listaAlmacen->ver(i));
                        if(listaPedidos->ver(w)->isPedidoFull()){
                            qDebug() << "Hola mina xd 2";
                            listaAlmacen ->ver(i) -> enAlmacen = false;
                            // A que pedido y cuando
                            listaAlmacen -> ver(i) -> tiempoEntrega = QDateTime::currentDateTime();
                            listaAlmacen -> ver(i)->pedido = listaPedidosPrioridad->ver(w)->getName();
                            readingStructures->appendTextToFile("C:/Users/artur/OneDrive/Escritorio/ITCR/IIS2024/Estructuras de Datos/Proyectos/IC2001-MonsterFactory/MonsterFactory/Historicos/historiaEntregados.txt",
                                                                listaPedidosPrioridad -> ver(i) ->getName() + " " + QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") + " No Prioridad");
                            listaPedidosEntregados->incert(listaPedidos->borrar(w));
                        }
                        indicesAEliminar.incert(i);  // Marcar el índice para eliminar
                        break;  // Una vez procesado, no buscar en más pedidos
                    }
                }
            }
        }

        // Eliminar los elementos de listaAlmacen que han sido procesados, desde el último al primero
        for (int j = indicesAEliminar.size() - 1; j >= 0; --j) {
            qDebug() << "Lo que se esta borrando (A ver a donde putas se cae" << indicesAEliminar.ver(j);
            listaAlmacen->borrar(indicesAEliminar.ver(j));  // Eliminar desde el final
        }

        QThread::sleep(this->sleepTime);
    }
}

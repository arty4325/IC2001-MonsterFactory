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
        readTextFiles* readingStructures = new readTextFiles(); // Se instancia el manejador de archivos para poder manejar la bitacora
        // Procesar primero los pedidos prioritarios
        for (int i = 0; i < listaAlmacen->size(); ++i) { // Se recorren todos los elementos que estan en el almacen
            bool procesado = false; // Se lleva control de si fueron procesados

            // Verificar en la lista de pedidos prioritarios
            for (int k = 0; k < listaPedidosPrioridad->size(); ++k) {
                if (listaPedidosPrioridad->ver(k)->Contiene(listaAlmacen->ver(i)->type)) { // Se verifica si el pedido de listaPedidosPrioridad ocupa el mounstro que esta en listaAlmacen
                    listaPedidosPrioridad->ver(k)->ContieneYRemueve(listaAlmacen->ver(i)->type);  // Se le quita ese mounstro a ese pedido
                    listaPedidosPrioridad->ver(k)->IncertMonster(listaAlmacen->ver(i));  // Luego, a la cola que esta en listaPedidosPrioridad, se le incerta el mounstro que ocupa
                    if(listaPedidosPrioridad->ver(k)->isPedidoFull()){ // Si el pedido esta lleno
                        // El pedido esta listo para ser entregado
                        listaAlmacen ->ver(i) -> enAlmacen = false; // Se marca la casilla que indica que este ya no esta en el almacen
                        listaAlmacen -> ver(i) -> tiempoEntrega = QDateTime::currentDateTime(); // Se guarda el momento en el que esto ocurrio
                        listaAlmacen -> ver(i)->pedido = listaPedidosPrioridad->ver(k)->getName(); // Al mounstro que se estaba viendo, se le indica a que pedido fue entregado
                        readingStructures->appendTextToFile("C:/Users/artur/OneDrive/Escritorio/ITCR/IIS2024/Estructuras de Datos/Proyectos/IC2001-MonsterFactory/MonsterFactory/Historicos/historiaEntregados.txt",
                                                            listaPedidosPrioridad -> ver(k) ->getName() + " " + QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") + " Prioridad");
                        // Se guarda esto en el registro de informacion
                        listaPedidosEntregados->incert(listaPedidosPrioridad->borrar(k)); // Se incerta en la lista de pedidos entregados y se borra de los pedidos que estan en prioridad

                    }
                    indicesAEliminar.incert(i);  // Marcar el índice para eliminar
                    procesado = true;
                    break;  // Si el monstruo ha sido procesado, no buscar en más pedidos
                }
            }

            // Si no fue procesado en la lista de prioridad, verificar en la lista normal
            if (!procesado) {
                for (int w = 0; w < listaPedidos->size(); ++w) { // Un proceso totalmente analogo al anterior
                    if (listaPedidos->ver(w)->Contiene(listaAlmacen->ver(i)->type)) {
                        listaPedidos->ver(w)->ContieneYRemueve(listaAlmacen->ver(i)->type);
                        listaPedidos->ver(w)->IncertMonster(listaAlmacen->ver(i));
                        if(listaPedidos->ver(w)->isPedidoFull()){
                            listaAlmacen ->ver(i) -> enAlmacen = false;
                            listaAlmacen -> ver(i) -> tiempoEntrega = QDateTime::currentDateTime();
                            listaAlmacen -> ver(i)->pedido = listaPedidos->ver(w)->getName();
                            readingStructures->appendTextToFile("C:/Users/artur/OneDrive/Escritorio/ITCR/IIS2024/Estructuras de Datos/Proyectos/IC2001-MonsterFactory/MonsterFactory/Historicos/historiaEntregados.txt",
                                                                listaPedidos -> ver(w) ->getName() + " " + QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") + " No Prioridad");
                            listaPedidosEntregados->incert(listaPedidos->borrar(w));
                        }
                        indicesAEliminar.incert(i);  // Se hace una lista de los indices de pedidos ya tramitados
                        break;  // Una vez procesado, no buscar en más pedidos
                    }
                }
            }
        }

        // Eliminar los elementos de listaAlmacen que han sido procesados, desde el último al primero
        for (int j = indicesAEliminar.size() - 1; j >= 0; --j) {
            listaAlmacen->borrar(indicesAEliminar.ver(j));  // Eliminar desde el final
        }

        QThread::sleep(this->sleepTime);
    }
}

void Entrega::stop(int val){ // Esto permite parar la aplicacion
    if(val == 2){
        // Se tiene que parar el combinador
        this->running = false;
    } else {
        // Se reanuda el combinador
        this->running = true;
    }
}


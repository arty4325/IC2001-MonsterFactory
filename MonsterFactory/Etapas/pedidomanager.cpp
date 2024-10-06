#include "pedidomanager.h"
#include "pedido.h"
#include "../MonsterStructures/mounstro.h"
#include "../ReadingStructures/readtextfiles.h"
#include <QRegularExpression>
#include <QString>
#include <QStringList>
#include <QDebug>
#include "../ReadingStructures/readtextfiles.h"

PedidoManager::PedidoManager() {}

PedidoManager::PedidoManager(int sleepTime, ListaOrdenada<Pedido*>* listaPedidos,  ListaOrdenada<Pedido*>* listaPedidosPrioridad, ListaOrdenada<Mounstro*>* listaAlmacen) {
    this->sleepTime = sleepTime;
    this->running = true;
    this->listaPedidos = listaPedidos;
    this->listaPedidosPrioridad = listaPedidosPrioridad;
    this->listaAlmacen = listaAlmacen;
}

void PedidoManager::run()
{
    this->running = true;

    while (true) {
        if (!this->running) {
            QThread::sleep(1);
            continue;
        }
        try {
            QString readString; // Se instancia el manejador de archivos para poder guardar la informacion en la bitacora
            readTextFiles* read = new readTextFiles();
            readString = read->readTextFilesInFolder();

            QStringList partes = readString.split(QRegularExpression("t=")); // Se hace un split de los textos con las apariciones de t=
            for (const QString &parte : partes) { // Se itera sobre ese string
                QString instanceString = ""; // Se crea un string vacio en donde se almacenara lo que nos interese
                QStringList partesPedido = parte.split(QRegularExpression("\n")); // Se hace split cuando hay un enter

                // Empieza desde el índice 3 por que es donde aparecen los elementos que nos interesan
                for (int i = 3; i < partesPedido.size(); ++i) {
                    instanceString += partesPedido[i] + "="; // Concatena los elementos que no sinteresan
                }

                if (!instanceString.isEmpty() && instanceString.endsWith("=")) {
                   instanceString.chop(1);
                }

                readTextFiles* readingStructures = new readTextFiles();
                if(partesPedido.size() > 1){
                    if(partesPedido[1] == "1ST PROGRA"){ // Como todo el archivo de texto se tiene separado se puede ver si el pedido es de prioridad
                        // CASO para los pedidos de prioridad
                        Pedido* pedido = new Pedido(instanceString, partesPedido.size() - 4); // Se instancia un pedido
                        readingStructures ->appendTextToFile("C:/Users/artur/OneDrive/Escritorio/ITCR/IIS2024/Estructuras de Datos/Proyectos/IC2001-MonsterFactory/MonsterFactory/Historicos/colaPedidosItinerario.txt",
                                                            instanceString + "=Primera Prioridad" + "=" +QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
                        pedido->ChangeMax(partesPedido.size() - 4); // Se guarda la informacion de ese pedido en memoria
                        listaPedidosPrioridad->incert(pedido); // Se incerta ese pedido en una lista de pedidos prioritarios para despues manejarlo

                    } else if (partesPedido[1] != "1ST PROGRA") {
                        // En este caso el pedido no es de prioridad
                        Pedido* pedidoNotPriority = new Pedido(instanceString, partesPedido.size() - 4); // Igualmente se instancia un pedido
                        readingStructures ->appendTextToFile("C:/Users/artur/OneDrive/Escritorio/ITCR/IIS2024/Estructuras de Datos/Proyectos/IC2001-MonsterFactory/MonsterFactory/Historicos/colaPedidosItinerario.txt",
                                                            instanceString + "=Segunda Prioridad" + "=" +QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
                        // Se guarda la informacion de este pedido en memoria
                        pedidoNotPriority->ChangeMax(partesPedido.size() - 4);
                        listaPedidos -> incert(pedidoNotPriority);
                    }
                }
            }
        } catch (...) {
            ;
        }

        // LLegados a este punto se pararon las solicuted
        QThread::sleep(this->sleepTime);
    }
}


void PedidoManager::stop(int val){ // Esto permite parar la aplicacion
    if(val == 2){
        // Se tiene que parar el combinador
        this->running = false;
    } else {
        // Se reanuda el combinador
        this->running = true;
    }
}


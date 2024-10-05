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
            QString readString;
            readTextFiles* read = new readTextFiles();
            readString = read->readTextFilesInFolder();

            QStringList partes = readString.split(QRegularExpression("t="));
            for (const QString &parte : partes) {
                QString instanceString = "";
                QStringList partesPedido = parte.split(QRegularExpression("\n"));

                // Empieza desde el índice 3 para concatenar el resto de elementos
                for (int i = 3; i < partesPedido.size(); ++i) {
                    instanceString += partesPedido[i] + "=";
                }

                // Quita el último '=' si lo deseas
                if (!instanceString.isEmpty() && instanceString.endsWith("=")) {
                   instanceString.chop(1); // Elimina el último caracter '='
                }
                //qDebug() << instanceString << instanceString.length();
                readTextFiles* readingStructures = new readTextFiles();
                if(partesPedido.size() > 1){
                    if(partesPedido[1] == "1ST PROGRA"){
                        //qDebug() << "Primera P " << instanceString << partesPedido.size() - 4;
                        // Instancio Pedido
                        Pedido* pedido = new Pedido(instanceString, partesPedido.size() - 4);
                        readingStructures ->appendTextToFile("C:/Users/artur/OneDrive/Escritorio/ITCR/IIS2024/Estructuras de Datos/Proyectos/IC2001-MonsterFactory/MonsterFactory/Historicos/colaPedidosItinerario.txt",
                                                            instanceString + "=Primera Prioridad" + "=" +QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
                        pedido->ChangeMax(partesPedido.size() - 4);
                        listaPedidosPrioridad->incert(pedido);

                    } else if (partesPedido[1] != "1ST PROGRA") {
                        //qDebug() << "Segunda P" << instanceString << partesPedido.size() - 4;
                        Pedido* pedidoNotPriority = new Pedido(instanceString, partesPedido.size() - 4);
                        readingStructures ->appendTextToFile("C:/Users/artur/OneDrive/Escritorio/ITCR/IIS2024/Estructuras de Datos/Proyectos/IC2001-MonsterFactory/MonsterFactory/Historicos/colaPedidosItinerario.txt",
                                                            instanceString + "=Segunda Prioridad" + "=" +QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
                        pedidoNotPriority->ChangeMax(partesPedido.size() - 4);
                        listaPedidos -> incert(pedidoNotPriority);
                    }
                }
            }
        } catch (...) {
            //qDebug() << "An error occurred.";
        }

        // Ya aqui se terminaron de procesar las solicitudes, tengo que comenzar a procesar los pedidos



        //qDebug() << read ->readTextFilesInFolder();

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


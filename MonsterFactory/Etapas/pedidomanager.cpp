#include "pedidomanager.h"
#include "pedido.h"
#include "../ReadingStructures/readtextfiles.h"
#include <QRegularExpression>
#include <QString>
#include <QStringList>
#include <QDebug>

PedidoManager::PedidoManager() {}

PedidoManager::PedidoManager(int sleepTime, Cola<Pedido*>* colaPedidos,  Cola<Pedido*>* colaPedidosPrioridad) {
    this->sleepTime = sleepTime;
    this->running = true;
    this->colaPedidos = colaPedidos;
    this->colaPedidosPrioridad = colaPedidosPrioridad;
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
                if(partesPedido.size() > 1){
                    if(partesPedido[1] == "1ST PROGRA"){
                        qDebug() << "Primera P " << instanceString;
                        // Instancio Pedido
                        Pedido* pedido = new Pedido(instanceString);
                        colaPedidosPrioridad -> push(pedido);

                    } else {
                        qDebug() << "Segunda P" << instanceString;
                        Pedido* pedido = new Pedido(instanceString);
                        colaPedidos -> push(pedido);
                    }
                }

            }

        } catch (...) {
            qDebug() << "An error occurred.";
        }


        //qDebug() << read ->readTextFilesInFolder();

        QThread::sleep(this->sleepTime);
    }
}


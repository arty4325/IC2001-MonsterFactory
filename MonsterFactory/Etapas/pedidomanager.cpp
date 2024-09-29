#include "pedidomanager.h"
#include "../ReadingStructures/readtextfiles.h"
#include <QRegularExpression>
#include <QString>
#include <QStringList>
#include <QDebug>

PedidoManager::PedidoManager() {}

PedidoManager::PedidoManager(int sleepTime) {
    this->sleepTime = sleepTime;
    this->running = true;
}

void PedidoManager::run()
{
    this->running = true;

    while (true) {
        if (!this->running) {
            QThread::sleep(1);
            continue;
        }
        QString readString;
        readTextFiles* read = new readTextFiles();
        readString = read ->readTextFilesInFolder();
        QStringList partes = readString.split(QRegularExpression("t="));
        for (const QString &parte : partes) {
            qDebug() << parte;
            QStringList partesPedido = parte.split(QRegularExpression("\n"));
            for (int i = 0; i < partesPedido.size(); ++i) {
                qDebug() << partesPedido[i];  // O partesPedido.at(i)
            }
        }

        //qDebug() << read ->readTextFilesInFolder();

        QThread::sleep(this->sleepTime);
    }
}


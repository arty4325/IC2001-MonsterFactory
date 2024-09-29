#ifndef PEDIDOMANAGER_H
#define PEDIDOMANAGER_H
#include <QtCore>
#include <QDebug>
#include <QRandomGenerator>
#include <QString>
#include <QLabel>


class PedidoManager : public QThread
{
public:
    PedidoManager();
    PedidoManager(int sleepTime);
    void run();
private:
    bool running;
    int sleepTime;
};

#endif // PEDIDOMANAGER_H

#ifndef PEDIDO_H
#define PEDIDO_H
#include <QList>
#include <QDebug>
#include<QObject>
#include <QRandomGenerator>


class Pedido
{
public:
    Pedido();
    Pedido(QString inputString);
private:
    QString inputString;
};

#endif // PEDIDO_H

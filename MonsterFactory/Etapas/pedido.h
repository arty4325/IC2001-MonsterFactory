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
    Pedido(QString inputString, int cantItems);
    bool Contiene(QString searchString);
private:
    QString inputString;
    int cantItems;
};

#endif // PEDIDO_H

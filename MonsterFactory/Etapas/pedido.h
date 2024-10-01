#ifndef PEDIDO_H
#define PEDIDO_H
#include <QList>
#include <QDebug>
#include<QObject>
#include <QRandomGenerator>
#include "../DataStructures/cola.h"
#include "../MonsterStructures/mounstro.h"


class Pedido
{
public:
    Pedido();
    Pedido(QString inputString, int cantItems);
    bool Contiene(QString searchString);
    void ChangeMax(int val);
    void IncertMonster(Mounstro* mousntro);
    bool ContieneYRemueve(QString searchString);
    bool isPedidoFull();
private:
    QString inputString;
    Cola<Mounstro*>* mounstrosPedido = new Cola<Mounstro*>();
    int cantItems;
};

#endif // PEDIDO_H

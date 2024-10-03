#ifndef PEDIDOSPRIORIDAD_H
#define PEDIDOSPRIORIDAD_H

#include <QDialog>
#include "DataStructures/listaOrdenada.h"
#include "Etapas/pedido.h"


namespace Ui {
class PedidosPrioridad;
}

class PedidosPrioridad : public QDialog
{
    Q_OBJECT

public:
    explicit PedidosPrioridad(QWidget *parent = nullptr, ListaOrdenada<Pedido*>* listaPedidosPrioridad = nullptr);
    ~PedidosPrioridad();
    void printPedidosPrioridad();
private:
    Ui::PedidosPrioridad *ui;
    ListaOrdenada<Pedido*>* listaPedidosPrioridad;
};

#endif // PEDIDOSPRIORIDAD_H

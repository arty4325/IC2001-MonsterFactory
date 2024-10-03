#ifndef PEDIDOSLABEL_H
#define PEDIDOSLABEL_H

#include <QDialog>
#include "DataStructures/listaOrdenada.h"
#include "Etapas/pedido.h"

namespace Ui {
class PedidosLabel;
}

class PedidosLabel : public QDialog
{
    Q_OBJECT

public:
    explicit PedidosLabel(QWidget *parent = nullptr, ListaOrdenada<Pedido*>* listaPedidos = nullptr);
    ~PedidosLabel();
    void PrintPedidos();

private:
    Ui::PedidosLabel *ui;
    ListaOrdenada<Pedido*>* listaPedidos;
};

#endif // PEDIDOSLABEL_H

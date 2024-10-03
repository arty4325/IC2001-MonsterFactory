#ifndef VERPEDIDOSENTREGADOS_H
#define VERPEDIDOSENTREGADOS_H

#include <QDialog>
#include "DataStructures/listaOrdenada.h"
#include "Etapas/pedido.h"

namespace Ui {
class VerPedidosEntregados;
}

class VerPedidosEntregados : public QDialog
{
    Q_OBJECT

public:
    explicit VerPedidosEntregados(QWidget *parent = nullptr, ListaOrdenada<Pedido*>* listaPedidosEntregados = nullptr);
    ~VerPedidosEntregados();
    void printPedidos();

private:
    Ui::VerPedidosEntregados *ui;
    ListaOrdenada<Pedido*>* listaPedidosEntregados;

};

#endif // VERPEDIDOSENTREGADOS_H

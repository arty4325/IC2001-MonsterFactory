#ifndef VERALMACEN_H
#define VERALMACEN_H

#include <QDialog>
#include "MonsterStructures/mounstro.h"
#include "DataStructures/listaOrdenada.h"

namespace Ui {
class VerAlmacen;
}

class VerAlmacen : public QDialog
{
    Q_OBJECT

public:
    explicit VerAlmacen(QWidget *parent = nullptr, ListaOrdenada<Mounstro*>* listaAlmacen = nullptr);
    ~VerAlmacen();
    void printAlmacen();

private:
    Ui::VerAlmacen *ui;
    ListaOrdenada<Mounstro*>* listaAlmacen;
};

#endif // VERALMACEN_H

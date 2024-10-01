#include "labelthread.h"

LabelThread::LabelThread() {}

LabelThread::LabelThread(int sleepTime, Cola<Energia*>* colaEnergia, Cola<Maldad*>* colaMaldad, Cola<Materia*>* colaMateria,
                         Cola<Mounstro*>* colaMounstro, ListaOrdenada<Mounstro*>* basurero, Cola<Mounstro*>* primeraBandeja,
                         Cola<Mounstro*>* segundaBandeja, Cola<Mounstro*>* terceraBandeja, Cola<Mounstro*>* cuartaBandeja,
                         Cola<Mounstro*>* colaCalidad, ListaOrdenada<Mounstro*>* listaAlmacen, ListaOrdenada<Mounstro*>* colaEntregados,
                         ListaOrdenada<Mounstro*>* colaAlmacen,  ListaOrdenada<Pedido*>* listaPedidos,  ListaOrdenada<Pedido*>* listaPedidosPrioridad,
                         ListaOrdenada<Pedido*>* listaPedidosEntregados) {
    this->sleepTime = sleepTime;
    this->running = true;
    this->colaEnergia = colaEnergia;
    this->colaMaldad = colaMaldad;
    this->colaMateria = colaMateria;
    this->colaMounstro = colaMounstro;
    this->colaCalidad = colaCalidad;
    this->basurero=basurero;
    this->primeraBandeja = primeraBandeja;
    this->segundaBandeja = segundaBandeja;
    this->terceraBandeja = terceraBandeja;
    this->cuartaBandeja = cuartaBandeja;
    this -> listaAlmacen = listaAlmacen;
    this -> colaEntregados = colaEntregados;
    this -> colaAlmacen = colaAlmacen;
    this -> listaPedidos = listaPedidos;
    this -> listaPedidosPrioridad = listaPedidosPrioridad;
    this -> listaPedidosEntregados = listaPedidosEntregados;
}


void LabelThread::run()
{
    this->running = true;
    while(true) {
        int secondsLeft = this->sleepTime;

        while (secondsLeft > 0) {
            if (!this->running) {
                QThread::sleep(1);
                continue;
            }
            QThread::sleep(1);
            secondsLeft--;
        }
        QString maxItemsEnergy = QString::number(colaEnergia->maxCant);
        QString cantItemsEnergy = QString::number(colaEnergia->getCantItems());
        energyLabel -> setText("Size Cola: " + maxItemsEnergy + " - " + "Cant Items Cola: " + cantItemsEnergy);

        QString maxItemsMaldad = QString::number(colaMaldad->maxCant);
        QString cantItemsMaldad = QString::number(colaMaldad->getCantItems());
        maldadLabel -> setText("Size Cola: " + maxItemsMaldad + " - " + "Cant Items Cola: " + cantItemsMaldad);

        QString maxItemsMateria = QString::number(colaMateria->maxCant);
        QString cantItemsMateria = QString::number(colaMateria->getCantItems());
        materiaLabel -> setText("Size Cola: " + maxItemsMateria + " - " + "Cant Items Cola: " + cantItemsMateria);

        QString maxItemsMounstro = QString::number(colaMounstro->maxCant);
        QString cantItemsMounstro = QString::number(colaMounstro->getCantItems());
        mounstroLabel -> setText("Size Cola: " + maxItemsMounstro + " - " + "Cant Items Cola: " + cantItemsMounstro);

        QString cantItemsBasurero = QString::number(basurero->cantItems);
        basureroLabel -> setText("Cant Items Basurero: " + cantItemsBasurero);


        QString maxItemsHorno1 = QString::number(primeraBandeja->maxCant);
        QString cantItemsHorno1 = QString::number(primeraBandeja->getCantItems());
        horno1Label -> setText("Size Cola: " + maxItemsHorno1 + " - " + "Cant Items Cola: " + cantItemsHorno1);

        QString maxItemsHorno2 = QString::number(segundaBandeja->maxCant);
        QString cantItemsHorno2 = QString::number(segundaBandeja->getCantItems());
        horno2Label -> setText("Size Cola: " + maxItemsHorno2 + " - " + "Cant Items Cola: " + cantItemsHorno2);

        QString maxItemsHorno3 = QString::number(terceraBandeja->maxCant);
        QString cantItemsHorno3 = QString::number(terceraBandeja->getCantItems());
        horno3Label -> setText("Size Cola: " + maxItemsHorno3 + " - " + "Cant Items Cola: " + cantItemsHorno3);

        QString maxItemsHorno4 = QString::number(cuartaBandeja->maxCant);
        QString cantItemsHorno4 = QString::number(cuartaBandeja->getCantItems());
        horno4Label -> setText("Size Cola: " + maxItemsHorno4 + " - " + "Cant Items Cola: " + cantItemsHorno4);


        QString maxItemsCalidad = QString::number(colaCalidad->maxCant);
        QString cantItemsCalidad = QString::number(colaCalidad->getCantItems());
        calidadLabel -> setText("Size Cola: " + maxItemsCalidad + " - " + "Cant Items Cola: " + cantItemsCalidad);

        QString cantItemsAlmacen = QString::number(listaAlmacen->cantItems);
        almacenLabel -> setText("Cant Items Almacen: " + cantItemsAlmacen);

        QString cantItemsAlmacenEntregados = QString::number(colaEntregados->cantItems);
        entregadosLabel -> setText("Cant Items Entregados: " + cantItemsAlmacenEntregados);

        QString cantItemsAlmacenNoEntregados = QString::number(colaAlmacen->cantItems);
        noEntregadosLabel -> setText("Cant Items En Almacen: " + cantItemsAlmacenNoEntregados);

        QString cantItemsEntregaPrioridad = QString::number(listaPedidos->cantItems);
        entregaPrioridadLabel -> setText("Cant Items por Entregar Prioridad: " + cantItemsEntregaPrioridad);

        QString cantItemsEntrega = QString::number(listaPedidosPrioridad->cantItems);
        entregaLabel -> setText("Cant Items por entregar: " + cantItemsEntrega);

        QString cantPedidosEntregados = QString::number(listaPedidosEntregados->cantItems);
        pedidosEntregadosLabel -> setText("Cant Items Entregados: " + cantPedidosEntregados);
        //qDebug() << "Deberia de cambiar los label" << colaEnergia ->cantItems << " " << colaEnergia -> maxCant;
        //qDebug() << materia->type;
    }
}

void LabelThread::setEmergyLabel(QLabel* label){
    this->energyLabel = label;
}

void LabelThread::setMaldadLabel(QLabel* label){
    this->maldadLabel = label;
}

void LabelThread::setMateriaLabel(QLabel* label){
    this->materiaLabel = label;
}

void LabelThread::setMounstroLabel(QLabel* label){
    this->mounstroLabel = label;
}

void LabelThread::setBasureroLabel(QLabel* label){
    this->basureroLabel = label;
}

void LabelThread::setHorno1Label(QLabel* label){
    this->horno1Label = label;
}
void LabelThread::setHorno2Label(QLabel* label){
    this->horno2Label = label;
}
void LabelThread::setHorno3Label(QLabel* label){
    this->horno3Label = label;
}
void LabelThread::setHorno4Label(QLabel* label){
    this->horno4Label = label;
}

void LabelThread::setCalidadLabel(QLabel* label){
    this->calidadLabel = label;
}

void LabelThread::setAlmacenLabel(QLabel* label){
    this->almacenLabel = label;
}

void LabelThread::setEntregadosLabel(QLabel* label){
    this->entregadosLabel = label;
}


void LabelThread::setNoEntregadosLabel(QLabel* label){
    this->noEntregadosLabel = label;
}

void LabelThread::setEntregaPrioridadLabel(QLabel* label){
    this->entregaPrioridadLabel = label;
}

void LabelThread::setEntregaLabel(QLabel* label){
    this->entregaLabel = label;
}

void LabelThread::setPedidosEntregados(QLabel* label){
    this->pedidosEntregadosLabel = label;
}









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
} // Esta funcion se encarga de manejar todos los labels de la pantalla principal, es entonces que recibe el objeto visual, y la informacion que debe de desplegar


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
        energyLabel -> setText("Size Cola: " + maxItemsEnergy + " - " + "Cant Items Cola: " + cantItemsEnergy); // Se coloca el label de energia

        QString maxItemsMaldad = QString::number(colaMaldad->maxCant);
        QString cantItemsMaldad = QString::number(colaMaldad->getCantItems());
        maldadLabel -> setText("Size Cola: " + maxItemsMaldad + " - " + "Cant Items Cola: " + cantItemsMaldad); // Se coloca el label de maldad

        QString maxItemsMateria = QString::number(colaMateria->maxCant);
        QString cantItemsMateria = QString::number(colaMateria->getCantItems());
        materiaLabel -> setText("Size Cola: " + maxItemsMateria + " - " + "Cant Items Cola: " + cantItemsMateria); // Se coloca el label de materia

        QString maxItemsMounstro = QString::number(colaMounstro->maxCant);
        QString cantItemsMounstro = QString::number(colaMounstro->getCantItems());
        mounstroLabel -> setText("Size Cola: " + maxItemsMounstro + " - " + "Cant Items Cola: " + cantItemsMounstro); // Se coloca el label de mousntro

        QString cantItemsBasurero = QString::number(basurero->cantItems);
        basureroLabel -> setText("Cant Items Basurero: " + cantItemsBasurero); // Se coloca el label de basureero


        QString maxItemsHorno1 = QString::number(primeraBandeja->maxCant);
        QString cantItemsHorno1 = QString::number(primeraBandeja->getCantItems());
        horno1Label -> setText("Size Cola: " + maxItemsHorno1 + " - " + "Cant Items Cola: " + cantItemsHorno1); // Se coloca el label del primer horno

        QString maxItemsHorno2 = QString::number(segundaBandeja->maxCant);
        QString cantItemsHorno2 = QString::number(segundaBandeja->getCantItems());
        horno2Label -> setText("Size Cola: " + maxItemsHorno2 + " - " + "Cant Items Cola: " + cantItemsHorno2); // Se coloca el label del segundo horno

        QString maxItemsHorno3 = QString::number(terceraBandeja->maxCant);
        QString cantItemsHorno3 = QString::number(terceraBandeja->getCantItems());
        horno3Label -> setText("Size Cola: " + maxItemsHorno3 + " - " + "Cant Items Cola: " + cantItemsHorno3); // Se coloca el label del tercer horno

        QString maxItemsHorno4 = QString::number(cuartaBandeja->maxCant);
        QString cantItemsHorno4 = QString::number(cuartaBandeja->getCantItems());
        horno4Label -> setText("Size Cola: " + maxItemsHorno4 + " - " + "Cant Items Cola: " + cantItemsHorno4); // Se colcoa el label del cuarto horno


        QString maxItemsCalidad = QString::number(colaCalidad->maxCant);
        QString cantItemsCalidad = QString::number(colaCalidad->getCantItems());
        calidadLabel -> setText("Size Cola: " + maxItemsCalidad + " - " + "Cant Items Cola: " + cantItemsCalidad); // Se coloca el label del quinto horno

        QString cantItemsAlmacen = QString::number(listaAlmacen->cantItems);
        almacenLabel -> setText("Cant Items Almacen: " + cantItemsAlmacen); // Se coloca el label del sexto horno

        QString cantItemsAlmacenEntregados = QString::number(colaEntregados->cantItems);
        entregadosLabel -> setText("Cant Items Entregados: " + cantItemsAlmacenEntregados); // Se coloca el laabel entregado

        QString cantItemsAlmacenNoEntregados = QString::number(colaAlmacen->cantItems);
        noEntregadosLabel -> setText("Cant Items En Almacen: " + cantItemsAlmacenNoEntregados); // Se coloca el label de lo que no esta entregado

        QString cantItemsEntregaPrioridad = QString::number(listaPedidos->cantItems);
        entregaPrioridadLabel -> setText("Cant Items por Entregar Prioridad: " + cantItemsEntregaPrioridad); // Se coloca el label de quienes se tienen que entregar en prioridad

        QString cantItemsEntrega = QString::number(listaPedidosPrioridad->cantItems);
        entregaLabel -> setText("Cant Items por entregar: " + cantItemsEntrega); // Se coloca el label de quienes se tienen que entregar en no prioridad

        QString cantPedidosEntregados = QString::number(listaPedidosEntregados->cantItems);
        pedidosEntregadosLabel -> setText("Cant Items Entregados: " + cantPedidosEntregados);
    }
}

// Las siguientes funciones son para pasar aqui los labels y que se puedan modificar desde esta funcion
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










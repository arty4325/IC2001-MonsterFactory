#ifndef LABELTHREAD_H
#define LABELTHREAD_H
#include <QtCore>
#include <QDebug>
#include <QRandomGenerator>
#include <QString>
#include <QLabel>
#include "MonsterStructures/energia.h"
#include "MonsterStructures/maldad.h"
#include "MonsterStructures/materia.h"
#include "MonsterStructures/mounstro.h"
#include "DataStructures/cola.h"
#include "DataStructures/listaOrdenada.h"


class LabelThread: public QThread
{
public:
    LabelThread();
    LabelThread(int sleepTime, Cola<Energia*>* colaEnergia, Cola<Maldad*>* colaMaldad, Cola<Materia*>* colaMateria, Cola<Mounstro*>* colaMounstro,
                ListaOrdenada<Mounstro*>* basurero, Cola<Mounstro*>* primeraBandeja, Cola<Mounstro*>* segundaBandeja, Cola<Mounstro*>* terceraBandeja,
                Cola<Mounstro*>* cuartaBandeja, Cola<Mounstro*>* colaCalidad, ListaOrdenada<Mounstro*>* listaAlmacen, ListaOrdenada<Mounstro*>* colaEntregados, ListaOrdenada<Mounstro*>* colaAlmacen);
    void run();
    void setEmergyLabel(QLabel* label);
    void setMaldadLabel(QLabel* label);
    void setMateriaLabel(QLabel* label);
    void setMounstroLabel(QLabel* label);
    void setBasureroLabel(QLabel* label);
    void setHorno1Label(QLabel* label);
    void setHorno2Label(QLabel* label);
    void setHorno3Label(QLabel* label);
    void setHorno4Label(QLabel* label);
    void setCalidadLabel(QLabel* label);
    void setAlmacenLabel(QLabel* label);
    void setEntregadosLabel(QLabel* label);
    void setNoEntregadosLabel(QLabel* label);
private:
    bool running;
    int sleepTime;
    Cola<Energia*>* colaEnergia;
    Cola<Maldad*>* colaMaldad;
    Cola<Materia*>* colaMateria;
    Cola<Mounstro*>* colaMounstro;
    Cola<Mounstro*>* colaCalidad;
    ListaOrdenada<Mounstro*>* basurero;
    Cola<Mounstro*>* primeraBandeja;
    Cola<Mounstro*>* segundaBandeja;
    Cola<Mounstro*>* terceraBandeja;
    Cola<Mounstro*>* cuartaBandeja;
    ListaOrdenada<Mounstro*>* listaAlmacen;
    ListaOrdenada<Mounstro*>* colaEntregados;
    ListaOrdenada<Mounstro*>* colaAlmacen;
    QLabel* energyLabel;
    QLabel* maldadLabel;
    QLabel* materiaLabel;
    QLabel* mounstroLabel;
    QLabel* basureroLabel;
    QLabel* horno1Label;
    QLabel* horno2Label;
    QLabel* horno3Label;
    QLabel* horno4Label;
    QLabel* calidadLabel;
    QLabel* almacenLabel;
    QLabel* entregadosLabel;
    QLabel* noEntregadosLabel;
};

#endif // LABELTHREAD_H

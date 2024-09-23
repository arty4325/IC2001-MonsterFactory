#ifndef CALIDAD_H
#define CALIDAD_H
#include <QtCore>
#include <QDebug>
#include <QRandomGenerator>
#include <QString>
#include <QLabel>
#include "../DataStructures/cola.h"
#include "../MonsterStructures/mounstro.h"
#include "../DataStructures/listaOrdenada.h"
#include "almacen.h"

class Calidad : public QThread
{
public:
    Calidad();
    Calidad(int sleepTime, Cola<Mounstro*>* colaCalidad, ListaOrdenada<Mounstro*>* basurero, Almacen* almacen);
    void stop(int val);
    void changeSecondProbability(int val);
    void changeFirstProbability(int val);
    void run();
private:
    bool running;
    int sleepTime;
    int probsPrimerInspector;
    int probsSegundoInspector;
    Cola<Mounstro*>* colaCalidad;
    ListaOrdenada<Mounstro*>* basurero;
    Almacen* almacen;
};

#endif // CALIDAD_H

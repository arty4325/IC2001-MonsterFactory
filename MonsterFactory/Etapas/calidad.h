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

class Calidad : public QThread
{
public:
    Calidad();
    Calidad(int sleepTime, Cola<Mounstro*>* colaCalidad, ListaOrdenada<Mounstro*>* basurero);
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
};

#endif // CALIDAD_H

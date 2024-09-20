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
    LabelThread(int sleepTime, Cola<Energia*>* colaEnergia, Cola<Maldad*>* colaMaldad, Cola<Materia*>* colaMateria, Cola<Mounstro*>* colaMounstro, ListaOrdenada<Mounstro*>* basurero);
    void run();
    void setEmergyLabel(QLabel* label);
    void setMaldadLabel(QLabel* label);
    void setMateriaLabel(QLabel* label);
    void setMounstroLabel(QLabel* label);
    void setBasureroLabel(QLabel* label);
private:
    bool running;
    int sleepTime;
    Cola<Energia*>* colaEnergia;
    Cola<Maldad*>* colaMaldad;
    Cola<Materia*>* colaMateria;
    Cola<Mounstro*>* colaMounstro;
    ListaOrdenada<Mounstro*>* basurero;
    QLabel* energyLabel;
    QLabel* maldadLabel;
    QLabel* materiaLabel;
    QLabel* mounstroLabel;
    QLabel* basureroLabel;
};

#endif // LABELTHREAD_H

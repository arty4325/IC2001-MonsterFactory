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


class LabelThread: public QThread
{
public:
    LabelThread();
    LabelThread(int sleepTime, Cola<Energia*>* colaEnergia, Cola<Maldad*>* colaMaldad, Cola<Materia*>* colaMateria, Cola<Mounstro*>* colaMounstro);
    void run();
    void setEmergyLabel(QLabel* label);
    void setMaldadLabel(QLabel* label);
    void setMateriaLabel(QLabel* label);
    void setMounstroLabel(QLabel* label);
private:
    bool running;
    int sleepTime;
    Cola<Energia*>* colaEnergia;
    Cola<Maldad*>* colaMaldad;
    Cola<Materia*>* colaMateria;
    Cola<Mounstro*>* colaMounstro;
    QLabel* energyLabel;
    QLabel* maldadLabel;
    QLabel* materiaLabel;
    QLabel* mounstroLabel;
};

#endif // LABELTHREAD_H

#ifndef MATERIATHREAD_H
#define MATERIATHREAD_H
#include <QtCore>
#include <QDebug>
#include <QRandomGenerator>
#include <QString>
#include <QLabel>
#include "materia.h"
#include "../DataStructures/cola.h"

class MateriaThread : public QThread
{
public:
    MateriaThread();
    MateriaThread(int sleepTime, Cola<Materia*>* cola);

    void run();
private:
    bool running;
    int sleepTime;
    Cola<Materia*>* cola;
};

#endif // MATERIATHREAD_H

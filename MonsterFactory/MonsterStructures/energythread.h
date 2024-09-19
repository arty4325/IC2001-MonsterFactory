#ifndef ENERGYTHREAD_H
#define ENERGYTHREAD_H
#include <QtCore>
#include <QDebug>
#include <QRandomGenerator>
#include <QString>
#include <QLabel>
#include "energia.h"
#include "../DataStructures/cola.h"

class EnergyThread : public QThread
{
public:
    EnergyThread();
    EnergyThread(int sleepTime, Cola<Energia*>* cola);
    void changeTime(int time);
    void stop(int val);
    void setLabel(QLabel* label);

    void run();
private:
    bool running;
    int sleepTime;
    Cola<Energia*>* cola;
    QLabel* queueLabel;
};

#endif // ENERGYTHREAD_H

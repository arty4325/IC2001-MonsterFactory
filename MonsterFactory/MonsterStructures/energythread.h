#ifndef ENERGYTHREAD_H
#define ENERGYTHREAD_H
#include <QtCore>
#include <QDebug>
#include <QRandomGenerator>
#include <QString>
#include <QLabel>


class EnergyThread : public QThread
{
public:
    EnergyThread();
    EnergyThread(int sleepTime);

    void run();
private:
    bool running;
    int sleepTime;
};

#endif // ENERGYTHREAD_H

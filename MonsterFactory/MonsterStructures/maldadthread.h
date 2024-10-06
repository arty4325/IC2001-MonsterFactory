#ifndef MALDADTHREAD_H
#define MALDADTHREAD_H

#include <QtCore>
#include <QDebug>
#include <QRandomGenerator>
#include <QString>
#include <QLabel>
#include "maldad.h"
#include "../DataStructures/cola.h"


class MaldadThread : public QThread
{
public:
    MaldadThread();
    MaldadThread(int sleepTime, Cola<Maldad*>* cola);
    void changeTime(int time);
    void stop(int val);

    void run();
private:
    bool running;
    int sleepTime;
    Cola<Maldad*>* cola;
};

#endif // MALDADTHREAD_H

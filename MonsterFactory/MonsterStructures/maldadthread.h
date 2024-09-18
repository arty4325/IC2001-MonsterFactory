#ifndef MALDADTHREAD_H
#define MALDADTHREAD_H

#include <QtCore>
#include <QDebug>
#include <QRandomGenerator>
#include <QString>
#include <QLabel>


class MaldadThread : public QThread
{
public:
    MaldadThread();
    MaldadThread(int sleepTime);

    void run();
private:
    bool running;
    int sleepTime;
};

#endif // MALDADTHREAD_H

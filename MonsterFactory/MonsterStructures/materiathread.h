#ifndef MATERIATHREAD_H
#define MATERIATHREAD_H
#include <QtCore>
#include <QDebug>
#include <QRandomGenerator>
#include <QString>
#include <QLabel>


class MateriaThread : public QThread
{
public:
    MateriaThread();
    MateriaThread(int sleepTime);

    void run();
private:
    bool running;
    int sleepTime;
};

#endif // MATERIATHREAD_H

#ifndef HORNO_H
#define HORNO_H

#include <QtCore>
#include <QDebug>
#include <QRandomGenerator>
#include <QString>
#include <QLabel>

class Horno : public QThread
{
public:
    Horno();
    Horno(int sleepTime);
    void changeTime(int time);
    void run();
private:
    bool running;
    int sleepTime;
};
#endif // HORNO_H

#ifndef CALIDAD_H
#define CALIDAD_H
#include <QtCore>
#include <QDebug>
#include <QRandomGenerator>
#include <QString>
#include <QLabel>


class Calidad : public QThread
{
public:
    Calidad();
    Calidad(int sleepTime);
    void stop(int val);
    void changeSecondProbability(int val);
    void changeFirstProbability(int val);
    void run();
private:
    bool running;
    int sleepTime;
    int probsPrimerInspector;
    int probsSegundoInspector;
};

#endif // CALIDAD_H

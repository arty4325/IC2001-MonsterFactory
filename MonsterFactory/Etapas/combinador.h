#ifndef COMBINADOR_H
#define COMBINADOR_H
#include <QtCore>
#include <QDebug>
#include <QRandomGenerator>
#include <QString>
#include <QLabel>
#include "../MonsterStructures/mounstro.h"
#include "../MonsterStructures/energia.h"
#include "../MonsterStructures/maldad.h"
#include "../MonsterStructures/materia.h"
#include "../DataStructures/cola.h"


class Combinador : public QThread
{
public:
    Combinador();
    Combinador(int sleepTime,Cola<Mounstro*>* colaMounstros ,Cola<Energia*>* colaEnergia, Cola<Maldad*>* colaMaldad ,Cola<Materia*>* colaMateria);
    void changeTime(int time);
    void stop(int val);

    void run();
private:
    bool running;
    int sleepTime;
    Cola<Mounstro*>* colaMounstros;
    Cola<Energia*>* colaEnergia;
    Cola<Maldad*>* colaMaldad;
    Cola<Materia*>* colaMateria;
};
#endif // COMBINADOR_H

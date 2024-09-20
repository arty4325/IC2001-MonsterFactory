#ifndef HORNO_H
#define HORNO_H

#include <QtCore>
#include <QDebug>
#include <QRandomGenerator>
#include <QString>
#include <QLabel>
#include "../DataStructures/cola.h"
#include "../MonsterStructures/mounstro.h"

class Horno : public QThread
{
public:
    Horno();
    Horno(int sleepTime,Cola<Mounstro*>* colaMounstro ,Cola<Mounstro*>* primeraBandeja, Cola<Mounstro*>* segundaBandeja, Cola<Mounstro*>* terceraBandeja, Cola<Mounstro*>* cuartaBandeja );
    void changeTime(int time);
    void changeMaxPrimeraBandeja(int time);
    void changeMaxSegundaBandeja(int time);
    void changeMaxTerceraBandeja(int time);
    void changeMaxCuartaBandeja(int time);
    void run();
private:
    bool running;
    int sleepTime;
    Cola<Mounstro*>* primeraBandeja;
    Cola<Mounstro*>* segundaBandeja;
    Cola<Mounstro*>* terceraBandeja;
    Cola<Mounstro*>* cuartaBandeja;
    Cola<Mounstro*>* colaMounstro;
};
#endif // HORNO_H

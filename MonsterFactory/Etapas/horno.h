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
    Horno(int sleepTime,Cola<Mounstro*>* colaMounstro ,Cola<Mounstro*>* primeraBandeja, Cola<Mounstro*>* segundaBandeja, Cola<Mounstro*>* terceraBandeja, Cola<Mounstro*>* cuartaBandeja, Cola<Mounstro*>* colaCalidad );
    void changeTime(int time);
    void changeMaxPrimeraBandeja(int time);
    void changeMaxSegundaBandeja(int time);
    void changeMaxTerceraBandeja(int time);
    void changeMaxCuartaBandeja(int time);
    void changeFirstBlocked(int val);
    void changeSecondBlocked(int val);
    void changeThirdBlocked(int val);
    void changeFourthBlocked(int val);
    void stop(int val);
    void run();
private:
    bool running;
    int sleepTime;
    Cola<Mounstro*>* primeraBandeja;
    Cola<Mounstro*>* segundaBandeja;
    Cola<Mounstro*>* terceraBandeja;
    Cola<Mounstro*>* cuartaBandeja;
    Cola<Mounstro*>* colaMounstro;
    Cola<Mounstro*>* colaCalidad;
    bool isFirstBlocked;
    bool isSecondBlocked;
    bool isThirdBlocked;
    bool isFourthBlocked;
};
#endif // HORNO_H

#include "energythread.h"
#include "energia.h"
#include "../DataStructures/cola.h"

EnergyThread::EnergyThread() {}

EnergyThread::EnergyThread(int sleepTime, Cola<Energia*>* cola) {
    this->sleepTime = sleepTime;
    this->cola = cola;
    this->running = true;
}

void EnergyThread::run()
{
    this->running = true;
    while(true) {
        int secondsLeft = this->sleepTime;
        while (secondsLeft > 0) {
            if (!this->running) {
                QThread::sleep(1);
                continue;
            }
            QThread::sleep(1);
            secondsLeft--;
        }

        Energia* energia = new Energia();
        cola->push(energia);
        qDebug() << energia->type;
    }
}


void EnergyThread::changeTime(int time){
    this-> sleepTime = time;
}

void EnergyThread::stop(int val){
    if(val == 2){
        qDebug() << "Tengo que parar esta vara";
        this->running = false;
    } else {
        qDebug() << "La tengo que reanudar";
        this->running = true;
    }
}





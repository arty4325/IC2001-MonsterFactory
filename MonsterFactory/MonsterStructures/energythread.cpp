#include "energythread.h"
#include "energia.h"
#include "../DataStructures/cola.h"

EnergyThread::EnergyThread() {}

EnergyThread::EnergyThread(int sleepTime, Cola<Energia*>* cola) {
    this->sleepTime = sleepTime;
    this->cola = cola;
    this->running = true;
}

void EnergyThread::run() // Este es un hilo que va creando energia
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

        Energia* energia = new Energia(); // Instancia una energia
        cola->push(energia); // Y la guarda dentro de una cola energia
    }
}



void EnergyThread::changeTime(int time){ // Esto puede cambiar la velocidad a la que se van a estar creando estos items
    this-> sleepTime = time;
}

void EnergyThread::stop(int val){ // Funcion permite parar momentaneamente el hilo
    if(val == 2){
        this->running = false;
    } else {
        this->running = true;
    }
}





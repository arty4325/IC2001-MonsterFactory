#include "calidad.h"

Calidad::Calidad() {}

Calidad::Calidad(int sleepTime) {
    this->sleepTime = sleepTime;
    this->running = true;
    //this->queueLabel;
}

void Calidad::run()
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
            qDebug() << "Debo de ver calidad";
        }

    }
}

void Calidad::stop(int val){
    if(val == 2){
        qDebug() << "Tengo que parar esta vara";
        this->running = false;
    } else {
        qDebug() << "La tengo que reanudar";
        this->running = true;
    }
}

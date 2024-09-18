#include "energythread.h"
#include "energia.h"

EnergyThread::EnergyThread() {}

EnergyThread::EnergyThread(int sleepTime) {
    this->sleepTime = sleepTime;
    this->running = true;
}

void EnergyThread::run()
{
    this -> running = true;
    while(true){
        int secondsLeft = this->sleepTime;
        while(secondsLeft > 0){
            if(!this->running)
            {
                QThread::sleep(1);
                continue;
            }
            QThread::sleep(1);
            Energia* energia = new Energia();
            qDebug() << energia -> type;
        }
    }
}




